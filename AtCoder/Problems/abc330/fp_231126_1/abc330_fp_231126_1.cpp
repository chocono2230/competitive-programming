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
  int n;
  ll k;
  cin >> n >> k;
  vector<int> x(n), y(n);
  rep(i, n) {
    int ix, iy;
    cin >> ix >> iy;
    x.at(i) = ix;
    y.at(i) = iy;
  }
  sort(ALL(x));
  sort(ALL(y));
  int mx = x.back() - x.front();
  int my = y.back() - y.front();
  auto fc = [&](vector<int> &v) {
    vector<pair<int, int>> res;
    int li = 0, ri = v.size() - 1;
    while (li != ri) {
      int lc = li + 1, rc = v.size() - ri;
      int ld = v.at(li + 1) - v.at(li);
      int rd = v.at(ri) - v.at(ri - 1);
      pair<int, int> add;
      if (lc < rc) {
        li++;
        add = {lc, ld};
      } else {
        ri--;
        add = {rc, rd};
      }
      res.push_back(add);
    }
    return res;
  };
  auto vx = fc(x);
  auto vy = fc(y);

  int ok = 1e9 + 5, ng = -1;
  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    auto ff = [&](vector<pair<int, int>> &v, int sd) {
      int now = sd;
      ll res = 0;
      for (auto [p, q] : v) {
        if (now <= mid) break;
        int d = q;
        if (now - q < mid) d = now - mid;
        res += (ll)p * d;
        now -= d;
      }
      return res;
    };
    // cerr << mid << " " << ff(vx, mx) + ff(vy, my) << " " << k << endl;
    if (ff(vx, mx) + ff(vy, my) <= k)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}