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
  int n, m;
  cin >> n >> m;
  vector<ll> x(n);
  rep(i, n) cin >> x.at(i);
  sort(ALL(x));
  vector<ll> d;
  rep(i, n - 1) d.push_back(x.at(i + 1) - x.at(i));
  sort(ALL(d));
  ll ok = 1e15, ng = -1;
  int k = n - m;
  while (ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    ll t = mid;
    rep(i, k) { t -= d.at(i); }
    if (t >= 0)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}