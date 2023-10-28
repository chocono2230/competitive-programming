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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<mint> p(n + 1, 0);
  vector<mint> sump(n + 1, 0);
  p.at(0) = sump.at(0) = 1;
  mint invn = mint(1) / n;
  rep2(i, 1, n + 1) {
    p.at(i) = sump.at(i - 1) * invn;
    sump.at(i) = sump.at(i - 1) + p.at(i);
  }
  mint ans = 0;
  rep2(i, 1, n + 1) { ans += p.at(i) * a.at(i - 1); }
  cout << ans.val() << endl;
  return 0;
}