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
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  vector dp(h, vector(w, vector(2, vector<bool>(2, false))));
  auto ff = [&](int x) -> void {
    rep(p, 2) {
      rep(z, 2) {
        rep(j, w) {
          if (j != 0 && a.at(x).at(j - 1) == a.at(x).at(j))
            dp.at(x).at(j).at(z).at(p) = true;
          if (j != w - 1 && a.at(x).at(j + 1) == a.at(x).at(j))
            dp.at(x).at(j).at(z).at(p) = true;
        }
      }
    }
  };
  ff(0);
  vector gr(h, vector(2, vector(2, vector(2, false))));
  rep2(i, 1, h) {
    rep(x, 2) rep(y, 2) rep(z, 2) {}
  }
  return 0;
}