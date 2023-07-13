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
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  rep(i, n) {
    int in;
    cin >> in;
    int co = min(k, in / x);
    k -= co;
    in -= co * x;
    a.at(i) = in;
  }
  sort(ALL(a));
  rrep(i, n) {
    if (k == 0) break;
    k--;
    a.at(i) = 0;
  }
  ll ans = reduce(ALL(a), 0LL);
  cout << ans << endl;
  return 0;
}