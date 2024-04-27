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
  vector<string> a(n);
  rep(i, n) cin >> a.at(i);
  vector<string> b(n);
  rep(i, n) cin >> b.at(i);
  rep(i, n) rep(j, n) {
    if (a.at(i).at(j) != b.at(i).at(j)) {
      cout << i + 1 << " " << j + 1 << endl;
      return 0;
    }
  }
  return 0;
}