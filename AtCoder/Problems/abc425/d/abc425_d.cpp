#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  vector tb(h, vector<int>(w, -1));
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '#') tb.at(i).at(j) = 0;
  }
  queue<pair<int, int>> base;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  rep(i, h) rep(j, w) {
    if (tb.at(i).at(j) != 0) continue;
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      base.push({ni, nj});
    }
  }

  while (!base.empty()) {
    vector<pair<int, int>> upd;
    while (!base.empty()) {
      auto [i, j] = base.front();
      base.pop();
      int co = 0;
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (tb.at(ni).at(nj) != -1) co++;
      }
      if (co == 1) upd.push_back({i, j});
    }
    vector<pair<int, int>> uq;
    for (auto [i, j] : upd) {
      if (tb.at(i).at(j) != -1) continue;
      tb.at(i).at(j) = 0;
      uq.push_back({i, j});
    }
    for (auto [i, j] : uq) {
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (tb.at(ni).at(nj) != -1) continue;
        base.push({ni, nj});
      }
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) if (tb.at(i).at(j) != -1) ans++;
  cout << ans << endl;
  return 0;
}