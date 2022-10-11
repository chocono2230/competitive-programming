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
  int t;
  cin >> t;
  int co = 0, x = 0, y = 0;
  for (auto c : s) {
    if (c == 'L') x--;
    if (c == 'R') x++;
    if (c == 'U') y++;
    if (c == 'D') y--;
    if (c == '?') co++;
  }
  int ans = 0;
  if (t == 1)
    ans = abs(x) + abs(y) + co;
  else {
    if (abs(x) + abs(y) >= co)
      ans = abs(x) + abs(y) - co;
    else
      ans = (((abs(x) + abs(y)) % 2 == co % 2) ? 0 : 1);
  }
  cout << ans << endl;
  return 0;
}