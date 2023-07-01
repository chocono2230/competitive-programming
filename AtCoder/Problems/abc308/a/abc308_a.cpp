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
  vector<int> a(8);
  rep(i, 8) cin >> a.at(i);
  bool f = false;
  rep(i, 7) {
    if (a.at(i) > a.at(i + 1)) f = true;
  }
  for (auto now : a) {
    if (now < 100 || 675 < now) f = true;
    if (now % 25 != 0) f = true;
  }
  if (f)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}