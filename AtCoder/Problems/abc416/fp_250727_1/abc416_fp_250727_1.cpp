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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  const ll INF = 1e18;
  vector dp(n, vector(k + 1, vector<ll>(3, -INF)));
  vector base(k + 1, vector<ll>(3, -INF));
  auto rc = [&](const auto &self, int now, int par) -> void {
    dp.at(now).at(0).at(0) = 0;
    for (auto nx : tree.at(now)) {
      if (nx == par) continue;
      self(self, nx, now);
      auto nw = base;
      rep(i, k + 1) rep(i1, k + 1) {
        int pi = i + i1;
        if (pi <= k) {
          nw.at(pi).at(0) = max(
              nw.at(pi).at(0), dp.at(now).at(i).at(0) + dp.at(nx).at(i1).at(0));
          nw.at(pi).at(1) =
              max(nw.at(pi).at(1),
                  dp.at(now).at(i).at(0) + dp.at(nx).at(i1).at(1) + a.at(now));
          nw.at(pi).at(1) = max(
              nw.at(pi).at(1), dp.at(now).at(i).at(1) + dp.at(nx).at(i1).at(0));
          nw.at(pi).at(1) = max(
              nw.at(pi).at(1), dp.at(now).at(i).at(1) + dp.at(nx).at(i1).at(1));
          nw.at(pi).at(2) = max(
              nw.at(pi).at(2), dp.at(now).at(i).at(2) + dp.at(nx).at(i1).at(0));
          nw.at(pi).at(2) = max(
              nw.at(pi).at(2), dp.at(now).at(i).at(2) + dp.at(nx).at(i1).at(1));
        }
        if (pi - 1 >= 0 && pi - 1 <= k) {
          nw.at(pi - 1).at(2) =
              max(nw.at(pi - 1).at(2),
                  dp.at(now).at(i).at(1) + dp.at(nx).at(i1).at(1));
        }
      }
      swap(dp.at(now), nw);
    }
    rep(i, k) {
      dp.at(now).at(i + 1).at(1) =
          max(dp.at(now).at(i + 1).at(1), dp.at(now).at(i).at(0) + a.at(now));
    }
    rep(i, k + 1) {
      dp.at(now).at(i).at(0) = *max_element(ALL(dp.at(now).at(i)));
    }
  };
  rc(rc, 0, -1);
  // rep(i, n) {
  //   rep(j, k + 1) {
  //     rep(p, 3) cerr << (dp.at(i).at(j).at(p) <= -1 ? -1 :
  //     dp.at(i).at(j).at(p))
  //                    << ":";
  //     cerr << " ";
  //   }
  //   cerr << endl;
  // }
  ll ans = -INF;
  rep(i, k + 1) ans = max(ans, dp.at(0).at(i).at(0));
  cout << ans << endl;
  return 0;
}