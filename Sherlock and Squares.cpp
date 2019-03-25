#include <iostream>
#include <vector>
#include <math.h>
using namespace std ;

bool Test(int &n)
{
    int n1 ;
    n1 = (int)sqrt(n) ;
    if(n1*n1 == n)
        return true ;
    else
        return false ;
}

int out_put(int &a, int &b)
{
    bool k ;
    int Count = 0 ;
    for(int i = a; i <= b; i++){
        k = Test(i) ;

        if(k == true){
            Count++ ;
        }
    }
    return Count ;
}


int main()
{
    int n ;
    cin >> n ;
    int x ;
    vector <int> v ;


    for(int i = 1; i <= 2*n; i++){
        cin >> x ;
        v.push_back(x) ;
    }


    for(int i = 0; i < 2*n; i += 2){
        cout << out_put(v[i], v[i + 1]) << endl ;
    }

    return 0 ;
}
