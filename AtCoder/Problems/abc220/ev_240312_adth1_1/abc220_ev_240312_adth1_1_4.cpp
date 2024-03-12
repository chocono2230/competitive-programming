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
  int n, d;
  cin >> n >> d;
  vector<mint> pw(1, 1);
  rep(i, max(d, n) + 5) pw.push_back(pw.back() * 2);
  mint ans = 0;
  rep(i, d + 1) {
    int j = d - i;
    if (i >= n || j >= n) continue;
    mint add = pw.at(n - max(i, j)) - 1;
    add *= pw.at(max(i - 1, 0));
    add *= pw.at(max(j - 1, 0));
    ans += add;
  }
  ans *= 2;
  cout << ans.val() << endl;
  return 0;
}