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
  vector wl(n, vector<int>(n, 0));
  rep(i, m) {
    int w, l;
    cin >> w >> l;
    w--;
    l--;
    wl.at(w).at(l) = 1;
    wl.at(l).at(w) = 2;
  }
  vector t(n, vector<int>(n, 0));
  int co = 0;
  rep(i, n) rep2(j, i + 1, n) { t.at(i).at(j) = t.at(j).at(i) = co++; }

  vector<int> ans;
  int nn = n * (n - 1) / 2;
  rep(now, n) {
    mf_graph<int> gr(2 + nn + n);
    rep(i, nn) { gr.add_edge(0, 2 + i, 1); }
    int w = 0;
    rep(i, n) rep(j, n) {
      if (i == j) continue;
      int z = t.at(i).at(j);
      int flg = wl.at(i).at(j);
      if (i == now && flg == 0) flg = 1;
      if (j == now && flg == 0) flg = 2;
      if (flg <= 1) {
        gr.add_edge(2 + z, 2 + nn + i, 1);
      }
      if (i == now && flg == 1) w++;
    }
    if (w == 0) continue;
    rep(i, n) {
      if (i == now) {
        rep(co, w) { gr.add_edge(2 + nn + i, 1, 1); }
      } else {
        rep(co, w - 1) { gr.add_edge(2 + nn + i, 1, 1); }
      }
    }
    int r = gr.flow(0, 1);
    if (r == nn) ans.push_back(now);
  }

  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}