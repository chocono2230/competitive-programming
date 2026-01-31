#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  if (a.empty() || a.back() != t) a.push_back(t);
  ll ans = 0, now = 0;
  for (auto p : a) {
    if (p < now) continue;
    ans += p - now;
    now = p + 100;
  }
  cout << ans << endl;
  return 0;
}