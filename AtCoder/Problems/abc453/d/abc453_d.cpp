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
  vector d(h, vector(w, vector<int>(4, INF)));
  vector memo(h, vector(w, vector<tuple<int, int, int>>(4, {-1, -1, -1})));
  queue<tuple<int, int, int>> q;
  int si = -1, sj = -1;
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == 'S') {
      q.push({i, j, 0});
      d.at(i).at(j).at(0) = 0;
      si = i, sj = j;
    }
  }
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  int pi, pj, pk = -1;
  while (!q.empty()) {
    auto [i, j, k] = q.front();
    q.pop();
    if (s.at(i).at(j) == 'G') {
      pi = i;
      pj = j;
      pk = k;
      break;
    }
    int flg = 0;
    if (s.at(i).at(j) == 'o') flg = 1;
    if (s.at(i).at(j) == 'x') flg = 2;
    rep(nk, 4) {
      int ni = i + di[nk], nj = j + dj[nk];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (s.at(ni).at(nj) == '#') continue;
      if (flg == 1 && nk != k) continue;
      if (flg == 2 && nk == k) continue;
      if (d.at(ni).at(nj).at(nk) != INF) continue;
      d.at(ni).at(nj).at(nk) = d.at(i).at(j).at(k) + 1;
      memo.at(ni).at(nj).at(nk) = {i, j, k};
      q.push({ni, nj, nk});
    }
  }

  if (pk == -1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  string ans;
  while (pi != si || pj != sj) {
    auto [ni, nj, nk] = memo.at(pi).at(pj).at(pk);
    char c;
    if (ni == pi) {
      if (nj + 1 == pj)
        c = 'R';
      else
        c = 'L';
    } else {
      if (ni + 1 == pi)
        c = 'D';
      else
        c = 'U';
    }
    ans.push_back(c);
    pi = ni, pj = nj, pk = nk;
  }
  reverse(ALL(ans));
  cout << ans << endl;
  return 0;
}