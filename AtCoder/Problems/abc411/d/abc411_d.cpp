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
  int n, q;
  cin >> n >> q;
  map<int, pair<string, int>> mp;
  mp[0] = {"", -1};
  int sz = 1;

  vector<int> idx(n + 1);
  rep(i, n + 1) idx.at(i) = 0;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int in;
      cin >> in;
      idx.at(in) = idx.at(0);
    }
    if (mode == 2) {
      int p;
      string s;
      cin >> p >> s;
      mp[sz] = {s, idx.at(p)};
      idx.at(p) = sz++;
    }
    if (mode == 3) {
      int p;
      cin >> p;
      idx.at(0) = idx.at(p);
    }
  }

  vector<string> v;
  int now = idx.at(0);
  while (now != 0) {
    v.push_back(mp[now].first);
    now = mp[now].second;
  }
  rrep(i, v.size()) { cout << v.at(i); }
  cout << endl;
  return 0;
}