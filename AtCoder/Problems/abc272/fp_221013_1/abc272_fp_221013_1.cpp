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

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string x = s + s + "$" + t + t + "~";
  auto v = suffix_array(x);
  ll ans = 0, ss = 0;
  for (auto i : v) {
    if (i < n) ss++;
    if (2 * n + 1 <= i && i < 3 * n + 1) ans += ss;
  }
  cout << ans << endl;
  return 0;
}