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
  vector tree(n, vector<int>());
  rep(i, n - 1) {
    int in;
    cin >> in;
    in--;
    tree.at(in).push_back(i + 1);
  }
  vector<int> d(n, -1);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    d.at(x) = max(d.at(x), y);
  }

  int ans = 0;
  auto dfs = [&](auto self, int now, int p) -> void {
    p = max(p, d.at(now));
    if (p >= 0) ans++;
    for (auto nx : tree.at(now)) {
      self(self, nx, p - 1);
    }
  };
  dfs(dfs, 0, -1);
  cout << ans << endl;
  return 0;
}