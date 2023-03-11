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

int rc(vector<vector<int>> &a, set<int> &se, int i, int j) {
  if (i == a.size() - 1 && j == a.at(i).size() - 1) {
    return 1;
  }
  int res = 0;
  if (i != a.size() - 1) {
    if (se.find(a.at(i + 1).at(j)) == se.end()) {
      se.insert(a.at(i + 1).at(j));
      res += rc(a, se, i + 1, j);
      se.erase(a.at(i + 1).at(j));
    }
  }
  if (j != a.at(i).size() - 1) {
    if (se.find(a.at(i).at(j + 1)) == se.end()) {
      se.insert(a.at(i).at(j + 1));
      res += rc(a, se, i, j + 1);
      se.erase(a.at(i).at(j + 1));
    }
  }
  return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  set<int> se;
  se.insert(a.front().front());
  cout << rc(a, se, 0, 0) << endl;
  return 0;
}