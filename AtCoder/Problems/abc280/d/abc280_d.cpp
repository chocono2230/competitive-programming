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
  ll k;
  cin >> k;
  auto pr = prime_factorization(k);
  ll ans = -1;
  for (auto p : pr) {
    ll add = 0, now = 0, co = 0;
    while (1) {
      now += p.first;
      ll tmp = now;
      while (tmp % p.first == 0) {
        co++;
        tmp /= p.first;
      }
      if (co >= p.second) {
        add = now;
        break;
      }
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}