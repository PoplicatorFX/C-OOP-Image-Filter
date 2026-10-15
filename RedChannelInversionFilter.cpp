module;

#include <iostream>

import Utils;
import UJImage;
import InversionFilter;

export module RedChannelInversionFilter;

export class RedChannelInversionFilter : public InversionFilter{
	
	public:
		
		explicit RedChannelInversionFilter(int thresh){
			
			_invThreshold = thresh;
		};
		
		void invertImage(UJImage& image) override;
	
	private:
	
		int _invThreshold;
};

void RedChannelInversionFilter::invertImage(UJImage& image){
	
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
			
			image.setPixel(r,c, px);
		};
	};
};