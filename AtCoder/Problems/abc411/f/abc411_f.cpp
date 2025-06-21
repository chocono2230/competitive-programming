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
  int n, m;
  cin >> n >> m;
  vector gr(n, set<int>());
  vector<pair<int, int>> uv(m);
  rep(i, n) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr.at(u).insert(v);
    gr.at(v).insert(u);
    uv.at(i) = {u, v};
  }
  dsu uf(n);
  vector<int> ld(n);
  rep(i, n) ld.at(i) = i;
  int ans = m;
  int q;
  cin >> q;
  while (q--) {
    int in;
    cin >> in;
    in--;
    auto [u, v] = uv.at(in);
    if (uf.same(u, v)) {
      cout << ans << endl;
      continue;
    }
    int lu = ld.at(uf.leader(u));
    int lv = ld.at(uf.leader(v));
    if (gr.at(lu).size() < gr.at(lv).size()) {
      swap(u, v);
      swap(lu, lv);
    }
    uf.merge(u, v);
    ans -= (gr.at(lu).size() - 1);
    ans -= (gr.at(lv).size() - 1);
    ans -= 1;
    gr.at(lu).erase(v);
    for (auto nx : gr.at(lv)) {
      if (uf.same(u, nx)) continue;
      if (gr.at(lu).find(nx) != gr.at(lu).end()) {
        gr.at(nx).erase(v);
        continue;
      }
      gr.at(lu).insert(nx);
    }
    ans += gr.at(lu).size();
    ld.at(uf.leader(u)) = lu;
    cout << ans << endl;
  }
  return 0;
}