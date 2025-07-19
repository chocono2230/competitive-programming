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
  vector<int> v;
  rep(i, s.size()) {
    if (s.at(i) == '#') v.push_back(i);
  }
  rep(i, v.size()) {
    int p = v.at(i) + 1;
    int q = v.at(i + 1) + 1;
    cout << p << "," << q << endl;
    i++;
  }
  return 0;
}