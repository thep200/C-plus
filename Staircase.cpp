#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  int i = 1;
  cin >> n;

  int j = n - 1 ;
  while (j >= 0) {
    string s1(i, '#');
    string s2(j, ' ');
    cout << s2 << s1 << endl;
    j--;
    i++;
  }
}
