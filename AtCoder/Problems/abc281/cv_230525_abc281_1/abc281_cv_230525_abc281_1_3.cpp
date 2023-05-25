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
  ll t;
  cin >> n >> t;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> sums(n + 1, 0);
  rep(i, n) sums.at(i + 1) = sums.at(i) + a.at(i);
  t %= sums.back();
  rep2(i, 1, n + 1) {
    if (t < sums.at(i)) {
      cout << i << " " << t - sums.at(i - 1) << endl;
      return 0;
    }
  }
  return 0;
}