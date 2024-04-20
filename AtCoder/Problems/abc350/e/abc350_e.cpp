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
  ll n, a, x, y;
  cin >> n >> a >> x >> y;
  map<ll, double> memo;
  auto rc = [&](const auto &self, ll now) -> double {
    if (now == 0) return 0;
    auto itr = memo.find(now);
    if (itr != memo.end()) return itr->second;
    double mn = x + self(self, now / a);
    double add = 0;
    rep(i, 5) { add += self(self, now / (i + 2)) / 5.0; }
    add += y * 6.0 / 5.0;
    // cerr << now << " " << mn << " " << add << endl;
    mn = min(mn, add);
    return memo[now] = mn;
  };
  cout << fixed << setprecision(10) << rc(rc, n) << endl;
  return 0;
}