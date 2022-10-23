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

struct frac {
  ll top = 0, btm = 1;
  frac(ll top, ll btm) : top(top), btm(btm) {}
  frac() {}
  friend bool operator<(const frac &l, const frac &r) {
    return l.top * r.btm < r.top * l.btm;
  }
  friend bool operator==(const frac &l, const frac &r) {
    return l.top * r.btm == r.top * l.btm;
  }
};

int main() {
  int n, a;
  cin >> n >> a;
  vector<tuple<int, int, int>> wxv(n);
  rep(i, n) {
    int w, x, v;
    cin >> w >> x >> v;
    wxv.at(i) = {w, x, v};
  }
  int ans = 0;
  rep(k, n) {
    auto [w1, x1, v1] = wxv.at(k);
    vector<pair<frac, int>> fv;
    int now = w1;
    rep(i, n) {
      if (i == k) continue;
      auto [w2, x2, v2] = wxv.at(i);
      if (x2 < x1) {
        int v = v2 - v1;
        int d = x1 - x2;
        if (v <= 0) continue;
        fv.push_back({frac(d, v), -w2});
        d += a;
        fv.push_back({frac(d, v), +w2});
      } else if (x2 <= x1 + a) {
        now += w2;
        if (v1 < v2) {
          int d = x1 + a - x2;
          fv.push_back({frac(d, v2 - v1), +w2});
        } else if (v2 < v1) {
          int d = x2 - x1;
          fv.push_back({frac(d, v1 - v2), +w2});
        }
      } else {
        int v = v1 - v2;
        int d = x2 - (x1 + a);
        if (v <= 0) continue;
        fv.push_back({frac(d, v), -w2});
        d += a;
        fv.push_back({frac(d, v), +w2});
      }
    }
    // cerr << k << " : " << now << endl;
    ans = max(ans, now);
    sort(ALL(fv));
    for (auto [f, w] : fv) {
      now -= w;
      // cerr << (double)f.top / f.btm << " " << now << " " << w << endl;
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}