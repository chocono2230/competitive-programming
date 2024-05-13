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
  int k, g, m;
  cin >> k >> g >> m;
  int a = 0, b = 0;
  while (k--) {
    if (a == g) {
      a = 0;
      continue;
    }
    if (b == 0) {
      b = m;
      continue;
    }
    int add = min(g - a, b);
    a += add;
    b -= add;
  }
  cout << a << " " << b << endl;
  return 0;
}