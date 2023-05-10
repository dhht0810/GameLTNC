#pragma once


#include <SDL.h>
#include <stdio.h>
#include <string>
#include<iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include<vector>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

//static int score=0;

static int val = 3;
static int score;
static int lifecount=0;
static SDL_Window* g_window = NULL;
static SDL_Renderer* g_Renderer = NULL;
 
static SDL_Event g_even;

static TTF_Font* font = NULL;
static SDL_Color color = { 255,128,0 };
static Mix_Chunk* g_OpenGame = NULL;
static Mix_Chunk* g_GameOver = NULL;
static Mix_Chunk* g_Running = NULL;
static Mix_Chunk* g_Hit = NULL;

static Mix_Music* g_MusicMenu = NULL;
static Mix_Music* g_MusicGame = NULL;



static fstream file;
static int HighScore;

bool check(SDL_Rect a, SDL_Rect b);
void FileFunction(fstream& file, int n,int& Highscore);
bool CheckFocus(const int& x, const int& y, SDL_Rect& rect);
