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
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  vector<int> a(n);
  rep(i, n) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  map<int, int> mp;
  for (auto i : a) mp[i % m]++;
  int mn = 1001001001;
  int st = -1;
  rep(i, m) {
    if (mp.find(i) == mp.end()) {
      mn = 0;
      st = i;
      break;
    }
    mn = min(mn, mp[i]);
  }
  if (mn != 0) {
    cout << 0 << endl;
    return 0;
  }

  auto itr = mp.lower_bound(st);
  int bf = (st - 1 + m) % m;
  if (itr == mp.end()) {
    itr = mp.lower_bound(0);
  }
  ll ans = 0, add = 0;
  int co = 0;
  while (1) {
    if (itr->first != (bf + 1) % m) {
      ans = max(ans, add);
      add = 0;
    }
    add += (ll)itr->first * itr->second;
    bf = itr->first;
    itr++;
    if (itr == mp.end()) {
      itr = mp.begin();
      co++;
      if (co == 2) break;
    }
  }
  cout << sum - ans << endl;
  return 0;
}