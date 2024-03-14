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
  vector dp(n + 1, vector<double>(6, 0));
  rrep(i, 6) dp.back().at(i) = i + 1;
  rrep(i, n) {
    rep(j, 6) {
      double mx = j + 1;
      double add = 0;
      rep(k, 6) { add += dp.at(i + 1).at(k) / 6.0; }
      dp.at(i).at(j) = max(mx, add);
    }
  }
  cout << fixed << setprecision(10) << dp.front().front() << endl;
  return 0;
}