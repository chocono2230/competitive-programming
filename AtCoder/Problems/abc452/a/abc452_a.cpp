#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int m, d;
  cin >> m >> d;
  bool f = false;
  if (m < 10 && m % 2 == 1) {
    if (m == 1) {
      if (d == 7) f = true;
    } else {
      if (m == d) f = true;
    }
  }
  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}