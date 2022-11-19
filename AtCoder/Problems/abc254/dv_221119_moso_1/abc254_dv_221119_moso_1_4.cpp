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
  int n;
  cin >> n;
  vector<ll> v;
  rep2(i, 2, n + 1) {
    if ((ll)i * i > n) break;
    v.push_back((ll)i * i);
  }
  ll ans = v.size() + 1;
  rep2(i, 2, n + 1) {
    auto mp = prime_factorization(i);
    ll base = 1;
    for (auto p : mp) {
      if (p.second % 2 == 0) continue;
      base *= p.first;
    }
    if (n / base == 0) continue;
    ans += (upper_bound(ALL(v), n / base) - v.begin()) + 1;
  }
  cout << ans << endl;
  return 0;
}