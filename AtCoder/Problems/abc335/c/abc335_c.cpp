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
  vector<pair<int, int>> t;
  int i = 1, j = 0;
  t.push_back({i, j});
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      char c;
      cin >> c;
      if (c == 'R') i++;
      if (c == 'L') i--;
      if (c == 'U') j++;
      if (c == 'D') j--;
      t.push_back({i, j});
    } else {
      int p;
      cin >> p;
      p--;
      int idx = t.size() - 1 - p;
      // cerr << idx << endl;
      int ai = 0, aj = 0;
      if (idx >= 0) {
        auto [x, y] = t.at(idx);
        ai = x, aj = y;
      } else {
        ai = -idx + 1;
      }
      cout << ai << " " << aj << endl;
    }
  }
  return 0;
}