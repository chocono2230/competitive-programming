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
  vector<ll> v;
  vector<ll> sums(1, 0);
  int d = 0;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      ll x;
      cin >> x;
      v.push_back(x);
      sums.push_back(sums.back() + x);
    }
    if (mode == 2) {
      d++;
    }
    if (mode == 3) {
      int in;
      cin >> in;
      in--;
      ll ans = sums.at(in + d) - sums.at(d);
      cout << ans << endl;
    }
  }
  return 0;
}