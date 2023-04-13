#include "WeaponObject.h"
WeaponObject::WeaponObject(int x) {
	rect = { x,0,Width,Height };
}
void WeaponObject::CreateWeapon(SDL_Renderer* renderer, BaseObject& anh) {
	anh.ApplySurface(renderer, rect.x, rect.y);
	rect.y += 5;
}
SDL_Rect WeaponObject::getRect() {
	return rect;
}

