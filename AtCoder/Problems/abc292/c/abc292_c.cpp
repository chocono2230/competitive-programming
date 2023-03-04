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
  vector<int> co(n + 1, 0);
  rep2(i, 1, n + 1) {
    rep2(j, 1, n + 1) {
      if (i * j > n) break;
      co.at(i * j)++;
    }
  }
  ll ans = 0;
  rep2(i, 1, n) {
    int j = n - i;
    ans += (ll)co.at(i) * co.at(j);
  }
  cout << ans << endl;
  return 0;
}