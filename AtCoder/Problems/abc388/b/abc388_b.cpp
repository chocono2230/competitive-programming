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
  vector<pair<int, int>> tl(n);
  rep(i, n) {
    int t, l;
    cin >> t >> l;
    tl.at(i) = {t, l};
  }
  rep(k, d) {
    int mx = 0;
    for (auto [t, l] : tl) {
      mx = max(mx, t * (l + k + 1));
    }
    cout << mx << endl;
  }
  return 0;
}