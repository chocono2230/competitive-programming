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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> e, o;
  rep(i, n) {
    if (i % 2 == 0)
      e.push_back(a.at(i));
    else
      o.push_back(a.at(i));
  }
  auto fc = [](vector<int> &e, int x, bool f = false) -> bool {
    int sz = 20005;
    int c = sz / 2;
    vector<bool> dp(sz, false);
    dp.at(c) = true;
    rep(j, e.size()) {
      vector<bool> nxdp(sz, false);
      set<int> t;
      rep(i, dp.size()) {
        if (!dp.at(i)) continue;
        int ni = i - e.at(j);
        if (ni >= 0) {
          if (!f || j != 0) {
            nxdp.at(ni) = true;
            t.insert(ni);
          }
        }
        ni = i + e.at(j);
        if (ni < sz) {
          nxdp.at(ni) = true;
          t.insert(ni);
        }
      }
      // cerr << e.at(j) << " : ";
      // for (auto k : t) cerr << k - c << " ";
      // cerr << endl;
      swap(nxdp, dp);
    }
    return dp.at(c + x);
  };
  if (fc(e, x, true) && fc(o, y))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}