#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  int x;
  cin >> n;
  int COunt1 = 0;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int Max = v[0];

  for (int i = 0; i < n; i++) {
    int k = count(v.begin(), v.end(), v[i]);
    if (k >= COunt1 && v[i] < Max) {
      COunt1 = k;
      Max = v[i];
    }
    // cout << v[i] << "    " << k <<endl ;
  }
  cout << Max;
  return 0;
}
