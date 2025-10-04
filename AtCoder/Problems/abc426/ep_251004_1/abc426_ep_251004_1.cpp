#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int q;
  cin >> q;
  using P = pair<double, double>;
  while (q--) {
    double tsx, tsy, tgx, tgy;
    cin >> tsx >> tsy >> tgx >> tgy;
    double asx, asy, agx, agy;
    cin >> asx >> asy >> agx >> agy;
    auto fc = [](P p, P ta, double mx) -> pair<double, P> {
      auto f = [&](double t) {
        return P(ta.first - p.first * t, ta.second - p.second * t);
      };
      double l = 0, r = mx;
      rep(_i, 100) {
        double l1 = l + (r - l) / 3, r1 = r - (r - l) / 3;
        auto vl = f(l1), vr = f(r1);
        if (hypot(vl.first, vl.second) < hypot(vr.first, vr.second)) {
          r = r1;
        } else {
          l = l1;
        }
      };
      auto res = f((l + r) / 2);
      P z(ta.first - p.first * mx, ta.second - p.second * mx);
      return {hypot(res.first, res.second), z};
    };
    auto nn = [](P p) {
      double ss = hypot(p.first, p.second);
      return P(p.first / ss, p.second / ss);
    };
    P st(asx - tsx, asy - tsy);
    P tv(tgx - tsx, tgy - tsy);
    P av(agx - asx, agy - asy);
    double tht = hypot(tv.first, tv.second);
    double tha = hypot(av.first, av.second);

    double tt = min(tht, tha);
    tv = nn(tv);
    av = nn(av);
    P vv(tv.first - av.first, tv.second - av.second);
    auto r1 = fc(vv, st, tt);

    double z = tht - tha;
    P zv;
    if (z < 0) {
      z *= -1;
      zv = P(av.first * -1, av.second * -1);
    } else {
      zv = tv;
    }
    auto r2 = fc(zv, r1.second, z);
    // cerr << r1.second.first << " " << r1.second.second << " " << z << " "
    //      << zv.first << " " << zv.second << " "
    //      << hypot(r1.second.first, r1.second.second) << " " <<
    //      r2.second.first
    //      << " " << r2.second.second << endl;
    // cerr << r1.first << " " << r2.first << endl;
    double ans = min(r1.first, r2.first);
    cout << fixed << setprecision(10) << ans << endl;
  }
  return 0;
}