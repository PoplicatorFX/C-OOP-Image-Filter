module;

#include<iostream>

import Utils;

export module UJImage;

//My aliases
using oneDimension = RGBColour*;
using twoDimension = RGBColour**;

//My class
export class UJImage{
	
	public:
		
		//My default constructor
		UJImage();
		
		//My parameterised constructor
		UJImage(std::string magicNum, int rows, int cols, int intensity);
		
		//My copy constructor
		UJImage(const UJImage& original);
		
		//My destructor
		~UJImage();
		
		//My constant
		RGBColour DEF_COLOUR = {255,255,255};
		
		//My getters
		int getRows() const;
		int getCols() const;
		RGBColour getPixel(int row, int col) const;
		
		//My setters
		void setPixel(int row, int col, RGBColour colour);
		
		//My overloaded operators
		friend std::ostream& operator<<(std::ostream& COUT, const UJImage& objRhs);
		UJImage& operator=(const UJImage& objRhs);
		bool operator==(const UJImage& objRhs) const;
		UJImage& operator!();
	
	private:
		
		//My private attributes
		std::string _magicNumber;
		int _intRows;
		int _intCols;
		int _intensity;
		twoDimension _myImage;
		
		//My private functions
		void allocMemory();
		void deallocMemory();
};

//My private functions
void UJImage::allocMemory(){
	
	_myImage = new oneDimension[_intRows];
	
	for(int r = 0; r < _intRows; r++){
		
		_myImage[r] = new RGBColour[_intCols];
		for(int c = 0; c < _intCols; c++){
			
			_myImage[r][c] = DEF_COLOUR;
		};
	};
};

void UJImage::deallocMemory(){
	
	if(_myImage != nullptr){
		
		for(int r = 0; r < _intRows; r++){
			
			delete[] _myImage[r];
		}
		delete[] _myImage;
		_myImage = nullptr;
	};
};

//My default constructor
UJImage::UJImage(){
	
	//My default values
	_magicNumber = "P3";
	_intRows = 0;
	_intCols = 0;
	_intensity = 255;
	_myImage = nullptr;
};
		
//My parameterised constructor
UJImage::UJImage(std::string magicNum, int rows, int cols, int intensity){
	
	//Enforce range
	
	//Initialising my variables
	_magicNumber = magicNum;
	_intRows = rows;
	_intCols = cols;
	_intensity = intensity;
	
	//Allocating memory
	allocMemory();
};
		
//My copy constructor
UJImage::UJImage(const UJImage& original){
	
	//Copying the variables
	_magicNumber = original._magicNumber;
	_intRows = original._intRows;
	_intCols = original._intCols;
	_intensity = original._intensity;
	_myImage = nullptr;
	
	//Allocating memory using new values
	_myImage = new oneDimension[_intRows];
	
	//Deep copying
	for(int r = 0; r < _intRows; r++){
		
		_myImage[r] = new RGBColour[_intCols];
		for(int c = 0; c < _intCols; c++){
			
			_myImage[r][c] = original._myImage[r][c];
		};
	};
};
		
//My destructor
UJImage::~UJImage(){
	
	deallocMemory();
};
		
//My getters
int UJImage::getRows() const{
	
	return _intRows;
};

int UJImage::getCols() const{
	
	return _intCols;
};

RGBColour UJImage::getPixel(int row, int col) const{
	
	//Enforce range
	
	
	return _myImage[row][col];
	
};
		
//My setters
void UJImage::setPixel(int row, int col, RGBColour colour){
	
	//Enforce range
	
	//Enforce colour
	
	_myImage[row][col] = colour;
};
		
//My overloaded operators
std::ostream& operator<<(std::ostream& COUT, const UJImage& objRhs){
	
	//Printing the variables
	COUT << objRhs._magicNumber << std::endl;
	COUT << objRhs._intCols << " " << objRhs._intRows << std::endl;
	COUT << objRhs._intensity << std::endl;
	
	//Printing the pixels
	for(int r = 0; r < objRhs._intRows; r++){
	
		for(int c = 0; c < objRhs._intCols; c++){
			
			COUT << objRhs._myImage[r][c].intRed << " "
				<< objRhs._myImage[r][c].intGreen << " "
				<< objRhs._myImage[r][c].intBlue << " ";
		};
		COUT << std::endl;
	};
	return COUT;
};

UJImage& UJImage::operator=(const UJImage& objRhs){
	
	//Prevent self assignmentt
	if(this == &objRhs){
		
		return *this;
	};
	
	//Deallocate memory
	deallocMemory();
	
	//Assign variables
	_magicNumber = objRhs._magicNumber;
	_intRows = objRhs._intRows;
	_intCols = objRhs._intCols;
	_intensity = objRhs._intensity;
	
	//Deep assignment
	_myImage = new oneDimension[_intRows];
	
	//Deep copying
	for(int r = 0; r < _intRows; r++){
		
		_myImage[r] = new RGBColour[_intCols];
		for(int c = 0; c < _intCols; c++){
			
			_myImage[r][c] = objRhs._myImage[r][c];
		};
	};
	return *this;
};

bool UJImage::operator==(const UJImage& objRhs) const{
	
	//Check variables
	if(_magicNumber != objRhs._magicNumber ||
		_intRows != objRhs._intRows ||
		_intCols != objRhs._intCols ||
		_intensity != objRhs._intensity){
		
		return false;
	};
	
	//Check pixels
	for(int r = 0; r < _intRows; r++){
		
		for(int c = 0; c < _intCols; c++){
			
			if(_myImage[r][c].intRed != objRhs._myImage[r][c].intRed ||
			   _myImage[r][c].intGreen != objRhs._myImage[r][c].intGreen ||
			   _myImage[r][c].intBlue != objRhs._myImage[r][c].intBlue){
	
				return false;
			};
		};
	};
	return true;
};

UJImage& UJImage::operator!(){
	
	RGBColour newColour = {255,255,255};
	
	for(int r = 0; r < _intRows; r++){
		
		for(int c = 0; c < _intCols; c++){
			
			_myImage[r][c] = newColour;
		};
	};
	
	return *this;
};