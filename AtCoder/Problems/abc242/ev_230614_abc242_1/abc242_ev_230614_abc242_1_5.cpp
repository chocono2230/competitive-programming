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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<mint> dp(n + 1, 0);
    auto rs = s.substr(0, n / 2);
    auto rrs = rs;
    reverse(ALL(rrs));
    bool chk = false;
    if (n % 2 == 0)
      chk = ((rs + rrs) <= s);
    else
      chk = (rs + s.at(n / 2) + rrs <= s);
    mint ans = 0;
    rep(i, dp.size()) {
      int ni = i + 1;
      int ri = n - i - 1;
      if (ri < i) {
        ans = dp.at(i);
        if (chk) ans++;
        break;
      }
      int lo = s.at(i) - 'A';
      dp.at(ni) = dp.at(i) * 26 + lo;
    }
    cout << ans.val() << endl;
  }
  return 0;
}