#include <iostream>
#include <fstream>
using namespace std ;
int main()
{
    string line ;

    ifstream File ;
    File.open("abc.txt") ;
    while(!File.eof()){
        getline(File, line) ;    // cách đọc File theo từng dòng một

        cout << line << endl  ;
    }

    File.close() ;


    ----------------------------
    char c ;

    ifstream File ;
    File.open("abc.txt") ;
    while(!File.eof()){
        File.get(c) ;    // cách đọc File theo từng từ một

        cout << c << endl  ;
    }

    File.close() ;

    return 0 ;
}
