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
  vector<int> p(5);
  rep(i, 5) cin >> p.at(i);
  vector<pair<int, string>> v;
  rep2(bit, 1, 1 << 5) {
    int add = 0;
    string s;
    rep(i, 5) {
      if ((bit & (1 << i)) != 0) {
        add += p.at(i);
        s.push_back('A' + i);
      }
    }
    v.push_back({-add, s});
  }
  sort(ALL(v));
  for (auto p : v) {
    cout << p.second << endl;
  }
  return 0;
}