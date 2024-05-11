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
  vector<string> vs(n);
  rep(i, n) cin >> vs.at(i);
  sort(ALL(vs));
  ll ans = 0;
  auto rc = [&](const auto &self, int lv, int l, int r) -> void {
    if (r - l <= 1) return;
    // cerr << lv << " " << l << " " << r << endl;
    char now = 0;
    int p = -1;
    rep2(i, l, r) {
      if (vs.at(i).size() == lv) {
        continue;
      }
      if (now == 0) {
        now = vs.at(i).at(lv);
        p = i;
      }
      if (vs.at(i).at(lv) != now) {
        ll co = i - p;
        // cerr << co << endl;
        ans += co * (co - 1) / 2;
        self(self, lv + 1, p, i);
        now = vs.at(i).at(lv);
        p = i;
      }
    }
    if (p != -1) {
      ll co = r - p;
      // cerr << co << endl;
      ans += co * (co - 1) / 2;
      self(self, lv + 1, p, r);
    }
  };
  rc(rc, 0, 0, n);
  cout << ans << endl;
  return 0;
}