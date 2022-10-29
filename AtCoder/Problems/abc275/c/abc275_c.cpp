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
  vector<string> s(9);
  rep(i, 9) cin >> s.at(i);
  int n = 9;
  set<vector<pair<int, int>>> se;
  rep(i, n) rep(j, n) {
    if (s.at(i).at(j) == '.') continue;
    rep(di, 9) rep(dj, 9) {
      if (di == 0 && dj == 9) continue;
      auto fc = [&](int pi, int pj) -> bool {
        if (pi == 0 && pj == 0) return false;
        int qi = pi + i, qj = pj + j;
        if (qi < 0 || n <= qi || qj < 0 || n <= qj) return false;
        return s.at(qi).at(qj) == '#';
      };
      if (!fc(di, dj)) continue;
      if (!fc(di - dj, dj + di)) continue;
      if (!fc(-dj, di)) continue;
      vector<pair<int, int>> v = {{i, j},
                                  {i + di, j + dj},
                                  {i + di - dj, j + dj + di},
                                  {i - dj, j + di}};
      sort(ALL(v));
      se.insert(v);
    }
  }
  // for (auto v : se) {
  //   for (auto p : v) cerr << p.first << ":" << p.second << "  ";
  //   cerr << endl;
  // }
  cout << se.size() << endl;
  return 0;
}