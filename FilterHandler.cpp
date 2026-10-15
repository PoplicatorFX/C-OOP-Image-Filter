module;

#include <iostream>

import Utils;
import UJImage;
import InversionFilter;
import FullInversionFilter;
import RedChannelInversionFilter;

export module FilterHandler;

export class FilterHandler{
	
	public:
		
		//My constructor
		FilterHandler();
		
		//My delegated function
		void applyFilter(UJImage& image);
		
		//My destructor
		~FilterHandler();
	
	private:
	
		InversionFilter* pInversionFilter;
};

//My constructor
FilterHandler::FilterHandler(){
	
	pInversionFilter = new RedChannelInversionFilter(128);
};
		
//My delegated function
void FilterHandler::applyFilter(UJImage& image){
		
	pInversionFilter->invertImage(image);
};
		
//My destructor
FilterHandler::~FilterHandler(){

	if(pInversionFilter!=nullptr){
		
		delete[] pInversionFilter;
		pInversionFilter = nullptr;
	};
};