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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int ans = 0;
  rep(bit, 1 << n) {
    int add = 0;
    ll now = 0;
    rep(i, n) {
      int p = 1;
      if ((bit & (1 << i)) != 0) p = -1;
      ll nx = now + a.at(i) * p;
      if (now >= 0 && nx < 0 || now < 0 && nx >= 0) add++;
      now = nx;
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}