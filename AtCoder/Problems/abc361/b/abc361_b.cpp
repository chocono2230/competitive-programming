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
  vector<int> v1(6), v2(6);
  rep(i, 6) cin >> v1.at(i);
  rep(i, 6) cin >> v2.at(i);
  auto fc = [&](int i, int j) {
    pair<int, int> p1(v1.at(i), v1.at(j));
    pair<int, int> p2(v2.at(i), v2.at(j));
    if (p1.first > p2.first) swap(p1, p2);
    return p2.first < p1.second;
  };
  if (fc(0, 3) && fc(1, 4) && fc(2, 5))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}