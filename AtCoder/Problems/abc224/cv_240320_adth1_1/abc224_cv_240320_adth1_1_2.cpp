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
  vector<pair<int, int>> xy(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  vector<pair<int, int>> p(3);
  auto fc = [&]() {
    vector<pair<int, int>> q = p;
    sort(ALL(q));
    if (q.at(0).first == q.at(1).first) {
      return q.at(0).first != q.at(2).first;
    }
    ll dx1 = q.at(1).first - q.at(0).first;
    ll dy1 = q.at(1).second - q.at(0).second;
    ll dx2 = q.at(2).first - q.at(0).first;
    ll dy2 = q.at(2).second - q.at(0).second;
    return dy1 * dx2 != dy2 * dx1;
  };

  int ans = 0;
  rep(i, n) {
    p.at(0) = xy.at(i);
    rep2(j, i + 1, n) {
      p.at(1) = xy.at(j);
      rep2(k, j + 1, n) {
        p.at(2) = xy.at(k);
        if (fc()) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}