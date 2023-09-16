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
  string s;
  cin >> s;
  int ans = -1;
  rep(i, s.size()) {
    rep2(j, 1, s.size() + 1) {
      if (i + j > s.size()) break;
      string p = s.substr(i, j);
      string q = p;
      reverse(ALL(p));
      if (p == q) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}