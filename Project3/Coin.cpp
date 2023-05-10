#include "Coin.h"
Coin::Coin() {
		rect = { 0,SCREEN_HEIGHT-100,Width,Height };
}

void Coin::CreateCoin(SDL_Renderer* renderer, BaseObject& coin) {
	coin.ApplySurface(renderer, rect.x, rect.y);
	
	}


SDL_Rect Coin::getRect() {
	return rect;
}

void Coin::SetPos() {
	int x=rand() % 1200 + 1;
	rect.x = x;
	if ((rect.x < 0) || (rect.x + Width > SCREEN_WIDTH))
	{
		//Move back
		rect.x -= 100;
	}
}

void Coin::SetInitialPos(int &x) {
	rect.x = x;
	
}