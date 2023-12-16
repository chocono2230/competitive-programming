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
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }

  vector<int> d(n, -1);
  auto fc = [&](int x) {
    queue<int> q;
    d.at(x) = 1;
    q.push(x);
    int res = 1;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto nx : tree.at(now)) {
        if (d.at(nx) != -1) continue;
        if (nx == 0) continue;
        q.push(nx);
        d.at(nx) = d.at(now) + 1;
        res++;
      }
    }
    return res;
  };
  int ans = 0;
  for (auto nx : tree.at(0)) {
    ans = max(ans, fc(nx));
  }
  cout << n - ans << endl;
  return 0;
}