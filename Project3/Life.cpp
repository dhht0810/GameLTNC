#include "Life.h"

Life::Life() {
	number = 0;
}
void Life::SetNum(const int& num) {
	number = num;
}
void Life::AddPos(const int& x_pos) {
	Life_Pos.push_back(x_pos);
}

void Life::CreateLife(SDL_Renderer* renderer, BaseObject& life) {
	for (int i = 0; i < Life_Pos.size(); i++) {
		rect.x = Life_Pos.at(i);
		rect.y =50;
		life.ApplySurface(renderer, rect.x, rect.y);
	}
}

void Life::Init(SDL_Renderer* renderer, BaseObject& life) {
	life.LoadImage(renderer, "Heart.png");
	number = 3;
	if (Life_Pos.size() > 0) {
		Life_Pos.clear();
	}
	AddPos(60);
	AddPos(110);
	AddPos(160);
}

void Life::Decrease() {
	number--;
	Life_Pos.pop_back();
}