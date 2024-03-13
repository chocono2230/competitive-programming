#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<multiset<int>> box(n);
  vector<set<int>> nums(200005);
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int i, j;
      cin >> i >> j;
      i--;
      j--;
      box.at(j).insert(i);
      nums.at(i).insert(j);
    } else if (mode == 2) {
      int i;
      cin >> i;
      i--;
      bool f = false;
      for (auto now : box.at(i)) {
        if (f) cout << " ";
        cout << now + 1;
        f = true;
      }
      cout << endl;
    } else {
      int i;
      cin >> i;
      i--;
      bool f = false;
      for (auto now : nums.at(i)) {
        if (f) cout << " ";
        cout << now + 1;
        f = true;
      }
      cout << endl;
    }
  }
  return 0;
}