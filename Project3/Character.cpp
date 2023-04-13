#include "Character.h"
Character::Character() {
	
	
	x_val = 0;
	rect = { 0,487,Width,Height };
}


	

SDL_Rect Character::getRect() {
	return rect;
}
void  Character::HandleInputAction(SDL_Event &events)
{
	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
	{
		switch (events.key.keysym.sym)
		{


		case SDLK_LEFT:
			//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
			x_val -= 90 / 4;
			break;

		case SDLK_RIGHT:
			//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
			x_val += 90 / 4;
			break;

		default:
			//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			break;
		}
	}
	else if (events.type == SDL_KEYUP && events.key.repeat == 0)
	{
		//Adjust the velocity
		switch (events.key.keysym.sym)
		{

		case SDLK_LEFT:
			x_val += 90 / 4;
			break;
		case SDLK_RIGHT:
			x_val -= 90 / 4;
			break;
		}
	}
}

void Character::RenderCharacter(SDL_Renderer* renderer, BaseObject& character) {
	character.ApplySurface(renderer, rect.x, rect.y);
}

void Character::HandleMove() {
	rect.x += x_val;
	if ((rect.x < 0) || (rect.x + 57 > SCREEN_WIDTH))
	{
		//Move back
		rect.x -= x_val;
	}
}

