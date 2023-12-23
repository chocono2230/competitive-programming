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
using mint = modint998244353;

int main() {
  int h, w;
  cin >> h >> w;
  dsu uf(h * w);
  auto fc = [&](int i, int j) { return i * w + j; };
  auto rfc = [&](int p) { return make_pair(p / w, p % w); };
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '.') continue;
    if (i != h - 1) {
      if (s.at(i + 1).at(j) == '#') {
        uf.merge(fc(i, j), fc(i + 1, j));
      }
    }
    if (j != w - 1) {
      if (s.at(i).at(j + 1) == '#') {
        uf.merge(fc(i, j), fc(i, j + 1));
      }
    }
  }
  int base = 0;
  auto grp = uf.groups();
  for (auto &v : grp) {
    int now = v.front();
    auto [i, j] = rfc(now);
    if (s.at(i).at(j) == '.') continue;
    base++;
  }
  mint co = 0, sum = 0;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '#') continue;
    co++;
    vector<pair<int, int>> p;
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '.') continue;
      bool f = true;
      for (auto [pi, pj] : p) {
        if (uf.same(fc(pi, pj), fc(ni, nj))) {
          f = false;
          break;
        }
      }
      if (f) p.push_back({ni, nj});
    }
    sum += base + 1 - p.size();
  }
  mint ans = sum / co;
  cout << ans.val() << endl;
  return 0;
}