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
  vector<tuple<int, int, int>> v;
  int zz = -1, mn2 = 1001001, mn3 = 1001001;
  for (auto now : a) {
    int p2 = 0, p3 = 0;
    while (now % 2 == 0) {
      p2++;
      now /= 2;
    }
    while (now % 3 == 0) {
      p3++;
      now /= 3;
    }
    v.push_back({p2, p3, now});
    if (zz == -1)
      zz = now;
    else {
      if (now != zz) {
        cout << -1 << endl;
        return 0;
      }
    }
    mn2 = min(mn2, p2);
    mn3 = min(mn3, p3);
  }
  ll ans = 0;
  for (auto [a, b, c] : v) {
    ans += a - mn2;
    ans += b - mn3;
  }
  cout << ans << endl;
  return 0;
}