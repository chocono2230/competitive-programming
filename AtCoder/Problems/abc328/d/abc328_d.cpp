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
  string s;
  cin >> s;
  string stk;
  for (auto c : s) {
    stk.push_back(c);
    if (stk.size() >= 3) {
      int n = stk.size();
      if (stk.at(n - 3) == 'A' && stk.at(n - 2) == 'B' &&
          stk.at(n - 1) == 'C') {
        rep(p, 3) stk.pop_back();
      }
    }
  }
  cout << stk << endl;
  return 0;
}