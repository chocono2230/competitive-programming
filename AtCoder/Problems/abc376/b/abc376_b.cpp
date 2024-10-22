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
  int n, q;
  cin >> n >> q;
  int l = 0, r = 1;
  int ans = 0;
  rep(i, q) {
    char h;
    int t;
    cin >> h >> t;
    t--;
    auto fc = [&](int x, int y, int ta, int d) {
      int res = 0;
      if (x == ta) return 0;
      while (1) {
        x = (x + d + n) % n;
        if (x == y) return 1001;
        res++;
        if (x == ta) return res;
      }
      return 0;
    };
    if (h == 'L') {
      ans += min(fc(l, r, t, 1), fc(l, r, t, -1));
      l = t;
    } else {
      ans += min(fc(r, l, t, 1), fc(r, l, t, -1));
      r = t;
    }
  }
  cout << ans << endl;
  return 0;
}