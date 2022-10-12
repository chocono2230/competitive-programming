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
  set<int> se;
  se.insert(0);
  se.insert(l);
  rep(i, q) {
    int c, x;
    cin >> c >> x;
    if (c == 1)
      se.insert(x);
    else {
      auto itr = se.lower_bound(x);
      auto pitr = itr;
      pitr--;
      cout << *itr - *pitr << endl;
    }
  }
  return 0;
}