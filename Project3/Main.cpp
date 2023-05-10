#include "CommonFunction.h"
#include "BaseObject.h"
#include"WeaponObject.h"
#include "Character.h"
#include "Coin.h"
#include "Life.h"

BaseObject g_Bkground;
Character g_Character;
BaseObject g_Score;
BaseObject g_HighScore;
BaseObject g_Menu;
BaseObject g_End;
Coin g_Coin;
Life g_Life;
int rand_x = rand() % 1200;
WeaponObject g_Weapon(rand_x);
vector<WeaponObject> weaponlist;
void CleanUp()
{
	//Free sound
	Mix_FreeChunk(g_OpenGame);
	Mix_FreeChunk(g_GameOver);
	Mix_FreeChunk(g_Running);
	Mix_FreeChunk(g_Hit);
	g_OpenGame = NULL;
	g_GameOver = NULL;
	g_Running = NULL;
	g_Hit = NULL;

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
		//Create window
		g_window = SDL_CreateWindow("New game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (g_window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Create renderer
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
				//Initialize Font loading
				if (TTF_Init() == -1) {
					printf("SDL_font could not initialize! SDL_font Error: %s\n", TTF_GetError());
					success = false;
				}
				//Initialize Audioloading
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

//Initializw Main Menu
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
				CleanUp();
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

//Initiallize EndMenu
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
		g_Score.ApplySurface(g_Renderer, 650, 0);
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
	srand(time(0));
	bool is_quit = false;
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		//Load Media
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
			printf("Failed to load weapom texture image!\n");

		}
		if (!g_Coin.LoadImage(g_Renderer, "Coin.png"))
		{
			printf("Failed to load coin texture image!\n");

		}
		g_Life.Init(g_Renderer,g_Life);
		g_OpenGame = Mix_LoadWAV("StartGame.wav");
		if (g_OpenGame == NULL) {
			printf("Failed to load sound!\n");
			Mix_GetError();
		}
		g_Hit = Mix_LoadWAV("Clash.wav");
		if (g_Hit == NULL) {
			printf("Failed to load sound!\n");
			Mix_GetError();
		}
		g_GameOver = Mix_LoadWAV("Hit.wav");
		if (g_GameOver == NULL) {
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
		//Create time
		int time = 0;				
		int menu = ShowMenu(g_Menu);
		if (menu == NULL) {
			printf("Function Menu error");
		}
		if (menu == 1) {
			is_quit = true;
		}
		//Star game loop
		while (true) {
			//ResetValue
			is_quit = false;
			score = 0;
			int CoinPos = rand() % 1200 + 1;;
			val = 3;
			lifecount = 0;
			g_Character.SetVal(0);
			g_Coin.SetInitialPos(CoinPos);
			g_Life.Init(g_Renderer,g_Life);
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
					//Handle Movement
					g_Character.HandleInputAction(g_even);
					g_Character.HandleMove();					
                }				
				font = TTF_OpenFont("gamefont.ttf", 50);
				if (font == NULL) {
					printf("Failed to load Font!\n");
				}
				else
				{
					if (!g_Score.LoadTtf(g_Renderer, "Current Score:" + to_string(score), font, color)) {
						printf("Failed to load Font!\n");
					}					
				}
				//Create new weapon
				if (time % 50 == 0) {
					int a = rand() % 1200 + 1;
					weaponlist.emplace_back(a);
				}
				//Clear screen
				SDL_RenderClear(g_Renderer);

				//Render texture to screen
				g_Bkground.ApplySurface(g_Renderer, NULL, NULL);
				//Coin collider
				if (check(g_Character.getRect(), g_Coin.getRect())) {
					score += 10;
					g_Coin.SetPos();
					}
				//Score
				if (score > 0 && score % 10 == 0) {
					val+=0.5;
				}
				//Render weapon
				for (int i = 0; i < weaponlist.size(); i++) {
					weaponlist[i].CreateWeapon(g_Renderer, g_Weapon, val);
				}
				//Render score,character and coin
				g_Score.ApplySurface(g_Renderer, 0, 0);
				g_Character.RenderCharacter(g_Renderer, g_Character);
				g_Coin.CreateCoin(g_Renderer, g_Coin);
				g_Life.CreateLife(g_Renderer, g_Life);
				//Delay game
				SDL_Delay(10);
				//Update screen
				SDL_RenderPresent(g_Renderer);
				//Increase time as long as game is playing
				time++;
				//Check Collider
				for (int i = 0; i < weaponlist.size(); i++) {
					if (check(weaponlist[i].getRect(), g_Coin.getRect())) {
						score -= 10;
						if (score < 0) {
							score = 0;
						}
						g_Coin.SetPos();
					}
					if (check(g_Character.getRect(), weaponlist[i].getRect())) {
						lifecount++;
						Mix_PlayChannel(-1, g_Hit, 0);
						weaponlist.clear();
						FileFunction(file, 0, HighScore);
						if (score > HighScore) {
							HighScore = score;
							FileFunction(file, 1, HighScore);
						}
						
						SDL_RenderClear(g_Renderer);
						if (lifecount == 3) {
							Mix_HaltMusic();
							Mix_PlayChannel(-1, g_GameOver, 0);
							is_quit = true;
						}
						else {
							g_Life.Decrease();
							g_Life.CreateLife(g_Renderer, g_Life);
						}
					}
				}				
			}
			is_quit = false;
			//Initialize End Menu
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
