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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);

  vector dp(n, vector<mint>(n, 0));
  dp.front().front() = 1;
  rep(i, n - 1) {
    int ni = i + 1, mode = 0;
    if (h.at(i) < h.at(i + 1)) mode = 1;
    if (h.at(i) > h.at(i + 1)) mode = 2;
    if (mode == 1) {
      mint sum = 0;
      rrep(j, ni) {
        sum += dp.at(i).at(j);
        dp.at(ni).at(j) = sum;
      }
    }
    if (mode == 2) {
      mint sum = 0;
      rep2(j, 1, ni + 1) {
        sum += dp.at(i).at(j - 1);
        dp.at(ni).at(j) = sum;
      }
    }
    if (mode == 0) {
      mint sum = reduce(ALL(dp.at(i)));
      rep(j, ni + 1) { dp.at(ni).at(j) = sum; }
    }
  }
  // rep(i, n) {
  //   rep(j, n) cerr << dp.at(i).at(j).val() << " ";
  //   cerr << endl;
  // }
  mint ans = reduce(ALL(dp.back()));
  cout << ans.val() << endl;
  return 0;
}