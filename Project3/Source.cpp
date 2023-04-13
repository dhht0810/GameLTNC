#include "CommonFunction.h"
#include "BaseObject.h"
#include"WeaponObject.h"
#include "Character.h"
using namespace std;


int y_weaponpos;
int y_weaponval;

//Character g_char;
vector<WeaponObject> weapon;
BaseObject g_Bkground;
Character g_Character;
BaseObject g_weapon;


void CleanUp()
{

	//Free loaded image
	g_Bkground.free();


	//Destroy window    
	SDL_DestroyRenderer(g_Renderer);
	SDL_DestroyWindow(g_window);

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

//void HandleInputAction(SDL_Event events)
//{
//	if (events.type == SDL_KEYDOWN && events.key.repeat == 0)
//	{
//		switch (events.key.keysym.sym)
//		{
//	
//
//		case SDLK_LEFT:
//			//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
//			x_val -= 90 / 4;
//			break;
//
//		case SDLK_RIGHT:
//			//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
//			x_val += 90 / 4;
//			break;
//
//		default:
//			//gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
//			break;
//		}
//	}
//	else if (events.type == SDL_KEYUP && events.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (events.key.keysym.sym)
//		{
//		
//		case SDLK_LEFT: 
//			x_val += 90/4; 
//			break;
//		case SDLK_RIGHT: 
//			x_val -= 90/4; 
//			break;
//		}
//	}
//}
//
//
//
//void HandleMove() {
//	x_pos += x_val;
//	if ((x_pos < 0) || (x_pos + 57 > SCREEN_WIDTH))
//	{
//		//Move back
//		x_pos -= x_val;
//	}
//}
//	void moveWepon() {
//		y_weaponpos += 50 / 4;
//		if ((y_weaponpos + 50 > SCREEN_HEIGHT))
//		{
//			//Move back
//			y_weaponpos -= 50/4;
//	 }
//		
//}


bool Init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) <0)
    {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
    }
    else
    {
		//KhoitaoWindow
        g_window = SDL_CreateWindow("New game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (g_window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
			//LayBematchoWindow
			g_Renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        
		if (g_Renderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

		}
	}
    }
    return success; 
}
bool check(SDL_Rect& a, SDL_Rect& b) {
	if (a.x + a.w <= b.x) return false;
	if (a.x >= b.x + b.w) return false;
	if (a.y + a.h <= b.y) return false;
	if (a.y >= b.y + b.h) return false;
	return true;
}


int main(int arc, char* argv[]) {
	bool is_quit = false;
	
	int c = rand() % 1000;
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if (!g_Bkground.LoadImage(g_Renderer,"bkground.png"))
		{
			printf("Failed to load background texture image!\n");
			
		}
		if (!g_Character.LoadImage(g_Renderer, "character.png"))
		{
			printf("Failed to load character texture image!\n");

		}
		if (!g_weapon.LoadImage(g_Renderer, "shuriken.png"))
		{
			printf("Failed to load character texture image!\n");

		}
		
        //g_weapon = LoadImage("shuriken.png");
		//if (g_weapon == NULL) {
		//	printf("Failed to load weapon");
		//	return 0;
		//}
		int time = 0;
		while (!is_quit)
		{
			while (SDL_PollEvent(&g_even))
			{
				if (g_even.type == SDL_QUIT)
				{
					is_quit = true;
					break;
				}
				g_Character.HandleInputAction(g_even);
				g_Character.HandleMove();
				if (time % 20 == 0) {
					int a = rand() % 1200 + 1;
					weapon.emplace_back(a);
				}
				//g_character.HandleInputAction(g_even,g_Renderer);
				//g_character.HandleMove();
				//moveWepon();//
				//Blit bkground sang surface
				   //Clear screen
				SDL_RenderClear(g_Renderer);

				//Render texture to screen
				g_Bkground.ApplySurface(g_Renderer,NULL, NULL);
				g_Character.RenderCharacter(g_Renderer, g_Character);
				
				
				for (int i = 0; i < weapon.size(); i++) {
					weapon[i].CreateWeapon(g_Renderer,g_weapon);
				}
				/* ApplySurface(g_Renderer, g_object,x_pos , 487,57,90);
				 for (int i = 0; i < 2; i++) {
					 ApplySurface(g_Renderer, g_weapon, 400, y_weaponpos, 50, 50);*/
			/*}*/
			/*SDL_RenderCopy(g_Renderer, g_object, 438, 487);*/


		//Update screen
			SDL_RenderPresent(g_Renderer);
			time++;
		}
			
	}
}
			
	CleanUp();
	
	
	return 1;
}
//