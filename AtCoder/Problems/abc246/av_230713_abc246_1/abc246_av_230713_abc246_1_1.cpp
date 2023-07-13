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
  map<int, int> x, y;
  rep(i, 3) {
    int ix, iy;
    cin >> ix >> iy;
    x[ix]++;
    y[iy]++;
  }
  int ax = -1, ay = -1;
  for (auto p : x) {
    if (p.second == 1) ax = p.first;
  }
  for (auto p : y) {
    if (p.second == 1) ay = p.first;
  }
  cout << ax << " " << ay << endl;
  return 0;
}