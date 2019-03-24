#include<iostream>
#include<string.h>
#include<time.h>
#include<cstdlib>
using namespace std ;
string Random()
{
    string SaveWord[] = {"google" , "random" , "technology" , "function" , "programer"} ;
    srand(time(0)) ;
    int i = (rand()  %5 + 1) ;
    return SaveWord[i] ;
}
string MakeWord(string word)
{
    int n = word.length() ;
    string s(n , '_') ;
    return s ;
}
bool Test(string guesseword)
{
    int Count = 0 ;
    int n = guesseword.length() ;
    for(int i = 0 ; i < n ; i++){
        if(guesseword[i] == '_')
            {
                Count++ ;
            }
    }
    if(Count != 0)
            return true ;
        else
            {
                cout << "_____You Win_____ !" ;
                return false ;
            }
}
string update(string guesseword , string word , char guess)
{
    int Count = word.length() ;
    for(int i = 0 ; i < Count ; i++){
        if(word[i] == guess)
            guesseword[i] = guess ;
    }
    return guesseword ;
}
int main()
{
    cout << "********* Hangmang *********" << endl ;
    string NewGuess ;
    string guesseword ;
    string word ;
    char guess ;
    word = Random() ;
    guesseword = MakeWord(word) ;
    cout << "Your Letter Is : " << guesseword << endl ;
    cout << "Enter The First Letter : " ;
    do{
        cin >> guess ;
        NewGuess = update(guesseword , word , guess) ;
        guesseword = NewGuess ;
        cout << "Your Letter Is : " << NewGuess << endl ;
        cout << "Enter The Next Letter : " ;
    }while(Test(NewGuess)) ;
    return 0 ;
}
