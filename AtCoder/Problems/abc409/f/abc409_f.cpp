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
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> xy;
  dsu uf(4000);
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      qe;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    rep(j, xy.size()) {
      auto [x1, y1] = xy.at(j);
      qe.push({abs(x1 - x) + abs(y1 - y), i, j});
    }
    xy.push_back({x, y});
  }
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, y;
      cin >> x >> y;
      rep(j, xy.size()) {
        auto [x1, y1] = xy.at(j);
        qe.push({abs(x1 - x) + abs(y1 - y), xy.size(), j});
      }
      xy.push_back({x, y});
    }
    if (mode == 2) {
      int mn = -1;
      while (!qe.empty()) {
        auto [c, i, j] = qe.top();
        if (mn != -1 && c > mn) break;
        qe.pop();
        if (uf.same(i, j)) continue;
        mn = c;
        uf.merge(i, j);
      }
      cout << mn << endl;
    }
    if (mode == 3) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (uf.same(u, v))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }

  return 0;
}