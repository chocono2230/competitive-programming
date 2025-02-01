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
  string d;
  cin >> d;
  vector<string> v = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
  int idx = 0;
  rep(i, v.size()) {
    if (d == v.at(i)) idx = i;
  }
  cout << v.at((idx + 4) % 8) << endl;
  return 0;
}