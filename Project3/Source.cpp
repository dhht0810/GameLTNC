#include "CommonFunction.h"
#include "BaseObject.h"
#include"WeaponObject.h"
#include "Character.h"
using namespace std;

int y_weaponpos;
int y_weaponval;

//Character g_char;

BaseObject g_Bkground;
Character g_Character;

int rand_x = rand() % 1200;
WeaponObject g_Weapon(rand_x);
vector<WeaponObject> weaponlist;
void CleanUp()
{

	//Free loaded image
	g_Bkground.free();
	g_Character.free();
	for (int i = 0; i < weaponlist.size(); i++) {
		weaponlist[i].free();
	}
	//Destroy window    
	SDL_DestroyRenderer(g_Renderer);
	SDL_DestroyWindow(g_window);

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}



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
bool check(SDL_Rect a, SDL_Rect b) {
	if (a.x + a.w <= b.x) return false;
	if (a.x >= b.x + b.w) return false;
	if (a.y + a.h <= b.y) return false;
	if (a.y >= b.y + b.h) return false;
	return true;
}



int main(int arc, char* argv[]) {
	bool is_quit = false;
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if (!g_Bkground.LoadImage(g_Renderer, "bkground.png"))
		{
			printf("Failed to load background texture image!\n");

		}
		if (!g_Character.LoadImage(g_Renderer, "character.png"))
		{
			printf("Failed to load character texture image!\n");

		}
		if (!g_Weapon.LoadImage(g_Renderer, "shuriken.png"))
		{
			printf("Failed to load character texture image!\n");

		}

		int time = 0;
		int i = 10;
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
			}
			if (time % 30 == 0) {
				int a = rand() % 1200 + 1;
				weaponlist.emplace_back(a);
			}
							//Clear screen
			SDL_RenderClear(g_Renderer);

			//Render texture to screen
			g_Bkground.ApplySurface(g_Renderer, NULL, NULL);
			g_Character.RenderCharacter(g_Renderer, g_Character);
			
			for (int i = 0; i < weaponlist.size(); i++) {
				weaponlist[i].CreateWeapon(g_Renderer, g_Weapon);
			}
			
			SDL_Delay(i);
			
			
			//Update screen
			SDL_RenderPresent(g_Renderer);
			time++;
			for (int i = 0; i < weaponlist.size(); i++) {
				if (check(g_Character.getRect(), weaponlist[i].getRect())) {
					is_quit = true;
				}
			}


		}
		is_quit = false;
		while (!is_quit) {
			while (SDL_PollEvent(&g_even)) {
				if (g_even.type == SDL_QUIT)
				{
					is_quit = true;
					break;
				}
			}
		}

		CleanUp();


		return 1;
	}
}
//
