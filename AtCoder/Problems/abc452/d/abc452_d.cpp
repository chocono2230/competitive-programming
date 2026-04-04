#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  vector dp(s.size() + 1, vector<ll>(t.size() + 1, 0));
  rep(i, s.size()) {
    int si = 0;
    if (s.at(i) == t.at(0)) si = 1;
    dp.at(i + 1).at(si) += 1;
    rep(j, t.size()) {
      int nj = j;
      if (s.at(i) == t.at(j)) nj++;
      dp.at(i + 1).at(nj) += dp.at(i).at(j);
    }
  }
  ll ans = 0;
  rep(i, s.size()) rep(j, t.size()) { ans += dp.at(i + 1).at(j); }
  cout << ans << endl;
  return 0;
}