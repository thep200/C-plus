#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <vector>
#include "column.h"

using namespace std ;

struct Game
{
    int n ;        // số lượng đĩa trong cột

    int recent ;   // địa chỉ cột được chọn

    vector <Column> c ;   // một mảng gồm các cột do người dùng chọn

    void move_left() ;    // nhận event di chuyển sang trái để chọn cột

    void move_righ() ;    // nhận event di chuyển sang phải để chọn cột

    void add_column(Column c) ;

    Game() ;
};

#endif // _GAME_H
