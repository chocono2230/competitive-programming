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
  const string S = "snuke";
  vector tb(h, vector<int>(w, -1));
  queue<pair<int, int>> q;
  if (s.front().front() == 's') {
    q.push({0, 0});
    tb.at(0).at(0) = 0;
  }
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (tb.at(ni).at(nj) != -1) continue;
      int idx = (tb.at(i).at(j) + 1) % S.size();
      if (s.at(ni).at(nj) != S.at(idx)) continue;
      tb.at(ni).at(nj) = tb.at(i).at(j) + 1;
      q.push({ni, nj});
    }
  }
  if (tb.back().back() != -1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}