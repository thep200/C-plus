#include <iostream>
#include <fstream>
#include <time.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std ;
vector <string> save_2 ;      // lưu từ được chọn bất kỳ vào
vector <char> save_1 ;        // lưu những chữ cái đã được nhập vào từ bàn phím
//vector <int> save_0 ;
int Run = 0 ;               // con chạy để in hình vẽ tương ứng
char Standardized(char &word)   // chuẩn hóa cho ký tự vào từ bàn phím
{
    if(word <= 'Z' && word >= 'A'){
        word = char(word + 32) ;
    }
    return word ;
}
string Random_word()            // lấy một từ bất kỳ trong file txt
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
    save_2.push_back(SaveWord[i]) ;
    return SaveWord[i] ;
}
string MakeWord(string word)        // chuyển từ được chọn trong file txt thành dấu "-"
{
    int n = word.length() ;
    string s(n , '-') ;
    return s ;
}
const string Figues_win[] = {                   // biểu tượng chiến thắng

      "   -------------      \n"
         "   |  W               \n"
         "   |                  \n"
         "   |        I         \n"
         "   |                  \n"
         "   |             N    \n"
         "   |     \n"
         " -----   \n",

         "   -------------      \n"
         "   |              W   \n"
         "   |                  \n"
         "   |        I         \n"
         "   |                  \n"
         "   |  N               \n"
         "   |     \n"
         " -----   \n",

         "   -------------      \n"
         "   |        W    ^_^  \n"
         "   |                  \n"
         "   |        I    ^.^  \n"
         "   |                  \n"
         "   |        N  (CMNR) \n"
         "   |     \n"
         " -----   \n"
};
const string Figues_lost[] = {                  // giá treo cổ lắc lư
"   -------------      \n"
         "   |            \\    \n"
         "   |             O--- \n"
         "   |            /|\\  \n"
         "   |            / \\  \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           /    \n"
         "   |       ---O     \n"
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
const string Figues[] = {               // vẽ hình xuất hiện khi nhập ký tự vào

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
void Prin_Lost(int Number)          // làm giá treo cổ lắc lư khi thua
{
    if(Number == 7){
        int i = 0 ;
        while(i < 3){
            for(int i = 0 ; i < 50 ; i++)
                cout << endl ;
                cout << Figues_lost[i] ;
                i++ ;
                this_thread :: sleep_for(chrono :: milliseconds(700)) ;
        }
        cout << "______You Lost_______"  << endl ;
        cout << "Word Computer is : " << save_2[0] << endl ; // trả đáp án cho người chơi khi họ thua cuộc
        save_2.clear() ;
        save_1.clear() ;
       // save_0.clear() ;
    }

}
void Prin_win()                 // vẽ biểu tượng sau khi chiến thắng
{
    int i = 0 ;
    while(i < 3){
        for(int i = 0 ; i < 50 ; i++)
            cout << endl ;
            cout << Figues_win[i] ;
            i++ ;
            this_thread :: sleep_for(chrono :: milliseconds(500)) ;
    }
    cout << "_____________You Win!_____________" << endl ;
            cout << "                        " << "Your choice YES or NO , please ?" << endl ;
            cout << "                        " << "Do you Want to Play Again ? :  " ;
      save_2.clear() ;
      save_1.clear() ;
     // save_0.clear() ;
}
void limited_Compare (char &guess , string &word )      // giới hạn một chữ cái chỉ được nhập vào một lần duy nhất
{                                                       // đồng thời in tiếp hình tiếp theo ra màn hình
    int n = save_1.size() ;
    int n1 = word.length() ;
    int Count = 0 ;
    int Count1 = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(guess == save_1[i]){
            Count++ ;
        }
    }
      for(int i = 0 ; i < n1 ; i++){
        if(guess == word[i]){
            Count1++ ;
        }
    }
    if(Count1 != 0){
        if(Count == 0){
            cout << Figues[Run] << endl ;
            save_1.push_back(guess) ;
        }
        else{
            Run++ ;
            cout << Figues[Run] << endl ;
        }
    }
    else{
            Run++ ;
            cout << Figues[Run] << endl ;
    }
    //save_0.push_back(Run) ;
}
/*void My_Scores ()
{
    int n = save_0.size() ;
    int scores ;
    for(int i = 0 ; i < n ; i++){
       scores = 9999 - save_0[i]*399 ;
    }
    cout << endl << scores ;
}*/
string update(string guesseword , string word , char guess)     // với mỗi từ nhập đúng sẽ thay ký tự ẩn bằng chữ cái đó
{
    int Count = word.length() ;
    for(int i = 0 ; i < Count ; i++){
        if(word[i] == guess)
            guesseword[i] = guess ;
    }
    return guesseword ;
}
void Play()     // hàm tổng để nhập vào và chơi game
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
        limited_Compare(guess , word) ;
        NewGuess = update(guesseword , word , guess) ;
        guesseword = NewGuess ;
        cout << "Your Letter Is : " << NewGuess << endl ;
        cout << "Enter The Next Letter : " ;
        Prin_Lost(Run) ;
        if(word == NewGuess)
        {
            Run = 0 ;
            Prin_win() ;
            break ;
        }
    }
   // My_Scores() ;
}
bool PlayAgain()        // nhận câu trả lời và xử lý để biết chơi tiếp hay không
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
