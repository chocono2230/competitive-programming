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

void dfs(vector<vector<tuple<int, int, int>>> &tree, vector<vector<int>> &par,
         vector<int> &lv, vector<ll> &dist, vector<pair<int, int>> &event,
         int now) {
  event.push_back({0, now});
  for (auto [nx, cost, idx] : tree.at(now)) {
    if (lv.at(nx) != -1) continue;
    lv.at(nx) = lv.at(now) + 1;
    par.at(0).at(nx) = now;
    dist.at(nx) = dist.at(now) + cost;
    event.push_back({1, idx});
    dfs(tree, par, lv, dist, event, nx);
    event.push_back({2, idx});
  }
}

int lca(vector<int> &dlv, vector<vector<int>> &par, int u, int v) {
  const int SZ = 30;
  if (dlv.at(u) < dlv.at(v)) swap(u, v);
  rep(i, SZ) {
    if (((dlv.at(u) - dlv.at(v)) & (1 << i)) != 0) {
      u = par.at(i).at(u);
    }
  }
  if (u == v) return u;
  rrep(i, SZ) {
    if (par.at(i).at(u) != par.at(i).at(v)) {
      u = par.at(i).at(u);
      v = par.at(i).at(v);
    }
  }
  return par.at(0).at(u);
}

int main() {
  int n;
  cin >> n;
  vector gr(n, vector<tuple<int, int, int>>());
  vector<int> edge(n - 1);
  rep(i, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).push_back({b, c, i});
    gr.at(b).push_back({a, c, i});
    edge.at(i) = c;
  }

  vector<int> lv(n, -1);
  vector<ll> dist(n, -1);
  vector par(30, vector<int>(n, -1));
  vector<pair<int, int>> event;
  lv.at(0) = 0;
  dist.at(0) = 0;
  dfs(gr, par, lv, dist, event, 0);
  map<int, pair<int, int>> edge_idx;
  map<int, int> var_idx;
  rep(i, event.size()) {
    auto [mode, idx] = event.at(i);
    if (mode == 0) {
      var_idx[idx] = i;
    }
    if (mode == 1) {
      edge_idx[idx].first = i;
    }
    if (mode == 2) {
      edge_idx[idx].second = i;
    }
  }

  rep(i, 29) {
    rep(now, n) {
      if (par.at(i).at(now) < 0)
        par.at(i + 1).at(now) = -1;
      else
        par.at(i + 1).at(now) = par.at(i).at(par.at(i).at(now));
    }
  }
  fenwick_tree<ll> fw(event.size());

  int q;
  cin >> q;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int idx, w;
      cin >> idx >> w;
      idx--;
      int d = w - edge.at(idx);
      auto [f, s] = edge_idx[idx];
      fw.add(f, d);
      fw.add(s, -d);
      edge.at(idx) = w;
    } else {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      int lc = lca(lv, par, u, v);
      ll d = dist.at(u) + dist.at(v) - 2 * dist.at(lc);
      auto fc = [&](int idx) -> ll {
        int p = var_idx[idx];
        return fw.sum(0, p);
      };
      d += fc(u) + fc(v) - 2 * fc(lc);
      cout << d << endl;
    }
  }

  return 0;
}