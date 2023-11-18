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
  string s, t;
  cin >> s >> t;
  vector dp(n, vector<bool>(m, false));
  if (s.front() != t.front()) {
    cout << "No" << endl;
    return 0;
  }
  dp.front().front() = true;
  rep(i, n - 1) {
    int ni = i + 1;
    rep(j, m) {
      if (!dp.at(i).at(j)) continue;
      if (s.at(ni) == t.front()) dp.at(ni).at(0) = true;
      if (j != m - 1 && s.at(ni) == t.at(j + 1)) dp.at(ni).at(j + 1) = true;
      if (j == m - 1) {
        rep(k, m) {
          if (s.at(ni) == t.at(k)) dp.at(ni).at(k) = true;
        }
      }
    }
  }
  // rep(i, n) {
  //   cerr << i;
  //   rep(j, m) cerr << " " << dp.at(i).at(j);
  //   cerr << endl;
  // }
  if (dp.back().back())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}