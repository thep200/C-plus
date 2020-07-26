#include <iostream>
#include "column.h"

Column :: Column() = default ;

Column::Column(int n)
{
    number = n ;
}

void Column :: dec()
{
    number -- ;
}
