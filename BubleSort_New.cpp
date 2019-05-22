#include <iostream>
using namespace std ;
void Swap(int &a, int &b)
{
    int k ;
    k = a ;
    a = b ;
    b = k ;
}
void Print(int a[50])
{
    for(int i = 0; i < 15; i++){
        cout << a[i] << " "  ;
    }
}
void ButbleSort(int s[50])
{
    for(int i = 0; i < 15; i++){
        for(int j = i + 1; j < 15; j++){
            if(s[i] > s[j]) Swap(s[i], s[j]) ;
        }
    }
}
int main()
{
    int s[15] = {1, 4, 2, 3, 5, 8, 1000, 9, 12, 11, 10, 14, 13, 6, 7} ;
    ButbleSort(s) ;
    Print(s) ;
    return 0 ;
}
