#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> co(m, {0, 0});
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    co.at(a).first += b;
    co.at(a).second++;
  }
  for (auto [a, b] : co) {
    double ans = (double)a / b;
    cout << fixed << setprecision(10) << ans << endl;
  }
  return 0;
}