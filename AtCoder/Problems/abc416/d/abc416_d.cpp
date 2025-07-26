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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);
    vector<ll> b(n);
    rep(i, n) cin >> b.at(i);
    sort(ALL(a));
    sort(ALL(b));
    int co = 0;
    int li = 0;
    rrep(i, n) {
      while (li != n) {
        if (a.at(li) + b.at(i) >= m) {
          co++;
          li++;
          break;
        }
        li++;
      }
    }
    ll ans = reduce(ALL(a)) + reduce(ALL(b));
    ans -= (ll)co * m;
    cout << ans << endl;
  }
  return 0;
}