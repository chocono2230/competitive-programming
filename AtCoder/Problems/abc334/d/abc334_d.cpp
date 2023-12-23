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
  int n, q;
  cin >> n >> q;
  vector<int> r(n);
  rep(i, n) cin >> r.at(i);
  sort(ALL(r));
  vector<ll> sums(n + 1, 0);
  rep(i, n) sums.at(i + 1) = sums.at(i) + r.at(i);
  while (q--) {
    ll x;
    cin >> x;
    int idx = upper_bound(ALL(sums), x) - sums.begin() - 1;
    cout << idx << endl;
  }
  return 0;
}