#pragma once
#include "CommonFunction.h"
#include "BaseObject.h"
class WeaponObject: public BaseObject
{
public:
	static const int Width = 50;
	static const int Height =44 ;
	//Initializes variables
	WeaponObject(int x);

	//Deallocates memory
	//~WeaponObject();

	//Loads image at specified path
	//Deallocates texture
	//void free();
	;
	//Renders texture at given point
	void CreateWeapon(SDL_Renderer* renderer, WeaponObject &anh,int val);

	
	//Gets image dimensions
	SDL_Rect getRect();

	

private:
	//The actual hardware texture
	//Image dimensions
	SDL_Rect rect;
	int weapon_val;
	
	//Moves the collision boxes relative to the dot's offset
	
};

