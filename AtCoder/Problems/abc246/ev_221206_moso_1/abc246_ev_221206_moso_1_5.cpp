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
  int ai, aj;
  cin >> ai >> aj;
  ai--;
  aj--;
  int bi, bj;
  cin >> bi >> bj;
  bi--;
  bj--;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  int di[] = {1, 1, -1, -1}, dj[] = {1, -1, 1, -1};
  deque<tuple<int, int, int>> q;
  const int INF = 1001001001;
  vector d(4, vector(n, vector<int>(n, INF)));
  rep(i, 4) {
    d.at(i).at(ai).at(aj) = 1;
    q.push_back({ai, aj, i});
  }
  while (!q.empty()) {
    auto [i, j, mode] = q.front();
    q.pop_front();
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || n <= ni || nj < 0 || n <= nj) continue;
      int nxcost = 1 + d.at(mode).at(i).at(j);
      if (mode == k) nxcost--;
      if (s.at(ni).at(nj) == '#' || d.at(k).at(ni).at(nj) <= nxcost) continue;
      d.at(k).at(ni).at(nj) = nxcost;
      if (mode == k)
        q.push_front({ni, nj, k});
      else
        q.push_back({ni, nj, k});
    }
  }
  // rep(i, n) {
  //   for (auto j : d.at(i)) {
  //     if (j == INF) j = -1;
  //     printf("%2d ", j);
  //   }
  //   cout << endl;
  // }
  int ans = INF;
  rep(i, 4) ans = min(ans, d.at(i).at(bi).at(bj));
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}