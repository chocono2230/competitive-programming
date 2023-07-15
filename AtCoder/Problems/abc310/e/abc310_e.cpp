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
  string s;
  cin >> s;
  ll ans = 0;
  vector<int> base(2, 0);
  auto dp = base;
  for (auto c : s) {
    int now = (c - '0');
    auto nxdp = base;
    if (now == 0) {
      nxdp.at(1) = dp.at(0) + dp.at(1);
    } else {
      nxdp.at(1) = dp.at(0);
      nxdp.at(0) = dp.at(1);
    }
    nxdp.at(now)++;
    ans += nxdp.at(1);
    swap(dp, nxdp);
  }
  cout << ans << endl;
  return 0;
}