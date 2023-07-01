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
  multiset<int> base, ans;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      cin >> x;
      auto itrb = base.lower_bound(x);
      if (itrb != base.end() && itrb != base.begin()) {
        auto pitr = prev(itrb);
        int z = (*itrb) ^ (*pitr);
        ans.erase(ans.lower_bound(z));
      }

      base.insert(x);
      auto itr = base.lower_bound(x);
      if (itr != base.begin()) {
        auto pitr = prev(itr);
        ans.insert((*pitr) ^ (*itr));
      }
      auto nxitr = next(itr);
      if (nxitr != base.end()) {
        ans.insert((*nxitr) ^ (*itr));
      }
    }
    if (mode == 2) {
      int x;
      cin >> x;
      auto itr = base.lower_bound(x);
      if (itr != base.begin()) {
        auto pitr = prev(itr);
        int z = ((*pitr) ^ (*itr));
        ans.erase(ans.lower_bound(z));
      }
      auto nxitr = next(itr);
      if (nxitr != base.end()) {
        int z = ((*nxitr) ^ (*itr));
        ans.erase(ans.lower_bound(z));
      }
      base.erase(itr);

      auto itrb = base.lower_bound(x);
      if (itrb != base.end() && itrb != base.begin()) {
        auto pitr = prev(itrb);
        int z = (*itrb) ^ (*pitr);
        ans.insert(z);
      }
    }
    if (mode == 3) {
      int a = *ans.begin();
      cout << a << endl;
    }
  }
  return 0;
}