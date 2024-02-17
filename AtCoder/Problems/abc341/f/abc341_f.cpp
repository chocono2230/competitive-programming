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
  vector<pair<int, int>> ab(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ab.at(i) = {a, b};
  }
  vector<int> w(n);
  rep(i, n) cin >> w.at(i);
  vector gr(n, vector<int>());
  for (auto [a, b] : ab) {
    if (w.at(a) == w.at(b)) continue;
    if (w.at(a) > w.at(b)) {
      gr.at(a).push_back(b);
    } else {
      gr.at(b).push_back(a);
    }
  }
  vector<pair<int, int>> wi(n);
  rep(i, n) wi.at(i) = {w.at(i), i};
  sort(ALL(wi), greater<pair<int, int>>());
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> memo(n, -1);
  auto fc = [&](const auto &self, int now) -> ll {
    if (memo.at(now) != -1) return memo.at(now);
    ll res = 1;
    for (auto nx : gr.at(now)) {
      ll p = self(self, nx);
      res = max(res, p + 1);
    }
    return memo.at(now) = res;
  };
  rep(i, n) fc(fc, i);
  ll ans = 0;
  for (auto [c, now] : wi) {
    vector dp(gr.at(now).size() + 1, vector<ll>(c, 0));
    vector bk(gr.at(now).size() + 1, vector<pair<int, int>>(c, {-1, -1}));
    int idx = -1;
    for (auto nx : gr.at(now)) {
      idx++;
      int add = memo.at(nx);
      int e = w.at(nx);
      // cerr << now << " " << nx << " " << add << " " << e << endl;
      rrep(i, c) {
        dp.at(idx + 1).at(i) = dp.at(idx).at(i);
        bk.at(idx + 1).at(i) = {idx, i};
        int j = i - e;
        if (j < 0) break;
        if (add + dp.at(idx).at(j) <= dp.at(idx + 1).at(i)) continue;
        dp.at(idx + 1).at(i) = add + dp.at(idx).at(j);
        bk.at(idx + 1).at(i) = {idx, j};
      }
    }
    ans += a.at(now);
    int pi = bk.size() - 1, pj = c - 1;
    vector<int> v;
    while (1) {
      if (bk.at(pi).at(pj).first == -1) break;
      auto [nxi, nxj] = bk.at(pi).at(pj);
      if (pj != nxj) {
        v.push_back(nxi);
      }
      pi = nxi;
      pj = nxj;
    }
    for (auto idx : v) {
      int nx = gr.at(now).at(idx);
      a.at(nx) += a.at(now);
    }
  }
  cout << ans << endl;
  return 0;
}