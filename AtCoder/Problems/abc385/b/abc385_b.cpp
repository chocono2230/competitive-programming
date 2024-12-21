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
  int h, w;
  cin >> h >> w;
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  string t;
  cin >> t;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  vector table(h, vector<bool>(w, false));
  table.at(x).at(y) = true;
  for (auto c : t) {
    auto ss = [&]() {
      if (c == 'D') return 0;
      if (c == 'R') return 1;
      if (c == 'U') return 2;
      return 3;
    };
    int idx = ss();
    int ni = x + di[idx], nj = y + dj[idx];
    if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
    if (s.at(ni).at(nj) == '#') continue;
    table.at(ni).at(nj) = true;
    x = ni;
    y = nj;
  }
  int ans = 0;
  rep(i, h) rep(j, w) {
    if (table.at(i).at(j) && s.at(i).at(j) == '@') ans++;
  }
  cout << x + 1 << " " << y + 1 << " " << ans << endl;
  return 0;
}