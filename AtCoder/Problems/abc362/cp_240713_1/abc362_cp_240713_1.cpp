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
  int n;
  cin >> n;
  vector<pair<int, int>> lr(n);
  vector<ll> ans(n);
  ll ls = 0, rs = 0;
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    lr.at(i) = {l, r};
    ls += l;
    rs += r;
    ans.at(i) = r;
  }
  if (ls > 0 || rs < 0) {
    cout << "No" << endl;
    return 0;
  }
  rep(i, n) {
    auto [l, r] = lr.at(i);
    ll d = min(rs, (ll)r - l);
    rs -= d;
    ans.at(i) -= d;
  }
  cout << "Yes" << endl;
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}