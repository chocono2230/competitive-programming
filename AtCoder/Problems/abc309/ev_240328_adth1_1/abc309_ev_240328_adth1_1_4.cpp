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
  vector ad(n, -1);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    ad.at(x) = max(ad.at(x), y);
  }
  int ans = 0;
  auto rc = [&](const auto &self, int now, int co) -> void {
    co = max(co, ad.at(now));
    if (co > -1) {
      ans++;
      co--;
    }
    for (auto nx : tree.at(now)) {
      self(self, nx, co);
    }
  };
  rc(rc, 0, -1);
  cout << ans << endl;
  return 0;
}