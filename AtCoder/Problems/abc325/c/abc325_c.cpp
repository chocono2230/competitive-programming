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
  int di[] = {1, 1, 1, 0, 0, -1, -1, -1};
  int dj[] = {1, 0, -1, 1, -1, 1, 0, -1};
  vector tb(h, vector<int>(w, -1));
  int co = 0;
  rep(si, h) rep(sj, w) {
    if (tb.at(si).at(sj) != -1) continue;
    if (s.at(si).at(sj) == '.') continue;
    tb.at(si).at(sj) = co;
    queue<pair<int, int>> q;
    q.push({si, sj});
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      rep(k, 8) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (tb.at(ni).at(nj) != -1) continue;
        if (s.at(ni).at(nj) == '.') continue;
        tb.at(ni).at(nj) = co;
        q.push({ni, nj});
      }
    }
    co++;
  }
  cout << co << endl;
  return 0;
}