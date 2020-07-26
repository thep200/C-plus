#ifndef _COLUMN_H
#define _COLUMN_H

struct Column
{
    int number ;      // số đĩa trong cột

    void dec() ;     // giảm số đĩa của cột được chọn khi nhận vào event

    Column() ;

    Column(int n) ;
};

#endif // _COLUMN_H
