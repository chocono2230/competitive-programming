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
  ll x, k;
  cin >> x >> k;
  ll p = 1;
  rep(i, k) {
    string s = to_string(x);
    if (s.size() <= i) {
      x = 0;
      break;
    }
    int now = s.at(s.size() - 1 - i) - '0';
    cerr << now << " " << x << endl;
    p *= 10;
    x /= p;
    if (now >= 5) {
      x++;
    }
    x *= p;
  }
  cout << x << endl;
  return 0;
}