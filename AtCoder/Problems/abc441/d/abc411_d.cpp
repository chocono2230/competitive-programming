#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int l, s, t;
  cin >> l >> s >> t;
  vector gr(n, vector<pair<int, int>>());
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).push_back({b, c});
  }

  vector<bool> ans(n, false);
  auto rc = [&](const auto &self, int now, ll sum, int lv) -> void {
    if (lv == l) {
      if (s <= sum && sum <= t) {
        ans.at(now) = true;
      }
      return;
    }
    for (auto [nx, nxc] : gr.at(now)) {
      self(self, nx, sum + nxc, lv + 1);
    }
  };
  rc(rc, 0, 0, 0);
  vector<int> o;
  rep(i, n) if (ans.at(i)) o.push_back(i + 1);
  rep(i, o.size()) {
    if (i != 0) cout << " ";
    cout << o.at(i);
  }
  cout << endl;
  return 0;
}