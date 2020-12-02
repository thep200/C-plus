#include<iostream>
#include<string.h>
#include<time.h>
#include<cstdlib>
using namespace std ;
    int Run = 0 ;
    string NewGuess ;
    string guesseword ;
    string word ;
    char guess ;
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
    string s(n , '-') ;
    return s ;
}
const string Figues[] = {
         "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",


         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",


         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------      \n"
         "   |            \\    \n"
         "   |             O    \n"
         "   |            /|\\  \n"
         "   |            / \\  \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           /    \n"
         "   |          O     \n"
         "   |         /|\\   \n"
         "   |         / \\   \n"
         "   |     \n"
         " -----   \n",

         "   -------------      \n"
         "   |            \\    \n"
         "   |           (@.@)  \n"
         "   |             |    \n"
         "   |            /|\\  \n"
         "   |            / \\  \n"
         "   |     \n"
         " -----   \n"
};
/*bool Test(string guesseword)
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
}*/
void Prin_Lost(int Number)
{
    if(Number == 7){
        cout << endl << Figues[7] << "  " << Figues[8] << "  " << Figues[9] ;
        cout << "______You Lost_______" ;
    }
}
void Compare(char &guess , string &word)
{
    int n = word.length() ;
    int Count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(guess == word[i])
        {
            Count++ ;
        }
    }
    if(Count == 0)
    {
        Run++ ;
        cout << Figues[Run] << endl ;
        //cout << Runer << endl ;
    }
    else
    {
        cout << Figues[Run] << endl ;
        //cout << Runer << endl ;
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
void Play()
{
    word = Random() ;
    guesseword = MakeWord(word) ;
    cout << "Your Letter Is : " << guesseword << endl ;
    cout << "Enter The First Letter : " ;
    while(Run != 7)
    {
        cin >> guess ;
        Compare(guess , word) ;
        NewGuess = update(guesseword , word , guess) ;
        guesseword = NewGuess ;
        cout << "Your Letter Is : " << NewGuess << endl ;
        cout << "Enter The Next Letter : " ;
        Prin_Lost(Run) ;
        if(word == NewGuess){
            cout << "_____________You Win!_____________" << endl ;
            cout << "                        " << "Your choice YES or NO , please ?" << endl ;
            cout << "                        " << "Do you Want to Play Again ? :  " ;
            break ;
        }
    }
}
bool PlayAgain()
{
    string answer ;
    cin >> answer ;
    if(answer == "yes" ){
        return true ;
    }
    else{
        return false ;
    }
}
int main()
{
    cout << "********* Hangmen *********" << endl ;
    do{
        Play() ;
    }while(PlayAgain()) ;
    return 0 ;
}
