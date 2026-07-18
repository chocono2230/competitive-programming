#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    auto fc = [](ll &a, ll &b, ll &c) {
      ll px, py;
      cin >> px >> py;
      ll qx, qy;
      cin >> qx >> qy;
      a = (qx - px) * 2;
      b = (qy - py) * 2;
      c = qx * qx - px * px + qy * qy - py * py;
      ll g = gcd(a, gcd(b, c));
      a /= g;
      b /= g;
      c /= g;
      if (a < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
      }
      if (a == 0 && b < 0) {
        b *= -1;
        c *= -1;
      }
    };
    ll pa, pb, pc, qa, qb, qc;
    fc(pa, pb, pc);
    fc(qa, qb, qc);
    if (pb * qa - qb * pa == 0) {
      if (pa == qa && pb == qb && pc == qc)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    } else
      cout << "Yes" << endl;
  }
  return 0;
}