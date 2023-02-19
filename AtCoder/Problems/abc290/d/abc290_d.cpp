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
    ll n, d, k;
    cin >> n >> d >> k;
    k--;
    if (k == 0) {
      cout << 0 << endl;
      continue;
    }
    ll g = gcd(n, d);
    ll z = n / g;
    ll ml = k / z;
    k %= z;
    ll pl = d * k;
    ll ans = (ml + pl) % n;
    // cerr << n << " " << d << " " << k << " " << g << " " << z << " " << ml
    //      << " " << pl << endl;
    cout << ans << endl;
  }
  // rep2(n, 1, 50) rep2(d, 1, n + 1) {
  //   vector<int> ans(n, -1);
  //   int now = 0, co = 0;
  //   ans.at(now) = co++;
  //   int z = 1;
  //   while (co != n) {
  //     now += d;
  //     now %= n;
  //     bool f = false;
  //     while (ans.at(now) != -1) {
  //       if (!f) {
  //         z++;
  //         f = true;
  //       }
  //       now++;
  //       now %= n;
  //     }
  //     ans.at(now) = co++;
  //   }
  //   rep(i, n) { cout << ans.at(i) << " "; }
  //   cout << endl;
  //   cout << z << " " << gcd(n, d) << endl;
  //   assert(z == gcd(n, d));
  // }
  return 0;
}