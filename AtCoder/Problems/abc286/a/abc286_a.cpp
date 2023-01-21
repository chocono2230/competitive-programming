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
  int n, p, q;
  cin >> n >> p >> q;
  p--;
  int r, s;
  cin >> r >> s;
  r--;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b;
  rep(i, n) {
    // cerr << i << endl;
    // rep(i, b.size()) {
    //   if (i != 0) cout << " ";
    //   cout << b.at(i);
    // }
    // cout << endl;
    if (i == p) {
      rep2(j, r, s) { b.push_back(a.at(j)); }
      i = q - 1;
      continue;
    }
    if (i == r) {
      i = s - 1;
      rep2(j, p, q) { b.push_back(a.at(j)); }
      continue;
    }
    b.push_back(a.at(i));
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << b.at(i);
  }
  cout << endl;
  return 0;
}