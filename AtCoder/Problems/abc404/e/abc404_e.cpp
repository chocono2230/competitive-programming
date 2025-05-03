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
  vector<int> c(n - 1);
  rep(i, n - 1) cin >> c.at(i);
  vector<int> a(n - 1);
  rep(i, n - 1) cin >> a.at(i);
  const int INF = 1001001001;
  vector<int> dp(n - 1, INF);
  dp.at(0) = 1;
  rep2(i, 1, n - 1) {
    int now = INF;
    int ni = i;
    rep(j, c.at(i)) {
      ni--;
      if (ni == -1) {
        now = 1;
        break;
      }
      if (a.at(ni) > 0) {
        now = dp.at(ni) + 1;
        break;
      }
      now = min(now, dp.at(ni) + 1);
    }
    dp.at(i) = now;
  }
  int ans = INF;
  rrep(i, n - 1) {
    if (a.at(i) != 0) {
      ans = dp.at(i);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}