#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

bool Comfirmation(vector <int> &v, int &k, int &n)
{
    int Count1 = 0 ;
    int sum1 = 0, sum2 = 0 ;
    int i = k - 2 ;
    int j = k ;


    while(i >= 0 && j < n){
           //cout << "i" << v[i] ;
        sum1 += v[i] ;
           //cout << "j" << v[j] ;
        sum2 += v[j] ;
        if(sum1 > sum2){
            j++ ;
            sum1 -= v[i] ;
            //cout << endl ;
        }
        else if(sum1 < sum2){
            i-- ;
            sum2 -= v[j] ;
            //cout << endl ;
        }
        else if(sum1 == sum2){
            Count1++ ;
            break ;
        }
    }


    if(Count1 != 0)
        return true ;
    else
        return false ;


}


void Processing(vector <int> &v, int &n)
{
    int x ;
    for(int i = 0; i < n; i++){
        cin >> x ;
        v.push_back(x) ;
    }

    int Count1 = 0 ;
    for(int i = 2; i <= n - 1; i++){
        bool k = Comfirmation(v, i, n) ;
        if(k == true){
            Count1++ ;
        }
    }



    if(Count1 != 0)
        cout << "YES" << endl ;
    else
        cout << "NO" << endl ;

}


int main()
{

    int n ;
    vector <int> v ;



    int turn ;
    cin >> turn ;
    int i = 1 ;
    while(i <= turn){
        cin >> n ;
    Processing(v, n) ;
    v.clear();
    i++ ;
    }


    return 0 ;

}
