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

struct Frac {
  ll top = 0, btm = 1;
  Frac(ll top, ll btm) : top(top), btm(btm) {}
  Frac() {}
  friend bool operator<(const Frac &l, const Frac &r) {
    return l.top * r.btm < r.top * l.btm;
  }
  friend bool operator==(const Frac &l, const Frac &r) {
    return l.top * r.btm == r.top * l.btm;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector gr(n, vector<tuple<int, int, int>>());
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    int b, c;
    cin >> b >> c;
    gr.at(u).push_back({v, b, c});
  }
  double ok = 0, ng = 1e10;
  rep(_i, 200) {
    double mid = (ok + ng) / 2;
    // cerr << ok << " " << mid << " " << ng << endl;
    auto fc = [&]() {
      vector<Frac> dp(n, Frac(0, 0));
      auto comp = [&](const Frac l, const Frac r) {
        double ld = l.top - l.btm * mid;
        double rd = r.top - r.btm * mid;
        return ld <= rd;
      };
      rep(i, n) {
        if (i != 0 && dp.at(i).btm == 0) continue;
        for (auto [nx, b, c] : gr.at(i)) {
          auto nxfr = dp.at(i);
          nxfr.top += b;
          nxfr.btm += c;
          if (dp.at(nx).btm == 0 || comp(dp.at(nx), nxfr)) {
            dp.at(nx) = nxfr;
          }
        }
      }
      auto f = dp.back();
      return (f.top - f.btm * mid) >= 0;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  double ans = (ok + ng) / 2.0;
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}