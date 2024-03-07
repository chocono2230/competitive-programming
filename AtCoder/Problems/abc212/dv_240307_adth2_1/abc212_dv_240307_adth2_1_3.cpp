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
  ll sum = 0;
  multiset<ll> se;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      ll x;
      cin >> x;
      x -= sum;
      se.insert(x);
    }
    if (mode == 2) {
      ll x;
      cin >> x;
      sum += x;
    }
    if (mode == 3) {
      auto itr = se.begin();
      cout << *itr + sum << endl;
      se.erase(itr);
    }
  }
  return 0;
}