#include <iostream>
#include <string>
using namespace std;
int convert(string s)
{
    int k = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if((int)s[i] < '0' || (int)s[i] > '9')
        {
            throw "Invalid" ;
        }
        else
        {
            k *= 10 ;
            k += ( (int)s[i] - '0' ) ;
        }
    }
    return k ;
}
int main()
{
    string s ;
    getline(cin , s) ;
    try
    {
        cout << convert(s) ;
    }
    catch(const char *m)
    {
        cerr << m ;
    }
    return 0 ;
}
















