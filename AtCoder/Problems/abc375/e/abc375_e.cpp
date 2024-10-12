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
  vector<pair<int, int>> ab(n);
  int sum = 0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    ab.at(i) = {a, b};
    sum += b;
  }
  if (sum % 3 != 0) {
    cout << -1 << endl;
    return 0;
  }
  int ta = sum / 3;
  const int INF = 1001001001;
  vector base(ta + 1, vector<int>(ta + 1, INF));
  auto dp = base;
  dp.at(0).at(0) = 0;
  int nwsum = 0;
  for (auto [a, b] : ab) {
    nwsum += b;
    auto nxdp = base;
    rep(i, ta + 1) rep(j, ta + 1) {
      if (dp.at(i).at(j) == INF) continue;
      rep(k, 3) {
        int ni = i, nj = j;
        int add = 1;
        if (k == a) add = 0;
        if (k == 0) ni += b;
        if (k == 1) nj += b;
        if (ni > ta || nj > ta || nwsum - ni - nj > ta) continue;
        nxdp.at(ni).at(nj) = min(nxdp.at(ni).at(nj), dp.at(i).at(j) + add);
      }
    }
    swap(dp, nxdp);
  }
  int ans = dp.back().back();
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}