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
  bool f = false;
  int x = -1, y = -1;
  rep(i, s.size()) {
    if (s.at(i) == 'B') {
      if (x == -1)
        x = i;
      else
        y = i;
    }
  }
  if (x % 2 == y % 2) f = true;
  x = -1, y = -1;
  rep(i, s.size()) {
    if (s.at(i) == 'R') {
      if (x == -1)
        x = i;
      else
        y = i;
    }
  }
  rep(i, s.size()) {
    if (s.at(i) == 'K') {
      if (i < x || y < i) f = true;
    }
  }
  if (!f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}