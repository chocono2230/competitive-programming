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
  ll a, b, c;
  cin >> a >> b >> c;
  if (a == b || (abs(a) == abs(b) && c % 2 == 0)) {
    cout << "=" << endl;
    return 0;
  }
  ll mn = min(a, b), mx = max(a, b);
  if (mx < 0 && c % 2 == 1) {
    if (a < b)
      cout << "<" << endl;
    else
      cout << ">" << endl;
    return 0;
  }
  if (mn < 0 && c % 2 == 1) {
    if (mn == a)
      cout << "<" << endl;
    else
      cout << ">" << endl;
    return 0;
  }
  a = abs(a);
  b = abs(b);
  if (a < b)
    cout << "<" << endl;
  else
    cout << ">" << endl;
  return 0;
}