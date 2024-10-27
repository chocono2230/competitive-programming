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
  set<pair<int, int>> se;
  int di[] = {2, 2, 1, 1, -1, -1, -2, -2}, dj[] = {1, -1, 2, -2, 2, -2, 1, -1};
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    se.insert({a, b});
    rep(k, 8) {
      int ni = a + di[k], nj = b + dj[k];
      if (ni < 0 || n <= ni || nj < 0 || n <= nj) continue;
      se.insert({ni, nj});
    }
  }
  ll ans = (ll)n * n;
  ans -= se.size();
  cout << ans << endl;
  return 0;
}