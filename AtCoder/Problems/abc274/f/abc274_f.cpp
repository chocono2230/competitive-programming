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
  int n, a;
  cin >> n >> a;
  vector<tuple<int, int, int>> wxv(n);
  int mx = 0;
  rep(i, n) {
    int w, x, v;
    cin >> w >> x >> v;
    mx = max(mx, x);
    wxv.at(i) = {w, x, v};
  }
  vector<tuple<double, int, int>> cr;
  rep(i, n) rep2(j, i + 1, n) {
    auto [w1, x1, v1] = wxv.at(i);
    auto [w2, x2, v2] = wxv.at(j);
    if (x1 > x2) {
      swap(x1, x2);
      swap(v1, v2);
    }
    double d = x2 - x1;
    if (v1 > v2) {
      if (d > a) {
        double t = (d - a) / (double)(v1 - v2);
        cr.push_back({t, i, j});
      }
      d += a;
      double t = (d - a) / (double)(v1 - v2);
      cr.push_back({t, i, j});
    } else {
      if (d < a) {
        double t = (a - d) / (double)(v2 - v1);
        cr.push_back({t, i, j});
      }
    }
  }

  sort(ALL(cr));
  bool end = false;
  int ans = 0;
  rep(___i, 1) {
    double t = 0;
    vector<pair<double, int>> xw(n);
    rep(i, n) {
      auto [w, x, v] = wxv.at(i);
      xw.at(i) = {x + t * v, w};
    }
    sort(ALL(xw));
    int now = 0;
    int l = 0;
    rep(i, n) {
      auto [x, w] = xw.at(i);
      now += w;
      while (xw.at(l).first < x - a) {
        now -= xw.at(l).second;
        l++;
      }
      // cerr << now << " " << x << endl;
      ans = max(ans, now);
    }
  }

  for (auto [t, pi, pj] : cr) {
    if (end) break;
    // cerr << t << endl;
    vector<pair<double, int>> xw(n);
    rep(i, n) {
      auto [w, x, v] = wxv.at(i);
      xw.at(i) = {x + t * v, w};
    }
    sort(ALL(xw));
    if (xw.front().first >= mx) end = true;
    int now = 0;
    int l = 0;
    rep(i, n) {
      auto [x, w] = xw.at(i);
      now += w;
      while (xw.at(l).first < x - a) {
        now -= xw.at(l).second;
        l++;
      }
      // cerr << now << " " << x << endl;
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}