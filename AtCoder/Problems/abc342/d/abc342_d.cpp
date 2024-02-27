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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  map<int, int> mp;
  int zc = 0, nz = 0;
  ll ans = 0;
  for (auto now : a) {
    if (now == 0) {
      zc++;
      continue;
    }
    nz++;
    auto pr = prime_factorization(now);
    int rs = 1;
    for (auto p : pr) {
      if (p.second % 2 == 0) continue;
      rs *= p.first;
    }
    ans += mp[rs];
    mp[rs]++;
  }
  rep(i, zc) {
    ans += nz;
    nz++;
  }
  cout << ans << endl;
  return 0;
}