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
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  string t = "snuke";
  int di[] = {0, 0, 1, 1, 1, -1, -1, -1}, dj[] = {1, -1, 1, 0, -1, 1, 0, -1};
  rep(i, h) rep(j, w) rep(z, 8) {
    vector<pair<int, int>> v;
    int ni = i, nj = j;
    rep(k, 5) {
      if (s.at(ni).at(nj) != t.at(k)) {
        break;
      }
      v.push_back({ni, nj});
      ni += di[z];
      nj += dj[z];
      if (nj < 0 || w <= nj || ni < 0 || h <= ni) break;
    }
    if (v.size() == 5) {
      for (auto [a, b] : v) cout << a + 1 << " " << b + 1 << endl;
      return 0;
    }
  }
  return 0;
}