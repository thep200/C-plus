#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int processing(vector <int> &v , int &n)
{
    int x ;
    for(int i = 0; i < n; i++){
        cin >> x ;
        v.push_back(x) ;
    }

    int Count1 = 0 ;
    sort(v.begin(), v.end()) ;
    for(int i = 0; i < n; i++){
        if(v[i] != v[i + 1]){
            int k = count(v.begin(), v.end(), v[i]) ;
            Count1 += k/2 ;
        }
    }

    return Count1 ;
}


int main()
{
    int n ;
    vector <int> v ;
    cin >> n ;
    cout << processing(v, n) ;
    return 0 ;


}
