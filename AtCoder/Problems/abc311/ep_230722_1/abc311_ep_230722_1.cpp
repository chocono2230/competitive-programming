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
  int h, w, n;
  cin >> h >> w >> n;
  vector tb(h, vector<bool>(w, false));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tb.at(a).at(b) = true;
  }
  vector dp(h, vector<int>(w, 0));
  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (tb.at(i).at(j)) continue;
    if (i == 0 || j == 0) {
      dp.at(i).at(j) = 1;
      ans++;
      continue;
    }
    int add =
        min({dp.at(i - 1).at(j), dp.at(i).at(j - 1), dp.at(i - 1).at(j - 1)}) +
        1;
    ans += add;
    dp.at(i).at(j) = add;
  }
  cout << ans << endl;
  return 0;
}