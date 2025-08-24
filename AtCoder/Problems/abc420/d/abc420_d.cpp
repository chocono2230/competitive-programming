#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  const int INF = 1001001001;
  vector table(h, vector(w, vector<int>(2, INF)));
  int si = -1, sj = -1;
  int ti = -1, tj = -1;
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == 'S') {
      si = i, sj = j;
    }
    if (s.at(i).at(j) == 'G') {
      ti = i, tj = j;
    }
  }
  queue<tuple<int, int, int>> q;
  q.push({si, sj, 0});
  table.at(si).at(sj).at(0) = 0;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  while (!q.empty()) {
    auto [i, j, m] = q.front();
    q.pop();
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      int nm = m;
      if (s.at(ni).at(nj) == '?') nm ^= 1;
      if (s.at(ni).at(nj) == '#' || table.at(ni).at(nj).at(nm) != INF) continue;
      if ((nm == 0 && s.at(ni).at(nj) == 'x') ||
          (nm == 1 && s.at(ni).at(nj) == 'o'))
        continue;
      table.at(ni).at(nj).at(nm) = table.at(i).at(j).at(m) + 1;
      q.push({ni, nj, nm});
    }
  }
  int ans = min(table.at(ti).at(tj).at(0), table.at(ti).at(tj).at(1));
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}