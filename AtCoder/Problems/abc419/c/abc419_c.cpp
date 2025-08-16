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
  int l = 1e9 + 5, r = -1, t = 1e9 + 5, b = -1;
  rep(i, n) {
    int ir, c;
    cin >> ir >> c;
    l = min(l, c);
    r = max(r, c);
    t = min(t, ir);
    b = max(b, ir);
  }
  int w = r - l, h = b - t;
  int ans = max((w + 1) / 2, (h + 1) / 2);
  cout << ans << endl;
  return 0;
}