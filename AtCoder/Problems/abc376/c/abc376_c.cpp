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
  vector<pair<int, int>> ab;
  rep(i, n) {
    int in;
    cin >> in;
    ab.push_back({in, 0});
  }
  rep(i, n - 1) {
    int in;
    cin >> in;
    ab.push_back({in, 1});
  }
  sort(ALL(ab), greater<pair<int, int>>());
  int ans = 0, co = 0;
  for (auto [sz, mode] : ab) {
    if (mode == 1) {
      co++;
      continue;
    }
    if (co == 0) {
      if (ans != 0) {
        ans = -1;
        break;
      } else {
        ans = sz;
      }
    } else {
      co--;
    }
  }
  cout << ans << endl;
  return 0;
}