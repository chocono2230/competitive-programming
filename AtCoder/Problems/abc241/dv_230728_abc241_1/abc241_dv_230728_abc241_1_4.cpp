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
  int q;
  cin >> q;
  multiset<ll> se;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      ll x;
      cin >> x;
      se.insert(x);
    }
    if (mode == 2) {
      ll x;
      int k;
      cin >> x >> k;
      auto itr = se.upper_bound(x);
      bool f = false;
      rep(i, k) {
        if (itr == se.begin()) {
          f = true;
          break;
        }
        itr--;
      }
      cout << (f ? -1 : *itr) << endl;
    }
    if (mode == 3) {
      ll x;
      int k;
      cin >> x >> k;
      auto itr = se.lower_bound(x);
      rep(i, k - 1) {
        if (itr != se.end()) itr++;
      }
      cout << (itr == se.end() ? -1 : *itr) << endl;
    }
  }
  return 0;
}