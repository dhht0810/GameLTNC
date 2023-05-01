

#include "CommonFunction.h";
bool check(SDL_Rect a, SDL_Rect b) {
	if (a.x + a.w <= b.x) return false;
	if (a.x >= b.x + b.w) return false;
	if (a.y + a.h <= b.y) return false;
	if (a.y >= b.y + b.h - 15) return false;
	return true;
}

void FileFunction(fstream& file, int n,int& Highscore) {
	if (n != 1 && n != 0) {
		printf("Wrong number");
	}
	file.open("HighScore.txt");
	if (n == 0) {
		file >> Highscore;
	}
	if (n == 1) {
		file << Highscore;
	}
	file.close();
}