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
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> r(n);
  rep(i, n) r.at(i) = l - a.at(i);
  const ll INF = 1e18;
  r.push_back(INF);
  r.push_back(-INF);
  sort(ALL(r));
  ll ans = INF;
  rep(i, n) {
    auto itr = lower_bound(ALL(r), a.at(i));
    auto previt = prev(itr);
    ans = min(ans, 2LL * l + 2 * abs(*itr - a.at(i)));
    ans = min(ans, 2LL * l + 2 * abs(*previt - a.at(i)));
  }
  cout << ans << endl;
  return 0;
}