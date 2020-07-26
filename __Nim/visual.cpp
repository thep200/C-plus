#include <bits/stdc++.h>
#include <SDL.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include <conio.h>
#include "column.h"
#include "game.h"
#include "visual.h"

using namespace std ;

const int SCREEN_WIDTH  = 1000 ;
const int SCREEN_HEIGHT = 600 ;
const string WINDOW_TITLE = "Nim Game" ;

SDL_Window *window ;
SDL_Surface *surface ;
SDL_Texture *texture ;
SDL_Renderer *renderer ;


int n, level;

bool check(Game g)
{
    int x = 0 ;
    for(int i = 0; i < g.n; i++){
      x ^= g.c[i].number ;    // check tổng XOR các phần tử đĩa trong từng cột một với nhau
    }                         // Tổng XOR khác không thì là một nước đi thua -> go_to_win()
    if (x == 0){              // Tổng XOR  bằng 0 thì là một nước đi thắng -> go()
        return true ;
    }
    return false ;
}

void go_to_win(Game &g)           // thực hiện bước đi sau khi thực hiện là một nước đi thua
{
    for(int i = 0; i < g.n; i++){
        int x = 0 ;
        for(int j = 0; j < g.n; j++)
            if (j != i){                    // tìm nước đi thắng cho game
              x ^= g.c[j].number ;          // XOR tất cả các phần tử đĩa ở từng cột với phần tử được chọn
            }                               // nếu tổng XOR nhỏ hơn số được chọn thì là một cột thỏa mãn nước đi thắng
                                            // nếu tổng XOR lớn hơn số được chọn thì là một cột không thỏa mãn nước đi thắng
        if (x < g.c[i].number){
            while(g.c[i].number > x){
              g.c[i].dec() ;                // thực hiện bốc đĩa ở cột thỏa mãn nước đi thắng
            }
            return ;
        }
    }


}

void go(Game &g)
{
    int max_col = 0 ;
    for(int i = 0; i < g.n; i++)                    // thực hiện bước đi sau khi xác định là một nước đi thắng
        if (g.c[i].number > g.c[max_col].number){   // chọn ra một cột có nhiều đĩa nhất và bốc ở đĩa đó
           max_col = i ;
        }
    g.c[max_col].dec() ;

    return ;
}

void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl ;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void init()
{
    SDL_Init(SDL_INIT_VIDEO) ;

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,  SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (window == NULL) logSDLError(cout, "CreateWindow", true) ;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;
    if (renderer == NULL) logSDLError(cout, "CreateRenderer", true) ;

}

void quit_sdl()
{
    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;
    SDL_Quit() ;
}

void draw_column(Column _c, int width)
{

    SDL_Rect pos = {width, 420, 70, 35};

    for(int i = 0; i < _c.number; i++){
        SDL_SetRenderDrawColor(renderer, rand() % 155 + 100, rand() % 200 + 55, rand() % 255, rand() % 155 + 100) ;
        SDL_RenderFillRect(renderer, &pos);      // in đậm
        pos.y -= 37;
    }
}
void draw_recent(Column _c, int width)          // vẽ ô đánh dấu cột được chọn
{
    SDL_Rect pos = {width, 460, 70, 20};
    SDL_SetRenderDrawColor(renderer, 150, 255, 50, 100) ;
    SDL_RenderDrawRect(renderer, &pos);
}

void draw(Game _g)
{
    int w = 50 ;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) ; // nền đen

    SDL_RenderClear(renderer) ;

    for(int i = 0; i < _g.n; i++){
        draw_column(_g.c[i], w) ;

        if (i == _g.recent){
          draw_recent(_g.c[_g.recent], w) ;
        }
        w += 100 ;
    }

    SDL_RenderPresent(renderer) ;
}

bool Test_column(Game _g)
{
    int k = 0 ;
    for(int i = 0; i < _g.n; i++){
        if(_g.c[i].number != 0){
            k++ ;
        }
    }
    if(k != 0) return true ;
    else       return false ;
}

void Sound_Game(int n)
{
        if(n == 1){
            PlaySound(TEXT("nova.wav") , NULL , SND_ASYNC) ;
        }
        else if(n == 2){
            PlaySound(NULL , NULL , SND_ASYNC) ;
        }
}

void createGame(Game &_g)
{
    Column _c ;


    n = level * 3 - (rand() % 3);

    for(int i = 0; i < n; i++){

        _c.number = 3 + rand()% 7 ; // random số đĩa trong cột

        _g.add_column(_c) ;

    }
    _g.recent = 0;
}

void menu()
{
    surface = SDL_LoadBMP("123.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    while(SDL_WaitEvent(&event)){
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        level = 1 ;
                        return ;
                        break ;

                    case SDLK_2:
                        level = 2 ;
                        return ;
                        break ;

                    case SDLK_3:
                        level = 3 ;
                        return ;
                        break ;

                }

            break;
        }

    }
}

void gamePlay()
{

    Sound_Game(1) ;
    Game _g ;
    bool your_turn = 0 ;

    createGame(_g) ;

    draw(_g) ;

    SDL_Event event ;

    while(SDL_WaitEvent(&event)){
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        if (your_turn == 0){
                            _g.move_left();
                            draw(_g);
                        }
                        break ;

                    case SDLK_RIGHT:
                        if (your_turn == 0){
                            _g.move_righ();
                            draw(_g);
                        }
                        break ;

                    case SDLK_DOWN:                      // thực hiện nhấn event down thì your_turn tăng lên xác nhận lượt đi của người chơi
                        if (_g.c[_g.recent].number){
                            _g.c[_g.recent].dec() ;
                            draw(_g);
                            your_turn = 1;
                        }
                        break ;

                    case SDLK_SPACE:
                        if (your_turn == 1){

                            SDL_Delay(500) ;

                            if (check(_g)){
                                go(_g) ;
                            }
                            else{
                                go_to_win(_g) ;
                            }

                            draw(_g) ;

                            your_turn = 0 ;

                            if (!Test_column(_g)){
                                cout << "computer win !" ;
                                SDL_Delay(3000) ;
                                quit_sdl() ;

                            }
                        }

                }
                        break;

                        if (!Test_column(_g)){
                                cout << "You Win!";
                        }

        }

    }

    quit_sdl();

}

