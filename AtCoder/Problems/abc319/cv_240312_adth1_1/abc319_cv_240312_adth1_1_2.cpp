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
  auto p2i = [&](int p) {
    int i = p / 3;
    int j = p % 3;
    return c.at(i).at(j);
  };
  vector<int> order(9);
  rep(i, 9) order.at(i) = i;
  auto ch = [&](int p, int q, int r) {
    int o1 = order.at(p), o2 = order.at(q), o3 = order.at(r);
    int x = p2i(p), y = p2i(q), z = p2i(r);
    if (o1 < o2 && o1 < o3) {
      if (o2 < o3)
        return x == y;
      else
        return x == z;
    } else if (o2 < o3) {
      if (o1 < o3)
        return y == x;
      else
        return y == z;
    } else {
      if (o1 < o2)
        return z == x;
      else
        return z == y;
    }
  };
  int co = 0, sum = 0;
  do {
    bool f = false;
    rep(i, 3) f |= ch(i * 3, i * 3 + 1, i * 3 + 2);
    rep(i, 3) f |= ch(i, 3 + i, 6 + i);
    f |= ch(0, 4, 8);
    f |= ch(2, 4, 6);
    if (!f) co++;
    sum++;
  } while (next_permutation(ALL(order)));
  double ans = (double)co / (double)sum;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}