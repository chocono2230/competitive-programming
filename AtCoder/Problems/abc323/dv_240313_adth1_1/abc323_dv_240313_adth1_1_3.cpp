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
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    int s, c;
    cin >> s >> c;
    mp[s] = c;
  }
  ll ans = 0;
  while (!mp.empty()) {
    auto itr = mp.begin();
    if (itr->second > 1) {
      mp[itr->first * 2] += itr->second / 2;
      itr->second %= 2;
    }
    ans += itr->second;
    mp.erase(itr);
  }
  cout << ans << endl;
  return 0;
}