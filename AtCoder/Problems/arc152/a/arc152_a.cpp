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
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int l = 0;
  rep(i, n) {
    int now = a.at(i);
    if (l == p || l == p - 1) {
      // cerr << "Y" << now << " " << l << endl;
      if (now == 2) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      // cerr << "X" << now << " " << l << endl;
      if (now == 1) {
        l += 2;
      } else {
        l += 3;
      }
      l = min(l, p);
    }
  }
  cout << "Yes" << endl;
  return 0;
}