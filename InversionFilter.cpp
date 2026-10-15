module;

#include <iostream>

import Utils;
import UJImage;

export module InversionFilter;

//My abstract class
export class InversionFilter{
	
	public:
		
		virtual void invertImage(UJImage& image) = 0;
		
		virtual ~InversionFilter() = default;
};
