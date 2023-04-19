//#ifndef BaseObject_H_
//#define BaseObject_H_
#pragma once
#include "CommonFunction.h"
class BaseObject
{
public:
	//Initializes variables
	BaseObject();

	//Deallocates memory
	~BaseObject();

	//Loads image at specified path
	bool LoadImage(SDL_Renderer* renderer,std::string path);

	bool LoadTtf(SDL_Renderer* renderer, std::string path,TTF_Font* font,SDL_Color color);
	//Deallocates texture
	void free();

	//Renders texture at given point
	void ApplySurface(SDL_Renderer* renderer,int x, int y,SDL_Rect* clip = NULL);

	

	
	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* g_bkground;

	//Image dimensions
	int mWidth;
	int mHeight;
	
};
//#endif