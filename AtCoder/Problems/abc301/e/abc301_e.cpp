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
const int INF = 1001001001;

int main() {
  int h, w, t;
  cin >> h >> w >> t;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  vector<pair<int, int>> sp(2, {0, 0});
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == 'o') sp.push_back({i, j});
    if (s.at(i).at(j) == 'S') sp.at(0) = {i, j};
    if (s.at(i).at(j) == 'G') sp.at(1) = {i, j};
  }

  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  vector sg(sp.size(), vector<int>(sp.size(), INF));
  auto bfs = [&](int si, int sj, vector<int> &tb) -> void {
    vector table(h, vector<int>(w, INF));
    queue<pair<int, int>> q;
    q.push({si, sj});
    table.at(si).at(sj) = 0;
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (s.at(ni).at(nj) == '#' || table.at(ni).at(nj) != INF) continue;
        table.at(ni).at(nj) = table.at(i).at(j) + 1;
        q.push({ni, nj});
      }
    }
    rep(id, sp.size()) {
      auto [i, j] = sp.at(id);
      tb.at(id) = table.at(i).at(j);
    }
  };
  rep(i, sp.size()) bfs(sp.at(i).first, sp.at(i).second, sg.at(i));

  vector dp(1 << sp.size(), vector<int>(sp.size(), INF));
  dp.at(1).front() = 0;
  int ans = 0;
  rep2(bit, 1, 1 << sp.size()) {
    rep(last, sp.size()) {
      if (dp.at(bit).at(last) == INF) continue;
      int now = dp.at(bit).at(last);
      rep(nx, sp.size()) {
        if ((bit & (1 << nx)) != 0) continue;
        int nxbit = (bit | (1 << nx));
        int nxcost = now + sg.at(last).at(nx);
        dp.at(nxbit).at(nx) = min(dp.at(nxbit).at(nx), nxcost);
        if (nx == 1) {
          if (dp.at(nxbit).at(nx) <= t) {
            ans = max(ans, __builtin_popcount(nxbit));
          }
        }
      }
    }
  }
  ans -= 2;
  if (ans < 0) ans = -1;
  cout << ans << endl;
  return 0;
}