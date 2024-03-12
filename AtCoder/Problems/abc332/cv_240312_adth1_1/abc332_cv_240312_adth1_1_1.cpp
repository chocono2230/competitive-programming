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
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ans = 0, now = 0, mm = m;
  for (auto c : s) {
    if (c == '0') {
      now = 0;
      mm = m;
      continue;
    }
    if (c == '1') {
      if (mm != 0) {
        mm--;
      } else {
        now++;
      }
    } else {
      now++;
    }
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}