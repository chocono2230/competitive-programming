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
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<ll> dp(n, 0);
  ll ans = 0;
  auto rc = [&](const auto &self, int now, int pr) -> void {
    if (pr == -1) {
      self(self, tree.at(now).front(), now);
      return;
    }
    vector<int> nxv;
    for (auto nx : tree.at(now)) {
      if (nx == pr) continue;
      nxv.push_back(nx);
      self(self, nx, now);
      dp.at(now) += dp.at(nx);
    }
    if (nxv.size() == 0 || nxv.size() > 2) {
      dp.at(now) = 0;
      return;
    }
    ll add = 0;
    if (nxv.size() == 1) {
      if (tree.at(nxv.front()).size() == 2)
        add = 0;
      else
        add = dp.at(now);
      dp.at(now) = 1;
    } else {
      add = dp.at(nxv.front()) * dp.at(nxv.back());
    }
    ans += add;
  };
  rep(i, n) {
    if (tree.at(i).size() == 1) {
      rc(rc, i, -1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}