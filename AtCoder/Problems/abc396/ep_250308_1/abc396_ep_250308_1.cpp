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
  vector gr(n, vector<pair<int, int>>());
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).push_back({b, c});
    gr.at(b).push_back({a, c});
  }
  vector<int> ans(n, 0);
  rep(bit, 30) {
    vector<bool> chk(n, false);
    vector<bool> flg(n, false);
    rep(i, n) {
      if (chk.at(i)) continue;
      vector<int> v;
      auto rc = [&](const auto &self, int now) -> bool {
        chk.at(now) = true;
        v.push_back(now);
        for (auto [nx, z] : gr.at(now)) {
          bool zf = ((z & (1 << bit)) != 0);
          if (chk.at(nx)) {
            if ((flg.at(now) ^ zf) == flg.at(nx)) continue;
            return false;
          }
          flg.at(nx) = (flg.at(now) ^ zf);
          if (!self(self, nx)) return false;
        }
        return true;
      };
      auto r = rc(rc, i);
      if (!r) {
        cout << -1 << endl;
        return 0;
      }
      int pc = 0, nc = 0;
      for (auto now : v) {
        if (flg.at(now))
          pc++;
        else
          nc++;
      }
      for (auto now : v) {
        if (flg.at(now) ^ (nc < pc)) ans.at(now) |= (1 << bit);
      }
    }
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}