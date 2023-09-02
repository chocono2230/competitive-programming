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
  int n, d, p;
  cin >> n >> d >> p;
  vector<int> f(n);
  rep(i, n) cin >> f.at(i);
  sort(ALL(f), greater<int>());
  ll ans = 0;
  int idx = 0;
  while (1) {
    if (idx >= n) break;
    ll sum = 0;
    rep(i, d) {
      if (idx + i >= n) break;
      sum += f.at(idx + i);
    }
    if (sum > p) {
      ans += p;
      idx += d;
    } else
      break;
  }
  while (idx < n) {
    ans += f.at(idx++);
  }
  cout << ans << endl;
  return 0;
}