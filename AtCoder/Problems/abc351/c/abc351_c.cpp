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
  vector<int> stk;
  rep(i, n) {
    int in;
    cin >> in;
    stk.push_back(in);
    while (stk.size() != 1) {
      if (stk.at(stk.size() - 1) != stk.at(stk.size() - 2)) break;
      int p = stk.back();
      stk.pop_back();
      stk.pop_back();
      stk.push_back(p + 1);
    }
  }
  cout << stk.size() << endl;
  return 0;
}