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
  int n, l, d;
  cin >> n >> l >> d;
  vector<double> yd(n + 2, 0);
  vector<double> yi(n + 2, 0);
  double now = 0;
  yi.at(0) = 1;
  yi.at(1) = -1;
  double ss = 0;
  rep(i, n + 2) {
    now += yi.at(i);
    if (i < l) {
      yi.at(i + 1) += now / d;
      int r = i + d + 1;
      if (r <= n) yi.at(r) -= now / d;
    } else if (i != n + 1) {
      yd.at(i) = now;
      ss += now;
    } else {
      yd.at(i) = 1 - ss;
    }
  }

  double yok = 1;
  now = 0;
  vector<double> xw(n + 2, 0);
  vector<double> xwi(n + 2, 0);
  rrep(i, n + 2) {
    if (i == n + 1) {
      xw.at(i) = 0;
      continue;
    }
    yok -= yd.at(i);
    now += xwi.at(i);
    // cerr << i << " " << yok << " " << now << endl;
    if (yok > now) {
      xw.at(i) = yok;
    } else {
      xw.at(i) = now;
    }
    if (i != 0) xwi.at(i - 1) += xw.at(i) / d;
    if (i - d - 1 >= 0) xwi.at(i - d - 1) -= xw.at(i) / d;
  }

  vector<double> xi(n + 2, 0);
  now = 0;
  xi.at(0) = 1;
  xi.at(1) = -1;
  double ans = xw.at(0);
  // rep(i, n + 1) {
  //   now += xi.at(i);
  //   if (i < l) {
  //     xi.at(i + 1) += now / d;
  //     int r = i + d + 1;
  //     if (r <= n) xi.at(r) -= now / d;
  //   } else {
  //     ans += xw.at(i) * now;
  //   }
  // }
  // for (auto now : yd) cerr << now << " ";
  // cerr << endl;
  // for (auto now : xw) cerr << now << " ";
  // cerr << endl;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}