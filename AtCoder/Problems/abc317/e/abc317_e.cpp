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
  auto chk = [](char x) {
    if (x == '.') return true;
    if (x == 'S') return true;
    if (x == 'G') return true;
    if (x == '@') return true;
    return false;
  };
  auto fc = [&](int si, int sj, int di, int dj) {
    int i = si + di, j = sj + dj;
    while (1) {
      if (i < 0 || h <= i || j < 0 || w <= j) break;
      if (!chk(s.at(i).at(j))) break;
      s.at(i).at(j) = '@';
      i += di;
      j += dj;
    }
  };
  rep(i, h) rep(j, w) {
    char c = s.at(i).at(j);
    if (c == '^') fc(i, j, -1, 0);
    if (c == 'v') fc(i, j, 1, 0);
    if (c == '>') fc(i, j, 0, 1);
    if (c == '<') fc(i, j, 0, -1);
  }
  int si = -1, sj = -1, gi = -1, gj = -1;
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == 'S') {
      si = i;
      sj = j;
    }
    if (s.at(i).at(j) == 'G') {
      gi = i;
      gj = j;
    }
  }
  queue<pair<int, int>> q;
  vector tb(h, vector<int>(w, -1));
  q.push({si, sj});
  tb.at(si).at(sj) = 0;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (!chk(s.at(ni).at(nj)) || s.at(ni).at(nj) == '@') continue;
      if (tb.at(ni).at(nj) != -1) continue;
      tb.at(ni).at(nj) = tb.at(i).at(j) + 1;
      q.push({ni, nj});
    }
  }
  cout << tb.at(gi).at(gj) << endl;
  return 0;
}