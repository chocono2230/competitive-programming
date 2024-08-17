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
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  rep(i, n) cin >> r.at(i);
  vector ans(0, vector<int>());
  vector<int> now;
  auto rc = [&](const auto &self, int lv, int sum) -> void {
    if (lv == n) {
      if (sum % k == 0) ans.push_back(now);
      return;
    }
    rep2(i, 1, r.at(lv) + 1) {
      now.push_back(i);
      self(self, lv + 1, sum + i);
      now.pop_back();
    }
  };
  rc(rc, 0, 0);
  sort(ALL(ans));
  for (auto &v : ans) {
    rep(i, v.size()) {
      if (i != 0) cout << " ";
      cout << v.at(i);
    }
    cout << endl;
  }
  return 0;
}