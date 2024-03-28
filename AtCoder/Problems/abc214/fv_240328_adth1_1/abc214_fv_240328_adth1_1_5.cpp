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
using mint = modint1000000007;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<mint> dp(n + 2, 0);
  dp.front() = 1;
  rep(i, n) {
    rrep2(j, -1, i) {
      dp.at(i + 2) += dp.at(j + 1);
      if (j == -1 || s.at(j) == s.at(i)) break;
    }
  }
  mint ans = reduce(ALL(dp)) - 1;
  cout << ans.val() << endl;
  return 0;
}