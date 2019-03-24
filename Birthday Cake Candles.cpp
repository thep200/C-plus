#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int main()
{
    int n, x ;
    int Max = 0 ;
    int Count1 = 0 ;
    vector <int> v ;

    cin >> n ;

    for(int i = 0; i < n; i++){
        cin >> x ;
        v.push_back(x) ;
    }

    sort(v.begin() , v.end()) ;

    for(int i = 0; i < n; i++){
        if(v[i] != v[i + 1]){
            Count1 = count(v.begin(), v.end(), v[i]) ;
        }
        if(Count1 > Max)
            Max = Count1 ;
    }

    cout << Max ;

    return 0 ;
}
