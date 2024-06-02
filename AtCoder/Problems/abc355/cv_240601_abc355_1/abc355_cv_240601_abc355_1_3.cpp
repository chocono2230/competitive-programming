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
  int n, t;
  cin >> n >> t;
  vector<int> hc(n, n), wc(n, n);
  int x1 = n, x2 = n;
  rep(tt, t) {
    int in;
    cin >> in;
    in--;
    int i = in / n, j = in % n;
    hc.at(i)--;
    wc.at(j)--;
    if (i == j) x1--;
    if (i + j == n - 1) x2--;
    if (hc.at(i) == 0 || wc.at(j) == 0 || x1 == 0 || x2 == 0) {
      cout << tt + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}