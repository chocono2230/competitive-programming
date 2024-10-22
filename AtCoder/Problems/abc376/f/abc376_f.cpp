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
  int n, q;
  cin >> n >> q;
  vector<pair<char, int>> ht(q);
  rep(i, q) {
    char h;
    int t;
    cin >> h >> t;
    t--;
    ht.at(i) = {h, t};
  }
  const ll INF = 1e18;
  vector<ll> base(n, INF);
  ht.insert(ht.begin(), {'R', 1});
  auto dp = base;
  dp.at(0) = 0;
  rep2(i, 1, q + 1) {
    auto nxdp = base;
    auto [bh, bt] = ht.at(i - 1);
    auto [h, t] = ht.at(i);
    rep(j, n) {
      if (dp.at(j) == INF) continue;
      // p を t に動かす
      int p = bt, q = bt;
      if (bh == h) {
        q = j;
      } else {
        p = j;
      }
      if (p == q) continue;

      // 時計回りに
      int nxq = q;
      if (p <= t) {
        ll add = t - p;
        if (p < q && q <= t) {
          nxq = (t + 1) % n;
          add += (t - q + 1);
        }
        nxdp.at(nxq) = min(nxdp.at(nxq), dp.at(j) + add);
      } else {
        ll add = (n - p) + t;
        if (q > p || q <= t) {
          nxq = (t + 1) % n;
          if (q <= t) {
            add += t - q + 1;
          } else {
            add += (n - q) + (t + 1);
          }
        }
        nxdp.at(nxq) = min(nxdp.at(nxq), dp.at(j) + add);
      }

      nxq = q;
      // 反時計回りに
      if (p >= t) {
        ll add = p - t;
        if (q < p && q >= t) {
          nxq = (t - 1 + n) % n;
          add += q - t + 1;
        }
        nxdp.at(nxq) = min(nxdp.at(nxq), dp.at(j) + add);
      } else {
        ll add = p + 1 + (n - (t + 1));
        if (q < p || q >= t) {
          nxq = (t - 1 + n) % n;
          if (q >= t) {
            add += q - t + 1;
          } else {
            add += (q + 1) + (n - (t + 1) + 1);
          }
        }
        nxdp.at(nxq) = min(nxdp.at(nxq), dp.at(j) + add);
      }
    }
    swap(dp, nxdp);
    // rep(i, n) cerr << (dp.at(i) == INF ? -1 : dp.at(i)) << " ";
    // cerr << endl;
  }
  cout << *min_element(ALL(dp)) << endl;
  return 0;
}