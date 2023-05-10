#pragma once

#include "CommonFunction.h"
#include "BaseObject.h"
class Life: public BaseObject
{
public:
	Life();
	

	void SetNum(const int& num);
	void AddPos(const int& x_pos);
	void CreateLife(SDL_Renderer* renderer, BaseObject& life);
	void Increase();
	void Decrease();
	void Init(SDL_Renderer* renderer, BaseObject& life);
private:
	int number;
	vector <int> Life_Pos;
	SDL_Rect rect;
};

