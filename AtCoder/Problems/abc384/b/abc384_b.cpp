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
  int n, r;
  cin >> n >> r;
  rep(i, n) {
    int d, a;
    cin >> d >> a;
    bool f = false;
    f |= (d == 1 && 1600 <= r && r < 2800);
    f |= (d == 2 && 1200 <= r && r < 2400);
    if (f) {
      r += a;
    }
  }
  cout << r << endl;
  return 0;
}