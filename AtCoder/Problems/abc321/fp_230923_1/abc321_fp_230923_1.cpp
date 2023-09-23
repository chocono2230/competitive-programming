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
  int q, k;
  cin >> q >> k;
  vector<mint> dp(k + 1, 0);
  dp.front() = 1;
  while (q--) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '+') {
      rrep2(i, x, k + 1) dp.at(i) += dp.at(i - x);
    } else {
      rep2(i, x, k + 1) dp.at(i) -= dp.at(i - x);
    }
    cout << dp.back().val() << endl;
  }
  return 0;
}