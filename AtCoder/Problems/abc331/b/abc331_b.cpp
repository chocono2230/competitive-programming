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
  int n, s, m, l;
  cin >> n >> s >> m >> l;
  int ans = 1001001001;
  rep(i, n + 1) rep(j, n + 1) rep(k, n + 1) {
    int co = i * 6;
    co += j * 8;
    co += k * 12;
    if (co < n) continue;
    ans = min(ans, i * s + j * m + k * l);
  }
  cout << ans << endl;
  return 0;
}