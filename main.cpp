#include <iostream>
#include <fstream>

import Utils;
import UJImage;
import InversionFilter;
import FullInversionFilter;
import RedChannelInversionFilter;
import FilterHandler;

using namespace std;

//Read Text File and create UJImage Object
UJImage readTXTFile(string strFileName);
//Write Binary File from UJImage Object
void writeBINFile(string strFileName, const UJImage& objImage);

int main(){
	string strTXTFileName = "data/UJ_20_large.txt";
	string strBINFileName = "data/UJ_20_large.dat";
	
	UJImage objImage = readTXTFile(strTXTFileName); //Invokes copy constructor
	
	
	FilterHandler objFilterHandler;
	
	//Delegation and Polymorphic call on transform function
	objFilterHandler.applyFilter(objImage);
	// Write to Binary File
	writeBINFile(strBINFileName, objImage);	
	
	//Test Overloaded Operators
    UJImage objCopy = objImage;
	if(objCopy == objImage){
		//cout << "Similar Images" << endl; Works fine
		!objCopy; // Logical NOT
	}
	
    cout << objImage << endl;	// Output transformed Image
	return 0;
}

//Read Text File and create UJImage Object
UJImage readTXTFile(string strFileName){
	
	//Open read connection
	std::ifstream in_stream(strFileName);
	
	//Check connection
	if(!in_stream)
		throw std::runtime_error("Could not open text file");
	
	//Create variables to read onto
	std::string magicNumber;
	int intRows;
	int intCols;
	int intensity;
	
	//Reading tto variables
	in_stream >> magicNumber >> intCols >> intRows >> intensity;
	
	//Creating an object
	UJImage tempImage(magicNumber, intRows, intCols, intensity);
	
	//Read colours
	for(int r = 0; r < intRows; r++){
		
		for(int c = 0; c < intCols; c++){
			
			//Temp storage
			RGBColour px;
			
			in_stream >> px.intRed >> px.intGreen >> px.intBlue;
			
			tempImage.setPixel(r,c,px);
		};
	};
	//Close connection
	in_stream.close();
	return tempImage;
}

//Write Binary File from UJImage Object - WITH THE CORRECT Flags
void writeBINFile(string strFileName, const UJImage& objImage){
	
	//Open write connection
	std::ofstream out_stream(strFileName, ios::binary);
	
	//Check connection
	if(!out_stream)
		throw std::runtime_error("Could not open text file");
	
	for(int r = 0; r < objImage.getRows(); r++){
		
		for(int c = 0; c < objImage.getCols(); c++){
			
			//Temp storage
			RGBColour px;
			
			//Saving
			px = objImage.getPixel(r,c);
			
			//Writing
			out_stream.write(reinterpret_cast<const char*>(&px), sizeof(RGBColour));
		};
	};
	out_stream.close();
}