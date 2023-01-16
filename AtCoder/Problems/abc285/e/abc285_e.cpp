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
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> v(n + 1, 0);
  int idx = 0;
  ll s = 0;
  rep2(i, 2, n + 1) {
    if (i % 2 == 1) s += a.at(idx++);
    ll add = s * 2;
    if (i % 2 == 0) add += a.at(idx);
    v.at(i) = add;
  }
  // rep(i, n + 1) cerr << v.at(i) << " ";
  // cerr << endl;
  const ll INF = 1e18;
  vector<ll> dp(n + 1, -INF);
  dp.front() = 0;
  rep(i, n) {
    rep2(j, 1, n + 1) {
      if (i + j > n) break;
      int ni = i + j;
      dp.at(ni) = max(dp.at(ni), dp.at(i) + v.at(j));
    }
  }
  // rep(i, n + 1) cerr << dp.at(i) << " ";
  // cerr << endl;
  cout << dp.back() << endl;
  return 0;
}