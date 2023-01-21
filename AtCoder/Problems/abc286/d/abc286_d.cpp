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
  int n, x;
  cin >> n >> x;
  vector<int> p;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    rep(j, b) p.push_back(a);
  }
  vector dp(p.size() + 1, vector<bool>(x + 1, 0));
  dp.front().front() = true;
  rep(i, p.size()) {
    int add = p.at(i);
    rep(j, x + 1) {
      if (!dp.at(i).at(j)) continue;
      dp.at(i + 1).at(j) = true;
      if (add + j <= x) {
        dp.at(i + 1).at(add + j) = true;
      }
    }
  }
  if (dp.back().back())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}