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
  vector<int> q(n);
  rep(i, n) cin >> q.at(i);
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  int ans = 0;
  rep(ac, 1000005) {
    bool f = false;
    int bc = 10000000;
    rep(i, n) {
      ll nxb = q.at(i) - (ll)a.at(i) * ac;
      if (nxb < 0) {
        f = true;
        break;
      }
      if (b.at(i) == 0) continue;
      bc = min((ll)bc, nxb / b.at(i));
    }
    // cerr << ac << " " << f << endl;
    if (f) break;
    ans = max(ans, ac + bc);
  }
  cout << ans << endl;
  return 0;
}