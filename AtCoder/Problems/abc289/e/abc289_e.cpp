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
  int t;
  cin >> t;
  vector tb(2005, vector<int>(2005, -1));
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i, n) cin >> c.at(i);
    vector gr(n, vector(2, vector<int>()));
    rep(i, m) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      int idx = (c.at(a) == c.at(b) ? 0 : 1);
      gr.at(a).at(idx).push_back(b);
      gr.at(b).at(idx).push_back(a);
    }
    if (c.front() == c.back()) {
      cout << -1 << endl;
      continue;
    }
    vector<pair<int, int>> use(0);
    queue<pair<int, int>> q;
    q.push({0, n - 1});
    tb.at(0).at(n - 1) = 0;
    use.push_back({0, n - 1});
    while (!q.empty()) {
      auto [a, b] = q.front();
      q.pop();
      rep(i, 2) {
        for (auto nx1 : gr.at(a).at(i)) {
          for (auto nx2 : gr.at(b).at(i)) {
            if (tb.at(nx1).at(nx2) != -1) continue;
            tb.at(nx1).at(nx2) = tb.at(a).at(b) + 1;
            use.push_back({nx1, nx2});
            q.push({nx1, nx2});
            if (nx1 == n - 1 && nx2 == 0) goto FIN;
          }
        }
      }
    }
  FIN:
    int ans = tb.at(n - 1).at(0);
    cout << ans << endl;
    for (auto [x, y] : use) {
      tb.at(x).at(y) = -1;
    }
  }
  return 0;
}