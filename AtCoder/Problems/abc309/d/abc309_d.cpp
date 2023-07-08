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
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  vector gr1(n1, vector<int>());
  vector gr2(n2, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a < n1) {
      gr1.at(a).push_back(b);
      gr1.at(b).push_back(a);
    } else {
      a -= n1;
      b -= n1;
      gr2.at(a).push_back(b);
      gr2.at(b).push_back(a);
    }
  }

  queue<int> q;
  auto fc = [&](vector<vector<int>> &gr, int st) -> vector<int> {
    vector<int> res(gr.size(), -1);
    queue<int> q;
    q.push(st);
    res.at(st) = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto nx : gr.at(now)) {
        if (res.at(nx) != -1) continue;
        q.push(nx);
        res.at(nx) = res.at(now) + 1;
      }
    }
    return res;
  };
  auto d1 = fc(gr1, 0);
  auto d2 = fc(gr2, gr2.size() - 1);
  int ans = *max_element(ALL(d1)) + *max_element(ALL(d2)) + 1;
  cout << ans << endl;
  return 0;
}