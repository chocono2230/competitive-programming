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
  vector<int> ans(2 * n + 2, 0);
  rep(i, n) {
    int now = a.at(i);
    int p = 2 * (i + 1), q = 2 * (i + 1) + 1;
    ans.at(p) = ans.at(q) = ans.at(now) + 1;
  }
  rep2(i, 1, 2 * n + 2) { cout << ans.at(i) << endl; }
  return 0;
}