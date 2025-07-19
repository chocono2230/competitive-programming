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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  vector<int> p(h + w - 1);
  rep(i, h + w - 1) cin >> p.at(i);
  const ll INF = 1e18;

  vector idxs(h + w - 1, vector<pair<int, int>>());
  rep(i, h) rep(j, w) { idxs.at(i + j).push_back({i, j}); }

  auto fc = [&](ll st) {
    vector dp(h, vector<ll>(w, -INF));
    dp.at(0).at(0) = st + a.at(0).at(0) - p.at(0);
    if (dp.at(0).at(0) < 0) return false;
    rep2(ta, 1, h + w - 1) {
      for (auto [i, j] : idxs.at(ta)) {
        int pi = i, pj = j;
        if (i != 0) {
          pi = i - 1, pj = j;
          ll nx = dp.at(pi).at(pj) + a.at(i).at(j) - p.at(ta);
          if (nx >= 0) {
            dp.at(i).at(j) = max(dp.at(i).at(j), nx);
          }
        }
        if (j != 0) {
          pi = i, pj = j - 1;
          ll nx = dp.at(pi).at(pj) + a.at(i).at(j) - p.at(ta);
          if (nx >= 0) {
            dp.at(i).at(j) = max(dp.at(i).at(j), nx);
          }
        }
      }
    }
    return dp.back().back() >= 0;
  };

  ll ok = 1e18, ng = -1;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    if (fc(mid))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}