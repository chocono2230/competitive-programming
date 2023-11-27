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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  map<int, int> mp;
  mp[0]++;
  ll ans = 0;
  vector<int> memo;
  memo.push_back(0);
  ll s = 0;
  rep2(i, 1, n + 1) {
    s += a.at(i - 1);
    ll p = s - i;
    if (p < 0) {
      int m = ((-p) + k - 1) / k;
      p += m * k;
    }
    p %= k;
    memo.push_back(p);
    if (i >= k) {
      mp[memo.at(i - k)]--;
    }
    ans += mp[p];
    // cerr << p << " " << ans << endl;
    mp[p]++;
  }
  cout << ans << endl;

  return 0;
}