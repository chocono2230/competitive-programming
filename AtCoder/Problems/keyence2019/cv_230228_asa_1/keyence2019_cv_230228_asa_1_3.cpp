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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  ll as = reduce(ALL(a), 0LL), bs = reduce(ALL(b), 0LL);
  if (bs > as) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> v(n);
  rep(i, n) { v.at(i) = a.at(i) - b.at(i); }
  // for (auto i : v) cerr << i << " ";
  // cerr << endl;
  sort(ALL(v));
  ll ms = 0;
  int ans = 0;
  rep(i, v.size()) {
    if (v.at(i) >= 0) break;
    ms += -v.at(i);
    ans++;
  }
  rrep(i, v.size()) {
    if (ms <= 0) break;
    ans++;
    ms -= v.at(i);
  }
  cout << ans << endl;
  return 0;
}