#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std ;



void input(vector <int> &v1 , int &n)
{
    int x ;
    for(int i = 0 ; i < n ; i++){
        cin >> x ;
        v1.push_back(x) ;
    }
}

int main()
{
    vector <int> v1 ;
    vector <int> v2 ;
    int n1 , n2 ;
    cin >> n1 ;
    input(v1 , n1) ;
    cin >> n2 ;
    input(v2 , n2) ;
    sort(v1.begin() , v1.end()) ;
    sort(v2.begin() , v2.end()) ;
    if(n1 > n2)
    {
        int i = 0 ;
    while(i < n1){
        if(v1[i] != v1[i + 1]){

            int x1 = count(v1.begin() , v1.end() , v1[i]) ;
            int x2 = count(v2.begin() , v2.end() , v1[i]) ;

            for(int j = 0 ; j < abs(x1 - x2) ; j++){
                cout << v1[i] << " " ;
            }

            }

        i++ ;


        }
    }
    else
    {
        int i = 0 ;
    while(i < n2){
        if(v2[i] != v2[i + 1]){

            int x1 = count(v1.begin() , v1.end() , v2[i]) ;
            int x2 = count(v2.begin() , v2.end() , v2[i]) ;

            for(int j = 0 ; j < abs(x1 - x2) ; j++){
                cout << v2[i] << " " ;
            }

            }

        i++ ;


        }
    }

        //-----------
    return 0 ;
}
