#pragma once
#include "CommonFunction.h"
#include "BaseObject.h"
class Character: public BaseObject
{
public:
	static const int Width = 57;
	static const int Height = 90;
	//Initializes variables
	Character();

	//Deallocates memory
	//~Character();

	//Loads image at specified path
	
	//Deallocates texture
	//void free();
	
	//Renders texture at given point
	//void RenderCharacter(SDL_Renderer* renderer, BaseObject& anh);

	void HandleInputAction(SDL_Event &events);

	void HandleMove();
	//Gets image dimensions
	SDL_Rect getRect();

	void RenderCharacter(SDL_Renderer* renderer, BaseObject& character);
		
private:
	
	
	int x_val ;
	SDL_Rect rect;
};

