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

ll euler_phi(ll n) {
  ll ret = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ret -= ret / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ret -= ret / n;
  return ret;
}

ll modPow(ll a, ll n, ll p) {
  if (n == 0) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
  ll a, x, m;
  cin >> a >> x >> m;
  if (a == 1) {
    ll ans = x % m;
    cout << ans << endl;
    return 0;
  }
  auto p = modPow(a, x, m);
  p = (p - 1 + m) % m;
  ll q = a - 1;
  ll g = gcd(q, m);
  ll gq = q / g;
  ll gm = m / g;
  auto phi = euler_phi(gm);
  phi = (phi - 1 + gm) % gm;
  cerr << p << " " << q << " " << g << " " << gq << " " << gm << " " << phi
       << endl;
  ll dd = modPow(q, phi, m);
  cerr << dd << endl;
  ll o = 81 % 7;
  cout << o << endl;
  ll ans = p * dd % m;
  cout << ans << endl;
  return 0;
}