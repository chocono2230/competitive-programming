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
  vector<pair<int, int>> v(3);
  rep(i, 3) {
    int x, y;
    cin >> x >> y;
    v.at(i) = {x, y};
  }
  auto fc = [&]() {
    int ax = v.at(1).first - v.at(0).first;
    int ay = v.at(1).second - v.at(0).second;
    int bx = v.at(2).first - v.at(0).first;
    int by = v.at(2).second - v.at(0).second;
    return ax * bx + ay * by;
  };
  rep(i, 3) {
    if (fc() == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    auto p = v.front();
    v.erase(v.begin());
    v.push_back(p);
  }
  cout << "No" << endl;
  return 0;
}