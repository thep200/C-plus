#include <fstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std ;
int Run = 0 ;
char Standardized(char &word)
{
    if(word <= 'Z' && word >= 'A'){
        word = char(word + 32) ;
    }
    return word ;
}
string Random_word()
{
    vector <string> SaveWord ;
    int Random_size ;
    string line ;
    ifstream myfile ("saveword.txt") ;
    if(myfile.is_open()){
        while(getline(myfile , line)){
            SaveWord.push_back(line) ;
        }
    myfile.close() ;
    }
    Random_size = SaveWord.size() - 1 ;
    srand(time(0)) ;
    int i = (rand() %Random_size + 1) ;
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


         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",

};
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
    }
    else
    {
        cout << Figues[Run] << endl ;
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
    char guess ;
    string word ;
    string NewGuess ;
    string guesseword ;
    word = Random_word() ;
    guesseword = MakeWord(word) ;
    cout << "Your Letter Is : " << guesseword << endl ;
    cout << "Enter The First Letter : " ;
    while(Run != 7)
    {
        cin >> guess ;
        guess = Standardized(guess) ;
        Compare(guess , word) ;
        NewGuess = update(guesseword , word , guess) ;
        guesseword = NewGuess ;
        cout << "Your Letter Is : " << NewGuess << endl ;
        cout << "Enter The Next Letter : " ;
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
    int n = answer.length() ;
    for(int i = 0 ; i < n ; i++){
        Standardized(answer[i]) ;
    }
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
