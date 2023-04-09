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
  int n, d;
  cin >> n >> d;
  vector<int> t(n);
  rep(i, n) cin >> t.at(i);
  int ans = -1;
  rep(i, n - 1) {
    if (t.at(i + 1) - t.at(i) <= d) {
      ans = t.at(i + 1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}