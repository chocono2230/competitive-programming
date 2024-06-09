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
  vector<int> edge(n);
  scc_graph sc(n);
  ll ans = 0;
  rep(i, n) {
    int in;
    cin >> in;
    in--;
    edge.at(i) = in;
    sc.add_edge(i, in);
  }
  auto grp = sc.scc();
  vector<ll> memo(n, -1);
  for (auto &v : grp) {
    if (v.size() == 1 && edge.at(v.front()) != v.front()) continue;
    ans += (ll)v.size() * v.size();
    for (auto now : v) {
      memo.at(now) = v.size();
    }
  }
  rep(i, n) {
    if (memo.at(i) != -1) continue;
    auto rc = [&](const auto &self, int now) -> ll {
      if (memo.at(now) != -1) return memo.at(now);
      int nx = edge.at(now);
      auto r = self(self, nx);
      memo.at(now) = r + 1;
      ans += memo.at(now);
      return memo.at(now);
    };
    rc(rc, i);
  }
  // rep(i, n) cerr << i + 1 << " " << memo.at(i) << endl;
  cout << ans << endl;
  return 0;
}