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
  ll n;
  cin >> n;
  map<ll, ll> mp;
  auto fc = [&](const auto &self, ll now) -> ll {
    if (mp.find(now) != mp.end()) {
      return mp[now];
    }
    if (now < 2) return 0;
    ll res = now;
    res += self(self, now / 2);
    res += self(self, (now + 1) / 2);
    return mp[now] = res;
  };
  cout << fc(fc, n) << endl;
  return 0;
}