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
  string s, t;
  cin >> s >> t;
  vector<int> gr(26, -1);
  scc_graph scc(26);
  rep(i, n) {
    int p = s.at(i) - 'a';
    int q = t.at(i) - 'a';
    if (gr.at(p) != -1) {
      if (gr.at(p) != q) {
        cout << -1 << endl;
        return 0;
      }
      continue;
    }
    gr.at(p) = q;
    scc.add_edge(p, q);
  }

  int ans = 0;
  bool emp = false;
  rep(i, 26) {
    if (gr.at(i) == -1) emp = true;
  }
  auto ss = scc.scc();
  bool z = false;
  for (auto p : ss) {
    if (p.size() != 1) {
      bool x = false;
      rep(i, 26) {
        if (find(ALL(p), i) != p.end()) continue;
        int nx = gr.at(i);
        if (nx == -1) continue;
        if (find(ALL(p), nx) != p.end()) {
          emp = true;
          x = true;
          break;
        }
      }
      if (x) continue;
      z = true;
      ans++;
    } else if (gr.at(p.front()) != -1 && gr.at(p.front()) != p.front())
      emp = true;
  }
  if (z && !emp) {
    cout << -1 << endl;
    return 0;
  }
  rep(i, 26) {
    if (gr.at(i) != -1 && gr.at(i) != i) ans++;
  }
  cout << ans << endl;
  return 0;
}