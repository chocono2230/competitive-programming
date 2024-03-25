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
  int w, b;
  cin >> w >> b;
  string t = "wbwbwwbwbwbw";
  string s;
  rep(i, 205) s += t;
  rep(i, s.size()) {
    int bc = 0, wc = 0;
    rep2(j, i, s.size()) {
      if (s.at(j) == 'b')
        bc++;
      else
        wc++;
      if (bc > b || wc > w) break;
      if (bc == b && wc == w) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}