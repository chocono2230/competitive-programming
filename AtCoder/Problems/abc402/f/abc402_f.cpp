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
  vector a(n, vector<ll>(n));
  vector<ll> pw(50, 1);
  rep(i, 49) {
    pw.at(i + 1) = pw.at(i) * 10;
    pw.at(i + 1) %= m;
  }
  rep(i, n) rep(j, n) {
    int in;
    cin >> in;
    a.at(i).at(j) = in;
    int t = (2 * n) - (i + j + 2);
    a.at(i).at(j) *= pw.at(t);
    a.at(i).at(j) %= m;
  }
  auto fc = [&](vector<vector<ll>> &memo, bool f) {
    auto rc = [&](const auto &self, int i, int j, ll now) -> void {
      if (i + j == n - 1) {
        if (f) {
          now += a.at(i).at(j);
          now %= m;
        }
        memo.at(i).push_back(now);
        return;
      }
      now += a.at(i).at(j);
      now %= m;
      if (i != n - 1) {
        self(self, i + 1, j, now);
      }
      if (j != n - 1) {
        self(self, i, j + 1, now);
      }
    };
    rc(rc, 0, 0, 0);
  };
  vector ra(n, vector<ll>(n));
  rep(i, n) rep(j, n) { ra.at(i).at(j) = a.at(n - i - 1).at(n - j - 1); }
  vector memo1(n, vector<ll>(0));
  vector memo2(n, vector<ll>(0));
  // rep(i, n) {
  //   rep(j, n) cerr << a.at(i).at(j) << " ";
  //   cerr << endl;
  // }
  fc(memo1, true);
  swap(a, ra);
  fc(memo2, false);
  ll ans = 0;
  rep(i, n) {
    int j = n - i - 1;
    auto &v1 = memo1.at(i);
    auto &v2 = memo2.at(j);
    sort(ALL(v1));
    sort(ALL(v2));
    int r = v2.size() - 1;
    rep(l, v1.size()) {
      while (r >= 0) {
        if (v1.at(l) + v2.at(r) < m) break;
        r--;
      }
      if (r < 0) break;
      // cerr << i << " " << v1.at(l) << " " << v2.at(r) << endl;
      ans = max(ans, v1.at(l) + v2.at(r));
    }
    ans = max(ans, (v1.back() + v2.back()) % m);
  }
  cout << ans << endl;
  return 0;
}