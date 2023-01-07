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
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    for (ll i = 2; i <= 1e7; i++) {
      if (n % i != 0) continue;
      ll x = n / i;
      if (x % i == 0) {
        cout << i << " " << x / i << endl;
      } else {
        ll zz = sqrt(x);
        for (ll j = zz - 5; j < zz + 5; j++) {
          if (j * j == x) {
            cout << j << " " << i << endl;
          }
        }
      }
      break;
    }
  }
  return 0;
}