#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ok = 0, ng = 1001001001;
    while (ng - ok > 1) {
      ll mid = (ok + ng) / 2;
      auto r = [&]() {
        ll pa = a - mid, pb = b, pc = c - mid;
        if (pa < 0 || pc < 0) return false;
        ll s = pa + pb + pc;
        return s >= mid;
      }();
      if (r)
        ok = mid;
      else
        ng = mid;
    }
    cout << ok << endl;
  }
  return 0;
}