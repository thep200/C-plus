#include <iostream>
#include <algorithm>
using namespace std ;
int main()
{
    int a[5] ;
    int sum1 = 0 , sum2 = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        cin >> a[i] ;
    }
    sort(a , a + 5) ;
    for(int i = 0 ; i < 4 ; i++){
        sum1 += a[i] ;
    }
    for(int i = 4 ; i >= 1 ;i--){
        sum2 += a[i] ;
    }
    cout << sum1 << " " << sum2 ;


    return 0 ;
}
