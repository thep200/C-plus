#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "visual.h"
using namespace std;

int main()
{
    //Sound_Game(1) ;
    srand(time(0)) ;
    init();
    menu();
    gamePlay();
    return 0;
}
