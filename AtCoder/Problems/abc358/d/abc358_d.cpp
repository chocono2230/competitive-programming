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
  multiset<int> se;
  rep(i, n) {
    int in;
    cin >> in;
    se.insert(in);
  }
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  sort(ALL(b));
  ll ans = 0;
  rrep(i, m) {
    auto itr = se.lower_bound(b.at(i));
    if (itr == se.end()) {
      cout << -1 << endl;
      return 0;
    }
    ans += *itr;
    se.erase(itr);
  }
  cout << ans << endl;
  return 0;
}