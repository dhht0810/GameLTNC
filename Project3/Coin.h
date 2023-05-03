#pragma once
#include "CommonFunction.h"
#include "BaseObject.h"
class Coin: public BaseObject
{
public:
	static const int Width = 35;
	static const int Height = 35;
	Coin();
	void CreateCoin(SDL_Renderer* renderer, BaseObject& coin);
	SDL_Rect getRect();
	void SetPos();
	void SetInitialPos(int &x);
private:
	SDL_Rect rect;
};

