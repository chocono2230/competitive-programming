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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  auto fc = [](vector<string> &ss) -> bool {
    rep(i, 3) rep(j, 3) {
      if (ss.at(i).at(j) == '.') return false;
      if (ss.at(i + 6).at(j + 6) == '.') return false;
    }
    rep(i, 4) {
      if (ss.at(3).at(i) == '#') return false;
      if (ss.at(i).at(3) == '#') return false;
      if (ss.at(5).at(8 - i) == '#') return false;
      if (ss.at(8 - i).at(5) == '#') return false;
    }
    return true;
  };

  vector<pair<int, int>> ans;
  rep(i, n) rep(j, m) {
    int ri = i + 9, rj = j + 9;
    if (ri > n || rj > m) continue;
    vector<string> t(9, string(9, '.'));
    rep(ii, 9) rep(jj, 9) { t.at(ii).at(jj) = s.at(ii + i).at(jj + j); }
    if (fc(t)) ans.push_back({i, j});
  }
  for (auto [i, j] : ans) cout << i + 1 << " " << j + 1 << endl;
  return 0;
}