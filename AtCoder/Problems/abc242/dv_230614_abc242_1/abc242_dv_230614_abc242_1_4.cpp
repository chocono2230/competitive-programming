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
  const string base = "ABC";
  string s;
  cin >> s;
  int q;
  cin >> q;
  while (q--) {
    ll t, k;
    cin >> t >> k;
    int ng = 0, ok = s.size();
    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      auto fc = [&]() -> bool {
        if (t > 60) return false;
        ll p = 1LL << t;
        if (mid > LLONG_MAX / p) return false;
        ll co = mid * p;
        return co < k;
      };
      if (fc())
        ng = mid;
      else
        ok = mid;
    }

    auto fc = [&](int x) -> bool {
      ll zz = t;
      ll y = k - 1;
      while (zz > 0) {
        int nx = (x - 1 + 3) % 3;
        if (y % 2 == 1) nx = (x + 1) % 3;
        x = nx;
        y /= 2;
        zz--;
        if (y == 0) {
          zz %= 3;
        }
      }
      return base.at(x) == s.at(ng);
    };
    int ans = -1;
    rep(i, 3) if (fc(i)) { ans = i; }
    cout << base.at(ans) << endl;
  }
  return 0;
}