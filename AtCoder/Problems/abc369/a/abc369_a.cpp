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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  rep2(now, -300, 300) {
    vector<int> v = {a, b, now};
    sort(ALL(v));
    bool f = false;
    do {
      if (v.at(1) - v.at(0) == v.at(2) - v.at(1)) f = true;
    } while (next_permutation(ALL(v)));
    if (f) ans++;
  }
  cout << ans << endl;
  return 0;
}