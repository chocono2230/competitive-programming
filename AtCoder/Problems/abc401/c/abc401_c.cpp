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
  ll md = 1000000000;
  int n, k;
  cin >> n >> k;
  vector<ll> ans(n + 1, 1);
  ll sum = k;
  rep(i, n + 1) {
    if (i < k) continue;
    ans.at(i) = sum;
    sum += ans.at(i) - ans.at(i - k);
    sum += md;
    sum %= md;
  }
  cout << ans.back() << endl;
  return 0;
}