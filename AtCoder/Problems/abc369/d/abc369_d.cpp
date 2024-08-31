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
  const ll INF = 1e18;
  vector dp(n + 1, vector<ll>(2, -INF));
  dp.at(0).at(0) = 0;
  rep(i, n) {
    rep(j, 2) {
      dp.at(i + 1).at(j) = max(dp.at(i + 1).at(j), dp.at(i).at(j));
      int nj = 1 - j;
      ll add = a.at(i);
      if (j == 1) add += a.at(i);
      dp.at(i + 1).at(nj) = max(dp.at(i + 1).at(nj), dp.at(i).at(j) + add);
    }
  }
  cout << max(dp.back().at(0), dp.back().at(1)) << endl;
  return 0;
}