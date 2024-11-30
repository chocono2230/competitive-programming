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
  int n, m;
  cin >> n >> m;
  vector<int> v;
  vector ans(0, vector<int>());
  auto rc = [&](const auto &self, int now) -> bool {
    if (now > m) return false;
    v.push_back(now);
    if (v.size() == n) {
      ans.push_back(v);
      v.pop_back();
      return true;
    }
    int nx = now + 10;
    bool res = false;
    while (1) {
      auto r = self(self, nx);
      res |= r;
      if (!r) break;
      nx++;
    }
    v.pop_back();
    return res;
  };
  rep2(i, 1, m + 1) {
    auto r = rc(rc, i);
    if (!r) break;
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    rep(j, n) {
      if (j != 0) cout << " ";
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
  return 0;
}