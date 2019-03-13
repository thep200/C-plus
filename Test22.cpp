#include <iostream>
using namespace std ;
int Factorial(int n)
{
    cout << "n = " << n <<  "   at   " << &n << endl ;
    if(n == 0 ) return 1 ;
    else        return n*Factorial(n - 1) ;
}
int main()
{
    int n ;
    cin >> n ;
    cout << Factorial(n) ;
    return 0 ;
}
// là khoảng cách của stack frame
