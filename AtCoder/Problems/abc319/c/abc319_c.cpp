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
  vector c(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> c.at(i).at(j);
  vector<int> p(9);
  rep(i, 9) p.at(i) = i;
  int ok = 0, sum = 0;
  auto fc = [](int x, int x1, int y, int y1, int z, int z1) -> bool {
    vector<pair<int, int>> v = {{x, x1}, {y, y1}, {z, z1}};
    sort(ALL(v));
    if (v.at(0).second == v.at(1).second) return true;
    return false;
  };
  do {
    vector t(3, vector<int>(3));
    rep(i, 9) t.at(p.at(i) / 3).at(p.at(i) % 3) = i;
    bool chk = false;
    rep(i, 3) {
      chk |= fc(t.at(i).at(0), c.at(i).at(0), t.at(i).at(1), c.at(i).at(1),
                t.at(i).at(2), c.at(i).at(2));
    }
    rep(j, 3) {
      chk |= fc(t.at(0).at(j), c.at(0).at(j), t.at(1).at(j), c.at(1).at(j),
                t.at(2).at(j), c.at(2).at(j));
    }
    chk |= fc(t.at(0).at(0), c.at(0).at(0), t.at(1).at(1), c.at(1).at(1),
              t.at(2).at(2), c.at(2).at(2));
    chk |= fc(t.at(0).at(2), c.at(0).at(2), t.at(1).at(1), c.at(1).at(1),
              t.at(2).at(0), c.at(2).at(0));
    if (!chk) ok++;
    sum++;
  } while (next_permutation(ALL(p)));
  double ans = (double)ok / sum;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}