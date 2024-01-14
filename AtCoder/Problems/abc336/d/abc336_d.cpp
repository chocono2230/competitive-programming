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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> l(n, -1), r(n, -1);
  int mn = 0;
  rep(i, n) {
    mn++;
    if (a.at(i) < mn) {
      mn = a.at(i);
    }
    l.at(i) = mn;
  }
  mn = 0;
  rrep(i, n) {
    mn++;
    if (a.at(i) < mn) {
      mn = a.at(i);
    }
    r.at(i) = mn;
  }
  int ans = 0;
  rep(i, n) ans = max(ans, min(l.at(i), r.at(i)));
  cout << ans << endl;
  return 0;
}