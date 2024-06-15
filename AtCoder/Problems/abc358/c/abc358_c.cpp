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
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  rep(i, n) {
    string s;
    cin >> s;
    int bb = 0;
    rep(i, m) {
      bb <<= 1;
      if (s.at(i) == 'o') bb++;
    }
    v.at(i) = bb;
  }
  int msk = (1 << m) - 1;
  int ans = 1001001001;
  rep2(bit, 1, 1 << n) {
    int now = 0;
    rep(i, n) {
      if ((bit & (1 << i)) == 0) continue;
      now |= v.at(i);
    }
    if (now == msk) {
      ans = min(ans, popcount((unsigned int)bit));
    }
  }
  cout << ans << endl;
  return 0;
}