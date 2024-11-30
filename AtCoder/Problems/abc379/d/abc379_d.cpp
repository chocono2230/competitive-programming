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
  int q;
  cin >> q;
  multiset<ll> se;
  ll now = 0;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      se.insert(now);
    }
    if (mode == 2) {
      int t;
      cin >> t;
      now += t;
    }
    if (mode == 3) {
      ll h;
      cin >> h;
      int ans = 0;
      while (!se.empty()) {
        auto itr = se.begin();
        if (now - *itr >= h) {
          ans++;
          se.erase(itr);
        } else
          break;
      }
      cout << ans << endl;
    }
  }
  return 0;
}