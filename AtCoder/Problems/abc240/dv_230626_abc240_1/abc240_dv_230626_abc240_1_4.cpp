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
  vector<pair<int, int>> v;
  int ans = 0;
  rep(i, n) {
    int in;
    cin >> in;
    if (v.empty() || v.back().first != in) {
      v.push_back({in, 1});
    } else {
      v.back().second++;
    }
    ans++;
    if (v.back().first == v.back().second) {
      ans -= v.back().second;
      v.pop_back();
    }
    cout << ans << endl;
  }
  return 0;
}