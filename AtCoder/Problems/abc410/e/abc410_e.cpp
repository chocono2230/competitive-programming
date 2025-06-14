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
  int n, h, m;
  cin >> n >> h >> m;
  vector<pair<int, int>> ab(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
  }
  const int INF = 1001001001;
  vector<int> base(h + 1, -INF);
  auto dp = base;
  dp.at(h) = m;
  rep(i, n) {
    auto [a, b] = ab.at(i);
    auto nxdp = base;
    rep(i, h + 1) {
      if (dp.at(i) < 0) continue;
      if (dp.at(i) >= b) {
        nxdp.at(i) = max(nxdp.at(i), dp.at(i) - b);
      }
      if (i < a) continue;
      nxdp.at(i - a) = max(nxdp.at(i - a), dp.at(i));
    }
    swap(dp, nxdp);
    bool f = false;
    rep(i, h + 1) {
      if (dp.at(i) >= 0) f = true;
    }
    if (!f) {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}