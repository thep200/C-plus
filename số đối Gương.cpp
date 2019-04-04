#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int Test(int in_put)
{
     vector <int> v ;
     while(in_put != 0){
        int k = in_put%10 ;
        v.push_back(k) ;
        in_put = in_put/10 ;
    }

    int my_size = v.size() ;
   // cout << my_size ;

    int sodu1 = my_size%2 ;

    if(sodu1 != 0){
        int sodu1 = my_size/2 - 1;
        int sodu2 = my_size + 1 ;

        while(sodu1 >= 0){
            if(v[sodu1] != v[sodu2]){
                return -1 ;
            }

            sodu1-- ;
            sodu2++ ;
        }
    }
    else{
        int sodu3 = 0 ;
        int sodu4 = my_size - 1 ;

        while(sodu3 < sodu4){
            if(v[sodu3] != v[sodu4]){
                return -1 ;
            }
            sodu3++ ;
            sodu4-- ;
        }
    }

    return 1 ;
}


void Process(int a, int b)
{
    int Count = 0 ;
    for(int i = a; i <= b; i++){
        if(Test(i) == 1){
            Count++ ;
        }

    }
    cout << Count<< endl ;
}

int main()
{
    int n, a, b ;
    cin >> n ;
    while(n != 0){
        cin >> a >> b ;
        Process(a, b) ;
    }
    return 0 ;
}

