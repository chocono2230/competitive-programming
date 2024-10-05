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
  int n, s, t;
  cin >> n >> s >> t;
  using Point = pair<int, int>;
  vector<pair<Point, Point>> v(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    v.at(i) = {{a, b}, {c, d}};
  }

  vector<int> pp(n);
  rep(i, n) pp.at(i) = i;
  const ll INF = 1e18;
  double ans = INF;
  do {
    rep(bit, 1 << n) {
      int x = 0, y = 0;
      double nw = 0;
      rep(i, n) {
        auto fc = [&](Point &p, Point &q) {
          double add = 0;
          double dd = hypot(x - p.first, y - p.second);
          add += dd / s;
          x = p.first, y = p.second;
          dd = hypot(x - q.first, y - q.second);
          add += dd / t;
          x = q.first, y = q.second;
          return add;
        };
        if ((bit & (1 << i)) == 0)
          nw += fc(v.at(pp.at(i)).first, v.at(pp.at(i)).second);
        else
          nw += fc(v.at(pp.at(i)).second, v.at(pp.at(i)).first);
      }
      ans = min(ans, nw);
    }
  } while (next_permutation(ALL(pp)));
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}