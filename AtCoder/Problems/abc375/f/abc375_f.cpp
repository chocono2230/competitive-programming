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
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int>> abc(m);
  vector<int> use(m, q);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    abc.at(i) = {a, b, c};
  }
  vector<tuple<int, int, int>> query(q);
  rep(i, q) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int in;
      cin >> in;
      in--;
      query.at(i) = {1, in, 0};
      use.at(in) = i;
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      query.at(i) = {2, x, y};
    }
  }

  const ll INF = 1e18;
  vector gr(n, vector<ll>(n, INF));
  rep(i, n) { gr.at(i).at(i) = 0; }
  rep(i, m) {
    if (use.at(i) == q) {
      auto [a, b, c] = abc.at(i);
      gr.at(a).at(b) = gr.at(b).at(a) = min(gr.at(a).at(b), (ll)c);
    }
  }
  rep(k, n) rep(i, n) rep(j, n) gr.at(i).at(j) =
      min(gr.at(i).at(j), gr.at(i).at(k) + gr.at(k).at(j));
  vector<ll> ans;
  rrep(i, q) {
    auto [x, y, z] = query.at(i);
    if (x == 1) {
      auto [a, b, c] = abc.at(y);
      if (c >= gr.at(a).at(b)) continue;
      gr.at(a).at(b) = gr.at(b).at(a) = c;
      rep(i, n) rep(j, n) {
        gr.at(i).at(j) =
            min(gr.at(i).at(j), gr.at(i).at(a) + c + gr.at(b).at(j));
      }
      rep(i, n) rep(j, n) {
        gr.at(i).at(j) =
            min(gr.at(i).at(j), gr.at(i).at(b) + c + gr.at(a).at(j));
      }
    } else {
      ans.push_back(gr.at(y).at(z) == INF ? -1 : gr.at(y).at(z));
    }
  }
  reverse(ALL(ans));
  for (auto o : ans) cout << o << endl;
  return 0;
}