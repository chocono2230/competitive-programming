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
  vector<pair<int, int>> xy(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    xy.at(i) = {a, b};
  }
  sort(ALL(xy));
  int ans = 0, mn = 1001001001;
  for (auto [x, y] : xy) {
    if (mn > y) ans++;
    mn = min(mn, y);
  }
  cout << ans << endl;
  return 0;
}