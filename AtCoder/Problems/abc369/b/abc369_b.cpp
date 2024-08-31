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
  vector<int> lv, rv;
  rep(i, n) {
    int x;
    char y;
    cin >> x >> y;
    if (y == 'L') {
      lv.push_back(x);
    } else {
      rv.push_back(x);
    }
  }
  auto fc = [](vector<int> &v) {
    int res = 0;
    rep(i, v.size() - 1) { res += abs(v.at(i) - v.at(i + 1)); }
    return res;
  };
  cout << fc(lv) + fc(rv) << endl;
  return 0;
}