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

int n;
vector<pair<int, int>> pt;
int M = 840;

int main() {
  int x, y;
  cin >> n >> x >> y;
  pt.resize(n - 1);
  rep(i, n - 1) cin >> pt.at(i).first >> pt.at(i).second;

  vector dp(n - 1, vector<ll>(M, 0));
  rrep(i, n - 1) {
    auto [p, t] = pt.at(i);
    rep(j, M) {
      ll add = t;
      int nj = j;
      if (j % p != 0) {
        add += p - (j % p);
        nj += p - (j % p);
      }
      if (i != n - 2) add += dp.at(i + 1).at((nj + t) % M);
      dp.at(i).at(j) = add;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    ll st;
    cin >> st;
    st += x;
    ll r = dp.at(0).at(st % M);
    ll ans = st + r + y;
    cout << ans << endl;
  }
  return 0;
}