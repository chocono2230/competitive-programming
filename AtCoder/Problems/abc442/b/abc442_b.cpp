#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int q;
  cin >> q;
  int now = 0, flg = 0;
  while (q--) {
    int in;
    cin >> in;
    if (in == 1) {
      now++;
    }
    if (in == 2) {
      now = max(0, now - 1);
    }
    if (in == 3) {
      flg ^= 1;
    }
    if (flg == 1 && now >= 3)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}