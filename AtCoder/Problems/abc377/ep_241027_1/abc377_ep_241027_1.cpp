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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  vector<ll> ans(n, -1);
  vector<bool> chk(n, false);
  rep(i, n) {
    if (ans.at(i) != -1) continue;
    vector<int> v;
    int now = i;
    while (!chk.at(now)) {
      v.push_back(now);
      chk.at(now) = true;
      now = p.at(now);
    }
    int idx = pow_mod(2, k, v.size());
    now = i;
    while (ans.at(now) == -1) {
      ans.at(now) = v.at(idx);
      now = p.at(now);
      idx = (idx + 1) % v.size();
    }
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}