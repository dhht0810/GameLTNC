#include "BaseObject.h"
BaseObject::BaseObject()
{
	//Initialize
	g_bkground = NULL;
	mWidth = 0;
	mHeight = 0;
	
}

BaseObject::~BaseObject()
{
	//Deallocate
	free();
}
bool BaseObject::LoadImage(SDL_Renderer* renderer,std::string file_path)
{
	free();
	SDL_Texture* NewTexture = NULL;

	//Load image tại 1 đường dẫn cố định
	SDL_Surface* load_image = NULL;
	//(Thành công sau khi đổi file bkground sang PNG,cần kiểm chứng thêm ở JPG)
	load_image = IMG_Load(file_path.c_str());
	if (load_image == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", file_path.c_str(), SDL_GetError());
	}
	else {
		Uint32 color_key = SDL_MapRGB(load_image->format, 255, 255, 255);
		SDL_SetColorKey(load_image, SDL_TRUE, color_key);

		//đẩy nhanh quá trình blit ảnh,copy surface loadimage sang surface window_surface
		NewTexture = SDL_CreateTextureFromSurface(renderer, load_image);
		if (NewTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", file_path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = load_image->w;
			mHeight = load_image->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(load_image);
	}
	g_bkground = NewTexture;
	return g_bkground != NULL;

}


void BaseObject::ApplySurface(SDL_Renderer* renderer,int x, int y,SDL_Rect* clip)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	offset.w = mWidth;
	offset.h = mHeight;
	if (clip != NULL) {
		offset.w = clip->w;
		offset.h = clip->h;
	}
	if (mWidth == 1000) {
		SDL_RenderCopy(renderer, g_bkground, clip, NULL);
	}
	else {
		SDL_RenderCopy(renderer, g_bkground, clip, &offset);
	}
}




int BaseObject::getWidth()
{
	return mWidth;
}

int BaseObject::getHeight()
{
	return mHeight;
}
void BaseObject::free()
{
	//Free texture if it exists
	if (g_bkground != NULL)
	{
		SDL_DestroyTexture(g_bkground);
		g_bkground = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}