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
  vector gr(n, vector<int>());
  map<int, vector<int>> mp;
  set<int> se;
  rep(i, n) {
    int a;
    cin >> a;
    rep(j, a) {
      int in;
      cin >> in;
      gr.at(i).push_back(in);
      mp[in].push_back(i);
    }
  }
  queue<int> q;
  vector<int> tb(n, -1);
  se.insert(1);
  for (auto st : mp[1]) {
    q.push(st);
    tb.at(st) = 0;
  }
  int ans = -1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto nm : gr.at(now)) {
      if (nm == m) {
        ans = tb.at(now);
        break;
      }
      if (se.find(nm) != se.end()) continue;
      for (auto nx : mp[nm]) {
        if (tb.at(nx) != -1) continue;
        tb.at(nx) = tb.at(now) + 1;
        q.push(nx);
      }
      se.insert(nm);
    }
    if (ans != -1) break;
  }
  cout << ans << endl;
  return 0;
}