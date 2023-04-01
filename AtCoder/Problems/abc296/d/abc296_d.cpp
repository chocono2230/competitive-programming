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

map<ll, ll> prime_factorization(ll n) {
  map<ll, ll> ans;
  ll a = 2;
  while (n >= a * a) {
    if (n % a == 0) {
      ans[a]++;
      n /= a;
    } else {
      a++;
    }
  }
  ans[n]++;

  return ans;
}

int main() {
  ll n, m;
  cin >> n >> m;
  if (n < LLONG_MAX / n && n * n < m) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = -1;
  for (ll i = 1; i <= min(10000000LL, n); i++) {
    ll j = (m + i - 1) / i;
    if (j > n) continue;
    if (i > LLONG_MAX / j) continue;
    if (ans == -1 || ans > i * j) ans = i * j;
  }
  cout << ans << endl;
  return 0;
}