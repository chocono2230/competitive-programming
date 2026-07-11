#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int r = 1;
  rep(i, n) {
    if (i == r) r++;
    while (1) {
      if (r == n) break;
      cout << "? " << i + 1 << " " << r + 1 << endl;
      string in;
      cin >> in;
      if (in == "Yes") {
        r++;
      } else {
        break;
      }
    }
    ans += r - i - 1;
  }
  cout << "! " << ans << endl;
  return 0;
}