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
  int n;
  ll x;
  cin >> n >> x;
  string s;
  cin >> s;
  string t;
  for (auto c : s) {
    if (c == 'U') {
      if (!t.empty() && t.back() != 'U')
        t.pop_back();
      else
        t.push_back(c);
    } else {
      t.push_back(c);
    }
  }
  for (auto c : t) {
    if (c == 'U') x /= 2;
    if (c == 'L') x *= 2;
    if (c == 'R') x = (x * 2) + 1;
  }
  cout << x << endl;
  return 0;
}