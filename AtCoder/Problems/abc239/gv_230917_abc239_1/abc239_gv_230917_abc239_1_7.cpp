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
  mf_graph<ll> gr(n * 2);
  const ll INF = 1e18;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.add_edge(a, b + n, INF);
    gr.add_edge(b, a + n, INF);
  }
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);
  rep2(i, 1, n - 1) { gr.add_edge(i + n, i, c.at(i)); }
  ll cc = gr.flow(0, 2 * n - 1);
  cout << cc << endl;
  vector<int> ans;
  auto mc = gr.min_cut(0);
  rep2(i, 1, n - 1) {
    if (mc.at(i + n) && !mc.at(i)) ans.push_back(i);
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}