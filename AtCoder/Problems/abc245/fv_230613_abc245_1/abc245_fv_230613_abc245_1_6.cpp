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

bool dfs(vector<vector<int>> &gr, vector<bool> &chk, vector<bool> &ss,
         int now) {
  int res = false;
  for (auto nx : gr.at(now)) {
    if (ss.at(nx)) {
      res = true;
      break;
    }
    if (chk.at(nx)) continue;
    chk.at(nx) = true;
    auto r = dfs(gr, chk, ss, nx);
    res |= r;
  }
  return ss.at(now) = res;
}

int main() {
  int n, m;
  cin >> n >> m;
  scc_graph gr(n);
  vector gg(n, vector<int>());
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr.add_edge(u, v);
    gg.at(u).push_back(v);
  }
  auto scc = gr.scc();

  vector<bool> ss(n, false);
  vector<bool> chk(n, false);
  for (auto &v : scc) {
    if (v.size() == 1) continue;
    for (auto i : v) ss.at(i) = true;
  }
  rep(i, n) {
    if (!ss.at(i) && !chk.at(i)) dfs(gg, chk, ss, i);
  }
  int ans = 0;
  rep(i, n) if (ss.at(i)) ans++;
  cout << ans << endl;

  return 0;
}