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
  vector tree(n, vector<pair<int, int>>());
  rep(i, n - 1) {
    int u, v, l;
    cin >> u >> v >> l;
    u--;
    v--;
    tree.at(u).push_back({v, l});
    tree.at(v).push_back({u, l});
  }
  vector<ll> ans;
  vector<ll> memo(n, -1);
  vector<ll> per(n, -1);
  vector<bool> del(n, false);
  set<pair<ll, int>> se;
  auto dfs = [&](const auto &self, int now, int bf, ll cost) -> void {
    per.at(now) = bf;
    for (auto [nx, l] : tree.at(now)) {
      if (nx == bf) continue;
      self(self, nx, now, cost + l);
    }
    memo.at(now) = cost;
    if (tree.at(now).size() == 1) se.insert({cost, now});
  };
  dfs(dfs, 0, -1, 0);
  ll tot = 0;
  int dbg = 0;
  int p = se.size();
  rep(pp, p) {
    auto itr = se.end();
    itr--;
    tot += itr->first;
    int pos = itr->second;
    int bf = -1;
    while (pos != 0) {
      del.at(pos) = true;
      for (auto [nx, l] : tree.at(pos)) {
        if (nx == per.at(pos)) continue;
        if (nx == bf) continue;
        auto dfs = [&](const auto &self, int now, int bf, ll cost) -> void {
          per.at(now) = bf;
          for (auto [nx, l] : tree.at(now)) {
            if (nx == bf) continue;
            self(self, nx, now, cost + l);
          }
          ll pm = memo.at(now);
          memo.at(now) = cost;
          if (tree.at(now).size() == 1) {
            se.erase({pm, now});
            se.insert({cost, now});
          }
        };
        dfs(dfs, nx, pos, l);
        per.at(nx) = 0;
      }
      bf = pos;
      pos = per.at(pos);
    }
    ans.push_back(tot * 2);
    se.erase(itr);
  }
  while (ans.size() != n) ans.push_back(ans.back());
  for (auto now : ans) cout << now << endl;
  return 0;
}