module;

#include <iostream>

import Utils;
import UJImage;
import InversionFilter;

export module FullInversionFilter;

export class FullInversionFilter : public InversionFilter{
	
	public:
		
		explicit FullInversionFilter(int thresh){
			
			_invThreshold = thresh;
		};
		
		void invertImage(UJImage& image) override;
	
	private:
	
		int _invThreshold;
};

void FullInversionFilter::invertImage(UJImage& image){
	
	for(int r = 0; r < image.getRows(); r++){
		
		for(int c = 0; c < image.getCols(); c++){
			
			//Temp colour
			RGBColour px;
			
			//Save the pixel to check after
			px = image.getPixel(r,c);
			
			//Check above thresh and change
			if(px.intRed > _invThreshold){
				
				px.intRed = 255 - px.intRed;
			}
			if(px.intGreen > _invThreshold){
				
				px.intGreen = 255 - px.intGreen;
			}
			if(px.intBlue > _invThreshold){
				
				px.intBlue = 255 - px.intBlue;
			}
			
			image.setPixel(r,c, px);
		};
	};
};