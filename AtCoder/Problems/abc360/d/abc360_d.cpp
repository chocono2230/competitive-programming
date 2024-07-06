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
  ll t;
  cin >> n >> t;
  string s;
  cin >> s;
  vector<ll> x(n);
  rep(i, n) cin >> x.at(i);
  vector<pair<ll, int>> q;
  rep(i, n) {
    if (s.at(i) == '1') {
      q.push_back({x.at(i), 0});
      q.push_back({x.at(i) + 2 * t, 2});
    } else {
      q.push_back({x.at(i), 1});
    }
  }
  sort(ALL(q));
  int now = 0;
  ll ans = 0;
  for (auto [idx, e] : q) {
    if (e == 0) {
      now++;
    }
    if (e == 1) {
      ans += now;
    }
    if (e == 2) {
      now--;
    }
  }
  cout << ans << endl;
  return 0;
}