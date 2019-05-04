#include <iostream>
#include "game.h"
#include "column.h"
#include <vector>

using namespace std;

Game::Game()
{
    n = 0 ;
    recent = 0 ;
    c.clear();
}

void Game::move_left()
{
    if (recent == 0){
        return ;        // nếu như là cột ngoài cùng bên trái thì không nhận event di chuyển
    }

    recent-- ;
}

void Game::move_righ()
{
    if (recent == n - 1){
        return ;       // nếu như là cột ngoài cùng bên phải thì không nhận event di chuyển
    }

    recent++ ;
}

void Game::add_column(Column _c)
{
    c.push_back(_c);
    n++ ;
}
