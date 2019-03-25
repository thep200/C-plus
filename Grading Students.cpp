
#include <cmath>
#include <iostream>
using namespace  std ;
int main() {
  size_t n, tmp_grade;
  cin >> n;
  while (n--) {
    cin >> tmp_grade;
    if (tmp_grade >= 38 && tmp_grade % 5 > 2)
      tmp_grade += 5 - (tmp_grade % 5);
            cout << tmp_grade << '\n';
  }

  return 0;
}
