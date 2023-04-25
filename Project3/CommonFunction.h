#pragma once


#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include<vector>
#include <ctime>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

static int score=0;

static int val = 3;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_Renderer = NULL;
 
static SDL_Event g_even;

static TTF_Font* font = NULL;

static Mix_Chunk* g_OpenGame = NULL;
static Mix_Chunk* g_WeaponHit = NULL;

static Mix_Music* g_MusicMenu = NULL;
static Mix_Music* g_MusicGame = NULL;