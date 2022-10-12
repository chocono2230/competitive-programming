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
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);
  sort(ALL(c), greater<int>());
  mint ans = 0, co = 1, now = 0;
  vector<mint> p2(n + 5, 1);
  rep2(i, 1, n + 5) p2.at(i) = p2.at(i - 1) * 2;
  rep(i, n) {
    mint add = c.at(i);
    add *= now + co;
    ans += add * p2.at(n - i - 1);

    // cerr << add.val() << " " << now.val() << " " << co.val() << " "
    //      << p2.at(n - i - 1).val() << " " << ans.val() << endl;
    now = now * 2 + co;
    co *= 2;
  }
  ans *= mint(2).pow(n);
  cout << ans.val() << endl;
  return 0;
}