#pragma once
#include "CommonFunction.h"
#include "BaseObject.h"
class Character: public BaseObject
{
public:
	static const int Width = 54;
	static const int Height =79;
	//Initializes variables
	Character();

	

	
	void SetVal(int x);
	
	
	//Renders texture at given point
	

	void HandleInputAction(SDL_Event &events);

	void HandleMove();
	//Gets image dimensions
	SDL_Rect getRect();



	void RenderCharacter(SDL_Renderer* renderer, BaseObject& character);
		
private:

	
	//Moves the collision boxes relative to the dot's offset
	
	
	int x_val ;
	SDL_Rect rect;
};

