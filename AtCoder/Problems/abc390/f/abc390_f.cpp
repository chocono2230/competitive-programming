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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  ll ans = 0;
  rep(i, n) { ans += (ll)(i + 1) * (n - i); }
  vector<int> memo(n + 2, -1);
  dsu uf(n);
  vector<int> dp(n, -1);
  rep(i, n) {
    int now = a.at(i);
    if (memo.at(now) != -1) {
      int ldidx = dp.at(uf.leader(now));
      if (a.at(ldidx) == memo.at(now)) ans -= (ll)(memo.at(now) + 1) * (n - i);
    }
    memo.at(now) = i;
    dp.at(uf.leader(now)) = i;
    if (memo.at(now + 1) != -1) {
      if (uf.same(now, now + 1)) ans -= (ll)(memo.at(now + 1) + 1) * (n - i);
      // flg.at(now + 1) = true;
    }
    if (memo.at(now - 1) != -1) {
      cerr << i << " " << now << " " << (ll)(memo.at(now - 1) + 1) * (n - i)
           << endl;
      ans -= (ll)(memo.at(now - 1) + 1) * (n - i);
      // flg.at(now - 1) = true;
    }
  }
  cout << ans << endl;
  return 0;
}