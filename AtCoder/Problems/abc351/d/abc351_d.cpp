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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int h, w;
  cin >> h >> w;
  dsu uf(h * w);
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  auto chk = [&](int i, int j) {
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '#') return false;
    }
    return true;
  };
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '#' || !chk(i, j)) continue;
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '#') continue;
      if (chk(ni, nj)) uf.merge(i * w + j, ni * w + nj);
    }
  }
  int ans = 0;
  auto grp = uf.groups();
  for (auto &v : grp) {
    int add = 0;
    set<pair<int, int>> se;
    for (auto nm : v) {
      int i = nm / w, j = nm % w;
      if (s.at(i).at(j) == '#') break;
      add++;
      if (!chk(i, j)) continue;
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (s.at(ni).at(nj) == '#') continue;
        if (!uf.same(nm, ni * w + nj)) se.insert({ni, nj});
      }
    }
    add += se.size();
    // cerr << v.front() << " " << add << endl;
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}