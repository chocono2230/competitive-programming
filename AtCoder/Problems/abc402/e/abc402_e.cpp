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
  int n, x;
  cin >> n >> x;
  vector<double> base(x + 1, -1);
  auto dp = base;
  dp.back() = 0;
  rep(i, n) {
    int s, c, ip;
    cin >> s >> c >> ip;
    double p = ip / 100.0;
    double rp = 1 - p;
    auto nxdp = base;
    rep(i, x + 1) {
      if (dp.at(i) < 0) continue;
      nxdp.at(i) = max(nxdp.at(i), dp.at(i));
      double np = 1;
      int sumc = 0;
      rep(k, x + 1) {
        sumc += c;
        if (i - sumc < 0) break;
        double add = dp.at(i) + (double)s * (np * p);
        nxdp.at(i - sumc) = max(nxdp.at(i - sumc), add);
        np *= rp;
      }
    }
    for (auto now : nxdp) cerr << now << " ";
    cerr << endl;
    swap(dp, nxdp);
  }
  cout << fixed << setprecision(10) << *max_element(ALL(dp)) << endl;
  return 0;
}