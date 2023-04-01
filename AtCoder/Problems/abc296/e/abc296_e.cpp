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
  vector<int> v(n);
  scc_graph gr(n);
  rep(i, n) {
    cin >> v.at(i);
    v.at(i)--;
    gr.add_edge(i, v.at(i));
  }
  auto gp = gr.scc();
  int ans = 0;
  for (auto &vv : gp) {
    if (vv.size() >= 2)
      ans += vv.size();
    else if (v.at(vv.front()) == vv.front()) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}