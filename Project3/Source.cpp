#include "CommonFunction.h"
#include "BaseObject.h"
#include"WeaponObject.h"
#include "Character.h"





BaseObject g_Bkground;
Character g_Character;
BaseObject g_Death;
BaseObject g_Font;
BaseObject g_HighScore;
BaseObject g_Menu;
BaseObject g_End;
int rand_x = rand() % 1200;
WeaponObject g_Weapon(rand_x);
vector<WeaponObject> weaponlist;
void CleanUp()
{
	Mix_FreeChunk(g_OpenGame);
	Mix_FreeChunk(g_WeaponHit);
	Mix_FreeChunk(g_Running);
	g_OpenGame = NULL;
	g_WeaponHit = NULL;
	g_Running = NULL;

	Mix_FreeMusic(g_MusicMenu);
	g_MusicMenu = NULL;
	Mix_FreeMusic(g_MusicGame);
	g_MusicGame = NULL;

	//Free loaded image
	g_Bkground.free();
	g_Character.free();
	for (int i = 0; i < weaponlist.size(); i++) {
		weaponlist[i].free();
	}
	//Destroy window    
	SDL_DestroyRenderer(g_Renderer);
	SDL_DestroyWindow(g_window);
	TTF_CloseFont(font);
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();
	Mix_Quit();
}

bool Init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
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
				if (TTF_Init() == -1) {
					printf("SDL_font could not initialize! SDL_font Error: %s\n", TTF_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}


bool CheckFocus(const int &x,const int &y, SDL_Rect& rect) {
	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
		return true;
	}
	return false;
}

int ShowMenu(BaseObject& anh) {
	if (!anh.LoadImage(g_Renderer, "mainmenu.png"))
	{
		printf("Failed to load character texture image!\n");

	}
	const int MenuItem = 1;
	SDL_Rect pos_arr[MenuItem];
	pos_arr[0] = { 760,340,305,40 };
	
	int x_Mouse, y_Mouse;
	SDL_Event event;
	while (true) {
		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(g_MusicMenu, -1);
		}
		anh.ApplySurface(g_Renderer, NULL, NULL);
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEBUTTONDOWN:
			{
				x_Mouse = event.motion.x;
				y_Mouse = event.motion.y;
				for (int i = 0; i < MenuItem; i++) {
					if (CheckFocus(x_Mouse,y_Mouse,pos_arr[i])) {
						Mix_HaltMusic();
						Mix_PlayChannel(-1, g_OpenGame, 0);
						return i;
					}
				}
			}
			default:
				break;
			}
		}
		SDL_RenderPresent(g_Renderer);
	}
	
	return 1;

}

