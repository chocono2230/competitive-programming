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
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  const int INF = 1001001001;
  vector mv(l, vector<int>());
  rep(i, n) { mv.at(i % l).push_back(a.at(i)); }
  vector cost(l, vector<int>(m, 0));
  rep(i, l) {
    rep(j, m) {
      int sum = 0;
      for (auto now : mv.at(i)) {
        if (j >= now)
          sum += j - now;
        else
          sum += j + m - now;
      }
      cost.at(i).at(j) = sum;
    }
  }
  vector dp(l + 1, vector<int>(m, INF));
  dp.at(0).at(0) = 0;
  rep(i, l) rep(j, m) rep(k, m) {
    int ni = i + 1;
    int nj = (j + k) % m;
    dp.at(ni).at(nj) = min(dp.at(ni).at(nj), dp.at(i).at(j) + cost.at(i).at(k));
  }
  cout << dp.back().at(0) << endl;
  return 0;
}