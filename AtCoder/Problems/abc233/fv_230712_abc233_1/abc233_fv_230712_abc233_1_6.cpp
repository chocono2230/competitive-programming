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
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  vector gr(n, vector<int>());
  map<pair<int, int>, int> edges;
  dsu uf(n);
  int m;
  cin >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.merge(a, b);
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
    edges[{a, b}] = i;
    edges[{b, a}] = i;
  }
  rep(i, n) {
    if (!uf.same(i, p.at(i))) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> ans;
  auto grp = uf.groups();
  for (auto &v : grp) {
    vector tree(n, vector<int>());
    vector<bool> cc(n, false);
    vector<int> deg(n, -1);
    auto dfs1 = [&](auto self, int now) -> void {
      cc.at(now) = true;
      deg.at(now) = 1;
      for (auto nx : gr.at(now)) {
        if (cc.at(nx)) continue;
        deg.at(now)++;
        tree.at(now).push_back(nx);
        tree.at(nx).push_back(now);
        self(self, nx);
      }
    };
    dfs1(dfs1, v.front());
    deg.at(v.front())--;

    vector<bool> ban(n, false);
    while (1) {
      int si = -1;
      for (auto now : v) {
        if (deg.at(now) == 1) {
          si = now;
          break;
        }
      }
      if (si == -1) break;

      auto remove_edge = [&]() {
        for (auto nx : tree.at(si)) {
          if (ban.at(nx)) continue;
          deg.at(nx)--;
        }
        ban.at(si) = true;
        deg.at(si) = 0;
      };

      if (p.at(si) == si) {
        remove_edge();
        continue;
      }

      vector<int> tb(n, -1);
      queue<int> q;
      q.push(si);
      int z = 0;
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (p.at(now) == si) {
          z = now;
          break;
        }
        for (auto nx : tree.at(now)) {
          if (tb.at(nx) != -1) continue;
          tb.at(nx) = now;
          q.push(nx);
        }
      }
      while (z != si) {
        int nx = tb.at(z);
        swap(p.at(z), p.at(nx));
        ans.push_back(edges[{z, nx}]);
        z = nx;
      }
      remove_edge();
    }
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}