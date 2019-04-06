#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int Test(vector <int> v1, vector <int> v2)
{
     int dem = 0 ;

	 int size1 = v1.size() ;
	 int size2 = v2.size() ;

	 vector <int> :: iterator it1 = max_element(v1.begin(), v1.end()) ;
	 vector <int> :: iterator it2 = max_element(v2.begin(), v2.end()) ;

     while(*it1 <= *it2){
        int Count = 0 ;

        for(int i = 0; i < size1; i++){
            if((*it1)%v1[1] != 0) Count++ ;
            //cout << v1[i] ;
        }


        for(int i = 0; i < size2; i++){
            if(v2[i]%(*it1) != 0) Count++ ;

           // cout << v2[i] ;
        }

        if(Count == 0) dem++ ;

        (*it1)++ ;

        //cout << *it1 << "   " << *it2 << endl ;
     }
     return dem ;
}
int main()
{
    vector <int> v1 = {2, 4} ;
    vector <int> v2 = {16, 32, 96} ;

    cout << Test(v1, v2) ;
    return 0 ;
}
