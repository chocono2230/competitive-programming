#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a));
  rep(i, q) {
    int x, y;
    cin >> x >> y;
    ll ok = x, ng = 2001001001;
    int base = upper_bound(ALL(a), x - 1) - a.begin();
    while (ng - ok > 1) {
      ll mid = (ok + ng) / 2;
      auto fc = [&]() {
        int co = upper_bound(ALL(a), (int)mid - 1) - a.begin();
        ll p = mid - (x - 1) - (co - base);
        // cerr << x << " " << mid << " " << p << " " << co << endl;
        return p <= y;
      };
      if (fc())
        ok = mid;
      else
        ng = mid;
    }
    // cerr << base << endl;
    cout << ok << endl;
  }
  return 0;
}