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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  dsu uf(n);
  vector gr(n, vector<pair<int, int>>());
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    uf.merge(u, v);
    gr.at(u).push_back({v, i});
    gr.at(v).push_back({u, i});
  }
  auto grp = uf.groups();
  int mx = 0;
  for (auto &v : grp) {
    mx += v.size() / 2 * 2;
  }
  if (k > mx || k % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  vector<bool> used(n, false);
  vector<int> lp(n, 0);
  vector<int> ans;
  int nk = 0;
  auto fc = [&](int st) {
    auto dfs = [&](const auto &self, int now, int bf, int bi) -> void {
      used.at(now) = true;
      for (auto [nx, i] : gr.at(now)) {
        if (used.at(nx)) continue;
        self(self, nx, now, i);
      }
      if (nk == k) return;
      if (lp.at(now) == 0 && bf != -1) {
        nk -= lp.at(now) + lp.at(bf);
        lp.at(now) ^= 1;
        lp.at(bf) ^= 1;
        nk += lp.at(now) + lp.at(bf);
        ans.push_back(bi);
      }
    };
    dfs(dfs, st, -1, -1);
  };
  rep(i, n) {
    if (used.at(i)) continue;
    fc(i);
    if (nk == k) {
      cout << ans.size() << endl;
      rep(i, ans.size()) {
        if (i != 0) cout << " ";
        cout << ans.at(i) + 1;
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}