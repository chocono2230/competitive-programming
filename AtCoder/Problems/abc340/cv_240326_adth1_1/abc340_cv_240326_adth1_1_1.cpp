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
  auto fc = [&](const auto &self, ll x) -> ll {
    if (mp.find(x) != mp.end()) return mp[x];
    if (x <= 1) return 0;
    ll res = self(self, x / 2) + self(self, (x + 1) / 2);
    return mp[x] = res + x;
  };
  cout << fc(fc, n) << endl;
  return 0;
}