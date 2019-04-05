BT1:
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std ;

char* concat(const char* s1, const char* s2){
    int my_lenght = strlen(s1) + strlen(s2) ;
    char* my_string = new char[my_lenght] ; // my_string là xâu rỗng
    my_string = strcpy(my_string, s1) ; // thêm s1 vào đầu my_string
    my_string = strcat(my_string, s2) ; // nối s2 vào my_string

    return my_string ;
}

int main()
{
    cout << concat("ho van ", "thep") ;
    return 0 ;
}

BT2:
BT3:
BT4:

#include <iostream>
using namespace std ;
int* p  ;
int main()
{

    int a = 10 ;
    p = &a  ;

    delete p ;
    return 0 ;

}



Phần C
BT1 : int* p = 10
BT2 : 1
BT3 : iii
BT4 :
BT5 : int a = 0; prinPtr(a) ---> truyền địa chỉ không phải truyền giá trị
BT6 : number = aPtr
BT7 : for(int i = 0; i < N; i++) cout << *(p + i) ;
BT8 : 5(gán giá trị của p1 trước khi tang a) 6(gán địa chỉ)
BT9 :
BT10 :
BT11 :
BT12 :
BT13 :
BT14 :
BT15 :
BT16 :

