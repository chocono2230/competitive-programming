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
using mint = modint998244353;

int main() {
  ll n, m;
  cin >> n >> m;
  mint ans = 0;
  rep(i, 60) {
    ll pw = (1LL << i);
    ll pw2 = (1LL << (i + 1));
    if ((m & pw) == 0) continue;

    mint add = n / pw2;
    add *= pw;
    ll npw = n % pw2;
    npw -= (pw - 1);
    add += max(0LL, npw);
    ans += add;
  }
  cout << ans.val() << endl;
  return 0;
}