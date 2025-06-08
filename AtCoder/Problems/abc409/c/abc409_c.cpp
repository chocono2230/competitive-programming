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
  int n, l;
  cin >> n >> l;
  vector<int> v;
  v.push_back(0);
  vector<int> co(l, 0);
  co.at(0)++;
  rep(i, n - 1) {
    int in;
    cin >> in;
    int add = v.back() + in;
    add %= l;
    v.push_back(add);
    co.at(v.back())++;
  }
  if (l % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  rep(i, l / 3) {
    ll add = co.at(i);
    add *= co.at(i + l / 3);
    add *= co.at(i + l / 3 * 2);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}