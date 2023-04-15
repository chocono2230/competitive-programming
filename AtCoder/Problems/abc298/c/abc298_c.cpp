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
  vector<multiset<int>> s1(200005);
  vector<set<int>> s2(200005);
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, y;
      cin >> x >> y;
      s1.at(y).insert(x);
      s2.at(x).insert(y);
    }
    if (mode == 2) {
      int x;
      cin >> x;
      bool f = false;
      for (auto o : s1.at(x)) {
        if (f) cout << " ";
        cout << o;
        f = true;
      }
      cout << endl;
    }
    if (mode == 3) {
      int x;
      cin >> x;
      bool f = false;
      for (auto o : s2.at(x)) {
        if (f) cout << " ";
        cout << o;
        f = true;
      }
      cout << endl;
    }
  }
  return 0;
}