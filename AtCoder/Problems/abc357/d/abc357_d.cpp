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
  ll n;
  cin >> n;
  string s = to_string(n);
  mint pw = 1;
  mint dd = 10;
  dd = dd.pow(s.size());
  mint z = dd.pow(n);
  z -= 1;
  z /= dd - mint(1);
  // cerr << z.val() << endl;
  mint ans = 0;
  rrep(i, s.size()) {
    int now = s.at(i) - '0';
    mint sum = pw * z;
    ans += sum * now;
    pw *= 10;
  }
  cout << ans.val() << endl;
  return 0;
}