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
  vector<tuple<int, int, int>> v;
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) != '#' && s.at(i).at(j) != '.') {
      v.push_back({i, j, s.at(i).at(j) - '0'});
    }
  }
  vector<string> ans(h, string(w, '.'));
  rep(i, h) rep(j, w) {
    if (s.at(i).at(j) == '.') continue;
    bool f = false;
    for (auto [ii, jj, x] : v) {
      int d = abs(ii - i) + abs(jj - j);
      if (d <= x) f = true;
    }
    if (!f) ans.at(i).at(j) = '#';
  }
  for (auto ss : ans) cout << ss << endl;
  return 0;
}