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
  int ans = -1;
  int ax = 0;
  set<string> se;
  rep(i, n) {
    string s;
    int t;
    cin >> s >> t;
    if (se.find(s) != se.end()) continue;
    se.insert(s);
    if (ax < t) {
      ax = t;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}