int ShowEndMenu(BaseObject& anh) {
	if (!anh.LoadImage(g_Renderer, "Endgame.png"))
	{
		printf("Failed to load  texture image!\n");

	}
	const int MenuItem = 2;
	SDL_Rect pos_arr[MenuItem];
	pos_arr[0] = { 495,270,200,50 };
	pos_arr[1] = { 550,375,105,55 };
	int x_Mouse, y_Mouse;
	SDL_Event event;
	while (true) {
		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(g_MusicMenu, -1);
		}
		if (!g_HighScore.LoadTtf(g_Renderer, "Highest Score:" + to_string(HighScore), font, color)) {
			printf("Failed to load character texture image!\n");
		}		
		anh.ApplySurface(g_Renderer, NULL, NULL);
		g_HighScore.ApplySurface(g_Renderer, 0, 0);
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEBUTTONDOWN:
			{
				x_Mouse = event.motion.x;
				y_Mouse = event.motion.y;
				for (int i = 0; i < MenuItem; i++) {
					if (CheckFocus(x_Mouse, y_Mouse, pos_arr[i])) {
						Mix_HaltMusic();
						Mix_PlayChannel(-1, g_OpenGame, 0);
						return i;
					}

				}
			}
			default:
				break;
			}
		}
		SDL_RenderPresent(g_Renderer);
	}

	return 1;

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
		if (!g_Character.LoadImage(g_Renderer, "character2.png"))
		{
			printf("Failed to load character texture image!\n");

		}
		if (!g_Weapon.LoadImage(g_Renderer, "shuriken.png"))
		{
			printf("Failed to load character texture image!\n");

		}
		if (!g_Death.LoadImage(g_Renderer, "Dead.png"))
		{
			printf("Failed to load character texture image!\n");

		}
		g_OpenGame = Mix_LoadWAV("StartGame.wav");
		if (g_OpenGame == NULL) {
			printf("Failed to load sound!\n");
			Mix_GetError();
		}
		g_WeaponHit = Mix_LoadWAV("Hit.wav");
		if (g_WeaponHit == NULL) {
			printf("Failed to load sound!\n");
			Mix_GetError();
		}
		g_Running = Mix_LoadWAV("Running.wav");
		if (g_Running == NULL) {
			printf("Failed to load sound!\n");
			Mix_GetError();
		}
		g_MusicMenu = Mix_LoadMUS("MenuMusic.wav");
		if (g_MusicMenu == NULL)
		{
			printf("Failed to load menu music!\n");
			Mix_GetError();
		}
		g_MusicGame = Mix_LoadMUS("GameMusic.wav");
		if (g_MusicGame == NULL)
		{
			printf("Failed to load game menu music!\n");
			Mix_GetError();
		}

		int time = 0;
		int i = 10;
		
		int menu = ShowMenu(g_Menu);
		if (menu == NULL) {
			printf("Function Menu error");
		}
		if (menu == 1) {
			is_quit = true;
		}
		
		while (true) {
			is_quit = false;
			int score = 0;
			val = 3;
			g_Character.SetVal(0);
			while (!is_quit)
			{
				if (Mix_PlayingMusic() == 0)
				{
					//Play the music
					Mix_PlayMusic(g_MusicGame, -1);
				}
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
				
				font = TTF_OpenFont("gamefont.ttf", 50);
				if (font == NULL) {
					printf("Failed to load character texture image!\n");
				}
				else
				{
					if (!g_Font.LoadTtf(g_Renderer, "Current Score:" + to_string(score), font, color)) {
						printf("Failed to load character texture image!\n");
					}
					
				}
				if (time % 30 == 0) {
					int a = rand() % 1200 + 1;
					weaponlist.emplace_back(a);
				}
				//Clear screen
				SDL_RenderClear(g_Renderer);

				//Render texture to screen
				g_Bkground.ApplySurface(g_Renderer, NULL, NULL);
				if (score > 0 && score % 50 == 0) {
					val++;
				}
				for (int i = 0; i < weaponlist.size(); i++) {


					weaponlist[i].CreateWeapon(g_Renderer, g_Weapon, val);

				}
				g_Font.ApplySurface(g_Renderer, 0, 0);
				g_Character.RenderCharacter(g_Renderer, g_Character);
				

				SDL_Delay(10);
				//Update screen
				SDL_RenderPresent(g_Renderer);
				time++;
				if (time % 10 == 0) {
					score++;
				}
				for (int i = 0; i < weaponlist.size(); i++) {
					if (check(g_Character.getRect(), weaponlist[i].getRect())) {
						Mix_HaltMusic();
						Mix_PlayChannel(-1, g_WeaponHit, 0);
						weaponlist.clear();
						FileFunction(file, 0, HighScore);
						if (score > HighScore) {
							HighScore = score;
							FileFunction(file, 1, HighScore);
						}
						
						SDL_RenderClear(g_Renderer);
						is_quit = true;
					}
				}
				

			}
			is_quit = false;
			
			int end = ShowEndMenu(g_End);
			
			while (!is_quit) {
				while (SDL_PollEvent(&g_even)) {
					if (g_even.type == SDL_QUIT)
					{
						is_quit = true;
						break;
					}
					if (end == 0) {
						is_quit = true;
					}
					if (end == 1) {
						CleanUp();
					}
					
				}
				SDL_RenderPresent(g_Renderer);
			}
			

		
	}
}
		CleanUp();

		
		return 1;
	}

//
