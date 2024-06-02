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
  map<int, vector<pair<int, int>>> event;
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    event[l].push_back({0, i});
    event[r].push_back({1, i});
  }
  ll ans = 0, now = 0;
  for (auto &[_, v] : event) {
    sort(ALL(v));
    for (auto [e, i] : v) {
      if (e == 0) {
        ans += now;
        now++;
      } else {
        now--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}