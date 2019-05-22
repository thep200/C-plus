#include <iostream>
#include <vector>
#include <math.h>
using namespace std ;

bool Process(vector <int> v)
        {
            const int Size = v.size() ;
            vector <int> v1 ;
            vector <int> v2 ;

            for(int i  = 0; i < Size; i++){
                if(i%2 == 0) v1.push_back(v[i]) ;
                else         v2.push_back(v[i]) ;
            }

            const int Size1 = v1.size() ;

            for(int i = 0; i < Size; i += 2){

                for(int j = 0; j < Size1; j++){

                        if(v1[j] == v[i] && v2[j] == v[i + 1]){
                        i += 2 ;

                        if(v1[j] == v[i] || v2[j] == v[i + 1]){
                            return true ;
                        }
                        else if(abs(v1[j] - v[i]) == abs(v2[j] - v[i + 1])){
                            return true ;
                        }

                    }
                }
            }

            return false ;
}

int main()
{
    vector <int> v = {1, 2, 1, 3, 2, 4, 3, 1} ;

    if(Process(v) == true) cout << "YES" ;
    else                       cout << "NO" ;


    return 0 ;
}
