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
  ll n;
  cin >> n;
  vector<int> v;
  rep(i, 60) {
    if ((n & (1LL << i)) != 0) v.push_back(i);
  }
  vector<ll> ans;
  rep(bit, 1 << v.size()) {
    ll add = 0;
    rep(i, v.size()) {
      if ((bit & (1 << i)) == 0) continue;
      add |= (1LL << (v.at(i)));
    }
    ans.push_back(add);
  }
  sort(ALL(ans));
  for (auto now : ans) cout << now << endl;
  return 0;
}