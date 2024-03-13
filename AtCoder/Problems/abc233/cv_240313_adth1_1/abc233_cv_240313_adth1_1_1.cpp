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
  ll n, x;
  cin >> n >> x;
  map<ll, ll> base;
  auto dp = base;
  dp[1] = 1;
  rep(i, n) {
    int sz;
    cin >> sz;
    auto nxdp = base;
    rep(_i, sz) {
      int in;
      cin >> in;
      for (auto p : dp) {
        if (p.first > LLONG_MAX / in || in * p.first > x) break;
        nxdp[p.first * in] += p.second;
      }
    }
    swap(dp, nxdp);
  }
  cout << dp[x] << endl;
  return 0;
}