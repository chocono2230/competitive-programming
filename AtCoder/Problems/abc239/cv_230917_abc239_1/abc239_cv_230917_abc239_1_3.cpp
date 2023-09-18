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
  int x1, y1;
  cin >> x1 >> y1;
  int x2, y2;
  cin >> x2 >> y2;
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  auto fc = [](int x, int y) {
    set<pair<int, int>> se;
    rep2(dx, -2, 3) rep2(dy, -2, 3) {
      if (abs(dx) == 0 || abs(dy) == 0) continue;
      if (abs(dx) == 1 && abs(dy) == 2 || abs(dx) == 2 && abs(dy) == 1) {
        int px = x + dx;
        int py = y + dy;
        se.insert({px, py});
      }
    }
    return se;
  };
  auto s1 = fc(x1, y1), s2 = fc(x2, y2);
  for (auto [p, q] : s1) {
    if (s2.find({p, q}) != s2.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}