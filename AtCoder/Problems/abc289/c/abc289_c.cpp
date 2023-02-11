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
  vector<int> tb(m, 0);
  rep(i, m) {
    int co;
    cin >> co;
    rep(j, co) {
      int in;
      cin >> in;
      in--;
      tb.at(i) |= (1 << in);
    }
  }
  int ans = 0;
  rep(bit, 1 << m) {
    int now = 0;
    rep(i, m) {
      if ((bit & (1 << i)) != 0) now |= tb.at(i);
    }
    if (now == ((1 << n) - 1)) ans++;
  }
  cout << ans << endl;
  return 0;
}