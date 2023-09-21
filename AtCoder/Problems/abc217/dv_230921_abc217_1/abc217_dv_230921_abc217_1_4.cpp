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
  int l, q;
  cin >> l >> q;
  map<int, int> mp;
  mp[0] = l;
  while (q--) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      auto itr = mp.upper_bound(x);
      itr--;
      int t = itr->second;
      itr->second = x;
      mp[x] = t;
    } else {
      auto itr = mp.upper_bound(x);
      itr--;
      cout << itr->second - itr->first << endl;
    }
  }
  return 0;
}