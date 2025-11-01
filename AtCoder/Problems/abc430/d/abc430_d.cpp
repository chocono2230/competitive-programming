#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  const int INF = 1001001001;
  ll ans = INF;
  mp[0] = INF;
  rep(i, n) {
    int in;
    cin >> in;
    mp[in] = INF;
    auto itr = mp.lower_bound(in);
    auto pritr = itr;
    pritr--;
    int d = itr->first - pritr->first;
    if (pritr->second > d) {
      ans -= pritr->second;
      pritr->second = d;
      ans += d;
    }
    itr->second = d;

    auto nxitr = itr;
    nxitr++;
    if (nxitr != mp.end()) {
      d = nxitr->first - itr->first;
      if (nxitr->second > d) {
        ans -= nxitr->second;
        ans += d;
        nxitr->second = d;
      }
      itr->second = min(itr->second, d);
    }
    ans += itr->second;
    // if (i == 1) {
    //   for (auto p : mp) cerr << p.first << " " << p.second << endl;
    // }
    cout << ans << endl;
  }
  return 0;
}