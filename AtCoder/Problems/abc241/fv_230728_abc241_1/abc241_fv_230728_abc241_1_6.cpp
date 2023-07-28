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
  int h, w, n;
  cin >> h >> w >> n;
  int sx, sy;
  cin >> sx >> sy;
  int gx, gy;
  cin >> gx >> gy;
  set<pair<int, int>> xs, ys;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xs.insert({x, y});
    ys.insert({y, x});
  }

  queue<pair<int, int>> q;
  map<pair<int, int>, int> dd;
  dd[{sx, sy}] = 0;
  q.push({sx, sy});
  const int INF = 1001001001;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    // cerr << i << " " << j << " " << dd[{i, j}] << endl;
    rep(k, 4) {
      int ni = INF, nj = INF;
      if (k == 1) {
        auto itr = xs.upper_bound({i, j});
        if (itr == xs.end() || itr->first != i) continue;
        auto [qi, qj] = *itr;
        qj--;
        if (dd.find({qi, qj}) != dd.end()) continue;
        ni = qi, nj = qj;
      }
      if (k == 3) {
        auto itr = xs.lower_bound({i, j});
        if (itr == xs.begin()) continue;
        itr--;
        if (itr->first != i) continue;
        auto [qi, qj] = *itr;
        qj++;
        if (dd.find({qi, qj}) != dd.end()) continue;
        ni = qi, nj = qj;
      }
      if (k == 0) {
        auto itr = ys.upper_bound({j, i});
        if (itr == ys.end() || itr->first != j) continue;
        auto [qj, qi] = *itr;
        qi--;
        if (dd.find({qi, qj}) != dd.end()) continue;
        ni = qi, nj = qj;
      }
      if (k == 2) {
        auto itr = ys.lower_bound({j, i});
        if (itr == ys.begin()) continue;
        itr--;
        if (itr->first != j) continue;
        auto [qj, qi] = *itr;
        qi++;
        if (dd.find({qi, qj}) != dd.end()) continue;
        ni = qi, nj = qj;
      }
      if (ni == INF) continue;
      q.push({ni, nj});
      dd[{ni, nj}] = dd[{i, j}] + 1;
    }
  }
  int ans = -1;
  if (dd.find({gx, gy}) != dd.end()) ans = dd[{gx, gy}];
  cout << ans << endl;
  return 0;
}