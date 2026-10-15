module;

#include<iostream>

export module Utils;

//My struct with allignment padding disabled
#pragma pack(push,1)
export struct RGBColour{
	
	int intRed;
	int intGreen;
	int intBlue;
};
#pragma pack(pop)

