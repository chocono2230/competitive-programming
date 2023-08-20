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
  int m;
  cin >> m;
  vector<int> d(m);
  rep(i, m) cin >> d.at(i);
  int sum = reduce(ALL(d));
  sum /= 2;
  rep(i, m) {
    if (d.at(i) <= sum) {
      sum -= d.at(i);
    } else {
      cout << i + 1 << " " << sum + 1 << endl;
      return 0;
    }
  }
  return 0;
}