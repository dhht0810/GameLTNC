//#ifndef Bkground_H_
//#define Bkground_H_
#pragma once
#include "CommonFunction.h"
class Bkground
{
public:
	//Initializes variables
	Bkground();

	//Deallocates memory
	~Bkground();

	//Loads image at specified path
	bool LoadImage(SDL_Renderer* renderer,std::string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void ApplySurface(SDL_Renderer* renderer,int x, int y);

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