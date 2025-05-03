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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<string> t(n);
  rep(i, n) cin >> t.at(i);
  auto rc = [&]() -> void {
    auto tt = s;
    rep(i, n) rep(j, n) { s.at(j).at(n - 1 - i) = tt.at(i).at(j); }
  };
  int ans = 1001001001;
  rep(i, 4) {
    int now = i;
    rep(i, n) rep(j, n) {
      if (s.at(i).at(j) != t.at(i).at(j)) now++;
    }
    ans = min(ans, now);
    rc();
  }
  cout << ans << endl;
  return 0;
}