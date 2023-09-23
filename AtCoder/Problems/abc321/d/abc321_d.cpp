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
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  sort(ALL(b));
  vector<ll> bs(m + 1, 0);
  rep(i, m) bs.at(i + 1) = bs.at(i) + b.at(i);
  ll ans = 0;
  rep(i, n) {
    int ta = p - a.at(i);
    int idx = lower_bound(ALL(b), ta) - b.begin();
    ll add = bs.at(idx);
    add += (ll)idx * a.at(i);
    add += (ll)p * (m - idx);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}