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
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr.at(u).push_back(v);
  }
  set<pair<int, int>> se;
  rep(st, n) {
    queue<int> q;
    vector<int> d(n, -1);
    d.at(st) = 0;
    q.push(st);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto nx : gr.at(now)) {
        if (d.at(nx) != -1) continue;
        d.at(nx) = d.at(now) + 1;
        q.push(nx);
      }
    }
    rep(i, n) {
      if (d.at(i) <= 1) continue;
      se.insert({st, i});
    }
  }
  cout << se.size() << endl;

  return 0;
}