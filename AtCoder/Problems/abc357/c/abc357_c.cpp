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
  int n;
  cin >> n;
  vector<string> ans;
  int pw = 1;
  rep(i, n) pw *= 3;
  ans.resize(pw);
  rep(i, pw) { ans.at(i) = string(pw, '.'); }
  auto rc = [&](const auto &self, int lv, int npw, int i, int j) -> void {
    if (lv == 0) {
      ans.at(i).at(j) = '#';
      return;
    }
    rep(di, 3) rep(dj, 3) {
      if (di == 1 && dj == 1) continue;
      self(self, lv - 1, npw / 3, i + di * npw, j + dj * npw);
    }
    rep(pi, npw) rep(pj, npw) { ans.at(i + npw + pi).at(j + npw + pj) = '.'; }
  };
  rc(rc, n, pw / 3, 0, 0);
  for (auto s : ans) cout << s << endl;
  return 0;
}