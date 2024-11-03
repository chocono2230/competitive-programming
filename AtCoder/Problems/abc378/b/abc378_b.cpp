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
  int n;
  cin >> n;
  vector<pair<int, int>> qr(n);
  rep(i, n) {
    int q, r;
    cin >> q >> r;
    qr.at(i) = {q, r};
  }
  int qe;
  cin >> qe;
  while (qe--) {
    int t, d;
    cin >> t >> d;
    t--;
    auto [q, r] = qr.at(t);
    int m = d % q;
    if (m <= r) {
      d = d / q * q + r;
    } else {
      d = (d + q - 1) / q * q + r;
    }
    cout << d << endl;
  }
  return 0;
}