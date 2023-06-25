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
  auto in = []() -> tuple<vector<string>, int, int> {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s.at(i);
    auto rt = [](vector<string> &s) -> vector<string> {
      int h = s.size(), w = s.front().size();
      vector<string> res(w, string(h, '.'));
      rep(i, h) rep(j, w) { res.at(w - j - 1).at(i) = s.at(i).at(j); }
      return res;
    };
    rep(_i, 4) {
      int w = s.front().size();
      while (s.back() == string(w, '.')) {
        s.pop_back();
      }
      s = rt(s);
    }
    return {s, s.size(), s.front().size()};
  };
  auto [a, ah, aw] = in();
  auto [b, bh, bw] = in();
  auto [x, xh, xw] = in();
  rep(ai, xh) rep(aj, xw) rep(bi, xh) rep(bj, xw) {
    if (ai + ah > xh) continue;
    if (bi + bh > xh) continue;
    if (aj + aw > xw) continue;
    if (bj + bw > xw) continue;
    vector<string> t(xh, string(xw, '.'));
    rep(i, ah) rep(j, aw) {
      if (a.at(i).at(j) == '#') t.at(ai + i).at(aj + j) = '#';
    }
    rep(i, bh) rep(j, bw) {
      if (b.at(i).at(j) == '#') t.at(bi + i).at(bj + j) = '#';
    }
    if (t == x) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}