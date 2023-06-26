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
  int n, x;
  cin >> n >> x;
  auto base = vector<bool>(x + 1, false);
  auto dp = base;
  dp.front() = true;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    auto nxdp = base;
    rep(i, dp.size()) {
      if (!dp.at(i)) continue;
      if (i + a <= x) nxdp.at(i + a) = true;
      if (i + b <= x) nxdp.at(i + b) = true;
    }
    swap(dp, nxdp);
  }
  if (dp.back())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}