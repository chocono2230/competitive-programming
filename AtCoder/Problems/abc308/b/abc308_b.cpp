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
  vector<string> c(n);
  rep(i, n) cin >> c.at(i);
  map<string, int> mp;
  vector<string> vs;
  rep(i, m) {
    string s;
    cin >> s;
    mp[s] = -1;
    vs.push_back(s);
  }
  int x;
  cin >> x;
  rep(i, m) {
    int in;
    cin >> in;
    mp[vs.at(i)] = in;
  }
  int ans = 0;
  for (auto now : c) {
    if (mp.find(now) == mp.end())
      ans += x;
    else
      ans += mp[now];
  }
  cout << ans << endl;
  return 0;
}