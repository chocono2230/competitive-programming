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

int main() {
  int n, m;
  cin >> n >> m;
  const ll INF = 1e18;
  vector gr(n + 1, vector<ll>(n + 1, INF));
  rep(i, n + 1) gr.at(i).at(i) = 0;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).at(b) = gr.at(b).at(a) = min(gr.at(a).at(b), (ll)c);
  }
  int k, t;
  cin >> k >> t;
  rep(i, k) {
    int in;
    cin >> in;
    in--;
    gr.at(in).at(n) = t;
    gr.at(n).at(in) = 0;
  }
  rep(k, n + 1) rep(i, n + 1) rep(j, n + 1) gr.at(i).at(j) =
      min(gr.at(i).at(j), gr.at(i).at(k) + gr.at(k).at(j));
  // rep(i, n + 1) {
  //   rep(j, n + 1) cerr << (gr.at(i).at(j) == INF ? -1 : gr.at(i).at(j)) << "
  //   "; cerr << endl;
  // }
  int q;
  cin >> q;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, y, t;
      cin >> x >> y >> t;
      x--;
      y--;
      gr.at(x).at(y) = gr.at(y).at(x) = min(gr.at(x).at(y), (ll)t);
      rep(i, n + 1) rep(j, n + 1) gr.at(i).at(j) =
          min(gr.at(i).at(j), gr.at(i).at(x) + gr.at(x).at(j));
      rep(i, n + 1) rep(j, n + 1) gr.at(i).at(j) =
          min(gr.at(i).at(j), gr.at(i).at(y) + gr.at(y).at(j));
    }
    if (mode == 2) {
      int x;
      cin >> x;
      x--;
      gr.at(x).at(n) = t;
      gr.at(n).at(x) = 0;
      rep(i, n + 1) rep(j, n + 1) gr.at(i).at(j) =
          min(gr.at(i).at(j), gr.at(i).at(x) + gr.at(x).at(j));
      rep(i, n + 1) rep(j, n + 1) gr.at(i).at(j) =
          min(gr.at(i).at(j), gr.at(i).at(n) + gr.at(n).at(j));
    }
    if (mode == 3) {
      ll ans = 0;
      rep(i, n) rep(j, n) {
        if (gr.at(i).at(j) == INF) continue;
        ans += gr.at(i).at(j);
      }
      cout << ans << endl;
    }
  }
  return 0;
}