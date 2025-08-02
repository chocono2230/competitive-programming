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
  int q;
  cin >> q;
  while (q--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    vector<vector<int>> gr(n, vector<int>());
    rep(i, m) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      gr.at(a).push_back(b);
      gr.at(b).push_back(a);
    }
    rep(i, n) sort(ALL(gr.at(i)));
    vector<bool> table(n, false);
    vector<int> ans;
    auto rc = [&](const auto &self, int now) -> bool {
      table.at(now) = true;
      ans.push_back(now);
      if (now == y) return true;
      for (auto nx : gr.at(now)) {
        if (table.at(nx)) continue;
        auto r = self(self, nx);
        if (r) return true;
      }
      ans.pop_back();
      return false;
    };
    rc(rc, x);
    rep(i, ans.size()) {
      if (i != 0) cout << " ";
      cout << ans.at(i) + 1;
    }
    cout << endl;
  }
  return 0;
}