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
  int n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> xy(n);
  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  map<tuple<ll, ll, ll>, int> mp;
  rep(i, n) rep2(j, i + 1, n) {
    auto p = xy.at(i);
    auto q = xy.at(j);
    ll dx = q.first - p.first, dy = q.second - p.second;
    if (dx < 0) {
      dx *= -1;
      dy *= -1;
    }
    if (dx == 0) {
      dy = 1;
    } else {
      ll g = gcd(dx, dy);
      dx /= g;
      dy /= g;
    }
    ll c = dx * p.second - dy * p.first;
    mp[{dx, dy, c}]++;
  }
  int ans = 0;
  for (auto p : mp) {
    if (p.second >= k * (k - 1) / 2) ans++;
  }
  cout << ans << endl;

  return 0;
}