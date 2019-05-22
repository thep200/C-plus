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
string Findnumber(int s[50], int x)
{
    string s1 = "Tim Thay" ;
    string s2 = "Khong Tim Thay" ;
    int Left = 0 ;
    int Righ = 14 ;
    while(Left <= Righ)
    {
        int Midle = (Left + Righ)/2 ;
        if(s[Midle] == x) return s1 ;
        else if(s[Midle] > x) Righ = Midle - 1 ;
        else if(s[Midle] < x) Left = Midle + 1;
    }
    return s2 ;
}



int main()
{
    int s[15] = {1, 4, 2, 3, 5, 8, 15, 9, 12, 11, 10, 14, 13, 6, 7} ;
    ButbleSort(s) ;
    int x ;
    while(x != 1)
    {
        cin >> x ;
        cout << Findnumber(s, x) << endl ;
    }

    return 0 ;
}
