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
  int n, m, q;
  cin >> n >> m >> q;
  vector<set<int>> vv(n + 1, set<int>());
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, y;
      cin >> x >> y;
      vv.at(x).insert(y);
    }
    if (mode == 2) {
      int x;
      cin >> x;
      vv.at(x).insert(-1);
    }
    if (mode == 3) {
      int x, y;
      cin >> x >> y;
      auto &s = vv.at(x);
      if (s.find(-1) != s.end() || s.find(y) != s.end())
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}