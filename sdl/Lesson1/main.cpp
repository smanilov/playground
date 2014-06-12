#include <iostream>
#include <SDL2/SDL.h>

using std::cerr;
using std::endl;

bool init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                cerr << "SDL_Init Error: " << SDL_GetError() << endl;
                return false;
        } else {
                return true;
        }
}

SDL_Window* make_win() {
        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480,
                                           SDL_WINDOW_SHOWN);
        if (win == nullptr) {
                cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        }
        return win;
}

SDL_Renderer* make_ren(SDL_Window *win) {
        SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (ren == nullptr){
                cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        }
        return ren;
}

SDL_Surface* make_surface() {
        SDL_Surface *bmp = SDL_LoadBMP("res/hello.bmp");
        if (bmp == nullptr){
                cerr << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
        }
        return bmp;
}

SDL_Texture* make_tex(SDL_Renderer *ren, SDL_Surface *bmp) {
        SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
        SDL_FreeSurface(bmp);
        if (tex == nullptr){
                cerr << "SDL_CreateTextureFromSurface Error: "
                     << SDL_GetError() << endl;
        }
        return tex;
}

int main(int argc, char **argv) {
        SDL_Window   *win;
        SDL_Renderer *ren;
        SDL_Surface  *bmp;
        SDL_Texture  *tex;

        if (!init()) { return 1; }
        if (nullptr == (win = make_win())) { return 1; }
        if (nullptr == (ren = make_ren(win))) { return 1; }
        if (nullptr == (bmp = make_surface())) { return 1; }
        if (nullptr == (tex = make_tex(ren, bmp))) { return 1; }

        render(ren, tex);

        cleanup(tex, ren, win);
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
        SDL_Delay(2000);

        SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();

        return 0;
}
