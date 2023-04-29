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
  vector<int> ans(min(h, w), 0);
  int di[] = {1, 1, -1, -1}, dj[] = {1, -1, 1, -1};
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '.' || tb.at(i).at(j) != -1) continue;
    queue<pair<int, int>> q;
    q.push({i, j});
    int co = 0;
    tb.at(i).at(j) = 1;
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      co++;
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        if (s.at(ni).at(nj) == '.' || tb.at(ni).at(nj) != -1) continue;
        tb.at(ni).at(nj) = 1;
        q.push({ni, nj});
      }
    }
    int idx = (co - 1) / 4 - 1;
    ans.at(idx)++;
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}