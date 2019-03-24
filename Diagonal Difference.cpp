#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int sum1 = 0, sum2 = 0;
  int n;
  cin >> n;
  int a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    sum1 += a[i][i];
  }

  int i = n - 1;
  int j = 0;
  while (i >= 0) {
    sum2 += a[i][j];
    i--;
    j++;
  }

  cout << abs(sum1 - sum2);
  return 0;
}
