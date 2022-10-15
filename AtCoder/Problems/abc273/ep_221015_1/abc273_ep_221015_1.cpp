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
  int q;
  cin >> q;
  vector<pair<int, int>> nodes(q + 1, {-1, 0});
  map<int, int> mp;
  int now = 0;
  rep(i, q) {
    string s;
    cin >> s;
    if (s == "DELETE") {
      now = nodes.at(now).second;
    } else {
      int x;
      cin >> x;
      if (s == "ADD") {
        nodes.at(i + 1).first = x;
        nodes.at(i + 1).second = now;
        now = i + 1;
      }
      if (s == "SAVE") {
        mp[x] = now;
      }
      if (s == "LOAD") {
        now = mp[x];
      }
    }
    if (i != 0) cout << " ";
    cout << nodes.at(now).first;
  }
  cout << endl;
  return 0;
}