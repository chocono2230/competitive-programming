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
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  map<ll, int> mp;
  mp[0]++;
  ll now = 0;
  ll ans = 0;
  for (auto add : a) {
    now += add;
    ll ta = now - k;
    ans += mp[ta];
    mp[now]++;
  }
  cout << ans << endl;
  return 0;
}