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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector vv(3, vector<int>(3, 0));
  string s;
  cin >> s;
  vector dp(n + 1, vector(3, vector<ll>(1 << 3, 0)));
  auto ff = [](char x) -> int {
    if (x == 'E') return 1;
    if (x == 'X') return 2;
    return 0;
  };
  auto f2 = [](int x) -> int {
    if (x == 1) return 2;
    if (x == 2) return 4;
    return 1;
  };
  rep(i, n) {
    int ni = i + 1;
    rep(j, 3) rep(k, 1 << 3) dp.at(ni).at(j).at(k) += dp.at(i).at(j).at(k);
    int idx = ff(s.at(i));
    int idx2 = f2(a.at(i));
    if (idx == 0) {
      dp.at(ni).at(idx).at(idx2)++;
      continue;
    }
    rep(k, 1 << 3) {
      int nxk = (k | idx2);
      dp.at(ni).at(idx).at(nxk) += dp.at(i).at(idx - 1).at(k);
    }
  }
  ll ans = 0;
  rep(k, 1 << 3) {
    if (k % 2 == 0) continue;
    if ((k & (1 << 1)) == 0) {
      ans += dp.back().back().at(k);
      continue;
    }
    if ((k & (1 << 2)) == 0) {
      ans += dp.back().back().at(k) * 2;
      continue;
    }
    ans += dp.back().back().at(k) * 3;
  }
  cout << ans << endl;
  return 0;
}