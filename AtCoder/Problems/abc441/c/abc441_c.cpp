#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, k;
  ll x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a));
  vector<ll> sums(n + 1, 0);
  rep(i, n) sums.at(i + 1) = sums.at(i) + a.at(i);
  if (sums.at(k) < x) {
    cout << -1 << endl;
    return 0;
  }
  int d = 0;
  rep(i, k) {
    ll t = sums.at(k) - sums.at(i + 1);
    if (t < x) break;
    d++;
  }
  cout << n - d << endl;
  return 0;
}