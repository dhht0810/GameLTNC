#include "WeaponObject.h"
WeaponObject::WeaponObject(int x) {
	rect = { x,0,Width,Height};
	
}




void WeaponObject::CreateWeapon(SDL_Renderer* renderer, WeaponObject& anh,int val) {
	anh.ApplySurface(renderer, rect.x, rect.y);
	
	rect.y += val;
	
}
SDL_Rect WeaponObject::getRect() {
	return rect;
}



