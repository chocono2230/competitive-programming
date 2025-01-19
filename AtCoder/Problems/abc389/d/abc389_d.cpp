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
  int r;
  cin >> r;
  ll ans = (r - 1) * 2 + 1;
  rep2(i, 1, r) {
    int ok = -1, ng = r;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      auto fc = [&]() { return hypot(mid + 0.5, i + 0.5) < r; };
      if (fc())
        ok = mid;
      else
        ng = mid;
    }
    // cerr << i << " " << ok << endl;
    if (ok >= 0) {
      ll add = 1;
      add += ok * 2;
      ans += add * 2;
    }
  }
  cout << ans << endl;
  return 0;
}