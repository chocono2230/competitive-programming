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
  vector<int> a(n);
  rep(i, n) a.at(i) = i + 1;
  int base = 0;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      int idx = (base + p) % n;
      a.at(idx) = x;
    }
    if (mode == 2) {
      int p;
      cin >> p;
      p--;
      int idx = (base + p) % n;
      cout << a.at(idx) << endl;
    }
    if (mode == 3) {
      int in;
      cin >> in;
      base += in;
      base %= n;
    }
  }
  return 0;
}