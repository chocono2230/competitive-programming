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

ll fc(ll now) {
  static map<ll, ll> memo;
  if (now == 0) return 1;
  if (memo.find(now) != memo.end()) return memo[now];
  ll res = fc(now / 2) + fc(now / 3);
  return memo[now] = res;
}

int main() {
  ll n;
  cin >> n;
  cout << fc(n) << endl;
  return 0;
}