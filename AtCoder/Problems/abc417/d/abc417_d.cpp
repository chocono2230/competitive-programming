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
  cin >> n;
  vector<tuple<int, int, int>> pab(n);
  rep(i, n) {
    int p, a, b;
    cin >> p >> a >> b;
    pab.at(i) = {p, a, b};
  }
  int sz = 1005;
  vector memo(n + 1, vector<int>(sz, -1));
  rep(i, sz) memo.back().at(i) = i;
  rrep(i, n) {
    auto [p, a, b] = pab.at(i);
    rep(j, sz) {
      if (j > p) {
        int nx = max(0, j - b);
        memo.at(i).at(j) = memo.at(i + 1).at(nx);
      } else {
        int nx = j + a;
        memo.at(i).at(j) = memo.at(i + 1).at(nx);
      }
    }
  }
  vector<int> sums(n + 1, 0);
  rep(i, n) {
    auto [p, a, b] = pab.at(i);
    sums.at(i + 1) = sums.at(i) + b;
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    int st = 0;
    if (x > 500) {
      int idx = lower_bound(ALL(sums), x - 500) - sums.begin();
      if (idx == n + 1) {
        x -= sums.back();
        cout << x << endl;
        continue;
      }
      x -= sums.at(idx);
      st = idx;
    }
    cout << memo.at(st).at(x) << endl;
  }
  return 0;
}