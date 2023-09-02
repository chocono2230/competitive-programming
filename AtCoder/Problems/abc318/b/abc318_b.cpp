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
  vector tb(105, vector<bool>(105, false));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    rep2(i, a, b) rep2(j, c, d) tb.at(i).at(j) = true;
  }
  int ans = 0;
  rep(i, 105) rep(j, 105) if (tb.at(i).at(j)) ans++;
  cout << ans << endl;
  return 0;
}