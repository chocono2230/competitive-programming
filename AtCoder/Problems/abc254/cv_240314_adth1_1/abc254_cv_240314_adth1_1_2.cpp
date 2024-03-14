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
  int n, k;
  cin >> n >> k;
  vector<multiset<int>> v(k);
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  rep(i, n) { v.at(i % k).insert(a.at(i)); }
  sort(ALL(a));
  rep(i, n) {
    int idx = i % k;
    auto itr = v.at(idx).find(a.at(i));
    if (itr == v.at(idx).end()) {
      cout << "No" << endl;
      return 0;
    }
    v.at(idx).erase(itr);
  }
  cout << "Yes" << endl;
  return 0;
}