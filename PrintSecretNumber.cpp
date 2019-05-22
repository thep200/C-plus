#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

class Number{
public:
    vector <int> v1 ;
    vector <int> v2 ;

    Number(vector <int> v1 = {1, 2, 4, 3, 5, 6}, vector <int> v2 = {4, 2, 3, 1, 5, 6, 7}) ;

    int PrintSecretNumber() ;

};

Number :: Number(vector <int> v1, vector <int> v2)
{
    this -> v1 = v1 ;
    this -> v2 = v2 ;
}

int Number :: PrintSecretNumber()
{
    const int Size1 = v1.size() ;

    for(int i = 0; i < Size1; i++){
        v2.push_back(v1[i]) ;
    }

    const int Size2 = v2.size() ;
    sort(v2.begin(),v2.end()) ;

    for(int i = 0 ;i < Size2; i++){
        if(v2[i] != v2[i + 1]){
            int TakeNumber = count(v2.begin(), v2.end(), v2[i]) ;
            if(TakeNumber == 1){
                return v2[i] ;
            }
        }
    }
}


int PrintSecretNumber(vector <int> v1, vector <int> v2) ;

int main()
{
    Number N ;
    cout << N.PrintSecretNumber() ;
    return 0 ;
}

