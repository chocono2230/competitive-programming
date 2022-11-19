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
  int n, q;
  cin >> n >> q;
  set<pair<int, int>> se;
  rep(i, q) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) se.insert({a, b});
    if (t == 2) {
      if (se.find({a, b}) != se.end()) se.erase({a, b});
    }
    if (t == 3) {
      if (se.find({a, b}) != se.end() && se.find({b, a}) != se.end())
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}