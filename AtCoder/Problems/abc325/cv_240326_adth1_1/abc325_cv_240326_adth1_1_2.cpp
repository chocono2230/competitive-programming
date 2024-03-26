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
  vector tb(h, vector<int>(w, -1));
  int sz = 0;
  int di[] = {1, 0, -1, 0, 1, 1, -1, -1}, dj[] = {0, 1, 0, -1, 1, -1, 1, -1};
  rep(si, h) rep(sj, w) {
    if (s.at(si).at(sj) == '.') continue;
    if (tb.at(si).at(sj) != -1) continue;
    queue<pair<int, int>> q;
    q.push({si, sj});
    tb.at(si).at(sj) = sz;
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      rep(k, 8) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (s.at(ni).at(nj) == '.' || tb.at(ni).at(nj) != -1) continue;
        tb.at(ni).at(nj) = sz;
        q.push({ni, nj});
      }
    }
    sz++;
  }
  cout << sz << endl;
  return 0;
}