#include <iostream>
#include <vector>
using namespace std ;
int main()
{
    int count1 = 0 , count2 = 0 ;


    int a[3] ;
    int b[3] ;


    for(int i = 0 ; i < 3 ; i++){
        cin >> a[i] ;
    }
    for(int i = 0 ; i < 3 ; i++){
        cin >> b[i] ;
    }


    for(int i = 0 ; i < 3 ; i++){
        if(a[i] > b[i])
            count1++ ;
        else if(a[i] < b[i])
            count2++ ;
    }

    cout << count1 << " " << count2 ;


    return 0 ;
}
