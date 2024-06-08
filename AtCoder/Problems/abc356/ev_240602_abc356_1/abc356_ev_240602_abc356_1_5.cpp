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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int sz = 1000005;
  fenwick_tree<int> fw(sz);
  map<int, int> mp;
  rep(i, n) mp[a.at(i)]++;
  ll ans = 0;
  rrep(now, sz) {
    if (mp.find(now) == mp.end()) continue;
    int q = mp[now];
    int l = now, r = now * 2;
    int add = 1;
    while (1) {
      ll co = fw.sum(l, min(r, sz));
      ans += co * add * q;
      add++;
      l = r;
      r += now;
      if (l >= sz) break;
    }
    ans += (ll)q * (q - 1) / 2;
    fw.add(now, q);
  }
  cout << ans << endl;
  return 0;
}