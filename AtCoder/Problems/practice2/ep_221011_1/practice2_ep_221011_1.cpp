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
  int n, k;
  cin >> n >> k;
  vector a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a.at(i).at(j);
  mcf_graph<int, ll> mcf(2 * n + 2);
  int s = 2 * n, t = 2 * n + 1;
  const ll INF = 1001001001;

  mcf.add_edge(s, t, n * k, INF);
  rep(i, n) {
    mcf.add_edge(s, i, k, 0);
    mcf.add_edge(n + i, t, k, 0);
  }
  rep(i, n) rep(j, n) { mcf.add_edge(i, n + j, 1, INF - a.at(i).at(j)); }
  cout << INF * n * k - mcf.flow(s, t, n * k).second << endl;

  auto v = mcf.edges();
  vector<string> ans(n, string(n, '.'));
  for (auto e : v) {
    if (e.from == s || e.to == t || e.flow == 0) continue;
    ans.at(e.from).at(e.to - n) = 'X';
  }
  for (auto o : ans) cout << o << endl;
  return 0;
}