#include <iostream>
using namespace std ;
int main()
{
    int a[3] = {1, 2, 3} ;
    char b[3] = {'a', 'b', 'c'} ;
        cout << "&a" << "         " << "&b" << endl ;
    for(int i = 0 ; i < 3 ; i++){
        cout << &a[i] << "   " << &b[i] << endl ;
        return 0 ;
}
