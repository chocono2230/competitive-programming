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
  int ax, ay;
  cin >> ax >> ay;
  int bx, by;
  cin >> bx >> by;
  ax--;
  ay--;
  bx--;
  by--;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);

  int di[] = {1, 1, -1, -1}, dj[] = {1, -1, 1, -1};
  const int INF = 1001001001;
  vector d(4, vector(n, vector<int>(n, INF)));
  deque<tuple<int, int, int>> q;
  q.push_back({-1, ax, ay});
  rep(k, 4) { d.at(k).at(ax).at(ay) = 0; }
  while (!q.empty()) {
    auto [arr, i, j] = q.front();
    q.pop_front();
    int cs = 0;
    if (arr != -1) cs = d.at(arr).at(i).at(j);
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || n <= ni || nj < 0 || n <= nj) continue;
      if (s.at(ni).at(nj) == '#') continue;
      int cc = cs;
      if (k != arr) cc++;
      if (d.at(k).at(ni).at(nj) <= cc) continue;
      if (k == arr) {
        d.at(k).at(ni).at(nj) = cc;
        q.push_front({k, ni, nj});
      } else {
        d.at(k).at(ni).at(nj) = cc;
        q.push_back({k, ni, nj});
      }
    }
  }
  // rep(k, 4) {
  //   rep(i, n) {
  //     rep(j, n) {
  //       int ans = INF;
  //       if (d.at(k).at(i).at(j) != -1) ans = min(ans, d.at(k).at(i).at(j));
  //       if (ans == INF) ans = -1;
  //       cout << ans << " ";
  //     }
  //     cout << endl;
  //   }
  // }
  int ans = INF;
  rep(k, 4) { ans = min(ans, d.at(k).at(bx).at(by)); }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}