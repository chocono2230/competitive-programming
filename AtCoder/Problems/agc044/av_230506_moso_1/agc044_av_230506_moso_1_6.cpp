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
ll c, d;
ll n, a, b;

ll fc(ll now, bool flg = false) {
  static map<ll, ll> memo;
  if (flg) {
    memo.clear();
    return 0;
  }
  if (now <= 1) return abs(now) * d;
  if (memo.find(now) != memo.end()) return memo[now];
  ll res = 8e18;
  if (now < LLONG_MAX / d) res = now * d;
  if (now % 2 == 0)
    res = min(res, fc(now / 2) + a);
  else {
    res = min({res, fc((now + 1) / 2) + a + d, fc((now - 1) / 2) + a + d});
  }
  rep(add, 3) {
    if ((now + add) % 3 == 0) res = min(res, fc((now + add) / 3) + b + d * add);
    if (now - add > 0 && (now - add) % 3 == 0)
      res = min(res, fc((now - add) / 3) + b + d * add);
  }
  rep(add, 5) {
    if ((now + add) % 5 == 0) res = min(res, fc((now + add) / 5) + c + d * add);
    if (now - add > 0 && (now - add) % 5 == 0)
      res = min(res, fc((now - add) / 5) + c + d * add);
  }
  return memo[now] = res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    cin >> c >> d;
    fc(0, true);
    cout << fc(n) << endl;
  }
  return 0;
}