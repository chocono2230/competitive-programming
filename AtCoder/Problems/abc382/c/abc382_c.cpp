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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ai(n);
  rep(i, n) {
    int in;
    cin >> in;
    ai.at(i) = {-in, i};
  }
  vector<int> table(200005, -2);
  for (auto [a, i] : ai) {
    a *= -1;
    rep2(j, a, table.size()) {
      if (table.at(j) != -2) break;
      table.at(j) = i;
    }
  }
  rep(i, m) {
    int in;
    cin >> in;
    cout << table.at(in) + 1 << endl;
  }
  return 0;
}