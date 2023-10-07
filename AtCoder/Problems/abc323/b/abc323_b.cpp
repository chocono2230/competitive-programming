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
  vector<pair<int, int>> v(n);
  rep(i, n) {
    string s;
    cin >> s;
    int oc = 0;
    for (auto c : s) {
      if (c == 'o') oc++;
    }
    v.at(i) = {-oc, i};
  }
  sort(ALL(v));
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << v.at(i).second + 1;
  }
  cout << endl;
  return 0;
}