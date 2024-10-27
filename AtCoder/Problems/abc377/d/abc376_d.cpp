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
  vector<int> v(m, -1);
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    v.at(r) = max(v.at(r), l);
  }
  int l = -1;
  ll ans = 0;
  rep(r, m) {
    l = max(l, v.at(r));
    ans += r - l;
  }
  cout << ans << endl;

  return 0;
}