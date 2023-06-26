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
  int a, b;
  cin >> a >> b;
  bool ans = false;
  if (b == 10) {
    if (a == 1 || a == 9) ans = true;
  } else {
    if (a + 1 == b) ans = true;
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}