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
  int n, t;
  cin >> n >> t;
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);
  vector<int> r(n);
  rep(i, n) cin >> r.at(i);
  int mx = 0, mxi = -1;
  rep(i, n) {
    if (c.at(i) == t) {
      if (mx < r.at(i)) {
        mx = r.at(i);
        mxi = i;
      }
    }
  }
  if (mxi == -1) {
    t = c.front();
    rep(i, n) {
      if (c.at(i) == t) {
        if (mx < r.at(i)) {
          mx = r.at(i);
          mxi = i;
        }
      }
    }
  }
  cout << mxi + 1 << endl;
  return 0;
}