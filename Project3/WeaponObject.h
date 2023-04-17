#pragma once
#include "CommonFunction.h"
#include "BaseObject.h"
class WeaponObject: public BaseObject
{
public:
	static const int Width = 50;
	static const int Height = 50;
	//Initializes variables
	WeaponObject(int x);

	//Deallocates memory
	//~WeaponObject();

	//Loads image at specified path
	//Deallocates texture
	//void free();

	
	//Renders texture at given point
	void CreateWeapon(SDL_Renderer* renderer, WeaponObject &anh);

	
	//Gets image dimensions
	SDL_Rect getRect();

private:
	//The actual hardware texture
	//Image dimensions
	SDL_Rect rect;
	
};

