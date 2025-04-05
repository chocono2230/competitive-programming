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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  int c, d;
  cin >> c >> d;
  c--;
  d--;
  const int INF = 1001001001;
  vector table(h, vector<int>(w, INF));
  deque<pair<int, int>> q;
  table.at(a).at(b) = 0;
  q.push_back({a, b});
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop_front();
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '#' || table.at(ni).at(nj) <= table.at(i).at(j))
        continue;
      table.at(ni).at(nj) = table.at(i).at(j);
      q.push_front({ni, nj});
    }
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '.' ||
          table.at(ni).at(nj) <= table.at(i).at(j) + 1)
        continue;
      table.at(ni).at(nj) = table.at(i).at(j) + 1;
      q.push_back({ni, nj});
    }
    rep(k, 4) {
      int ni = i + di[k] * 2, nj = j + dj[k] * 2;
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '.' ||
          table.at(ni).at(nj) <= table.at(i).at(j) + 1)
        continue;
      table.at(ni).at(nj) = table.at(i).at(j) + 1;
      q.push_back({ni, nj});
    }
  }
  cout << table.at(c).at(d) << endl;
  return 0;
}