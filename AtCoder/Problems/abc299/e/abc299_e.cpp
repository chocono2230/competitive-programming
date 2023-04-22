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

void bfs(vector<vector<int>> &gr, vector<int> &d, int st) {
  d.at(st) = 0;
  queue<int> q;
  q.push(st);
  const int INF = 1001001001;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto nx : gr.at(now)) {
      if (d.at(nx) != INF) continue;
      d.at(nx) = d.at(now) + 1;
      q.push(nx);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  int k;
  cin >> k;
  vector<pair<int, int>> dp(k);
  rep(i, k) {
    int p, d;
    cin >> p >> d;
    p--;
    dp.at(i) = {d, p};
  }
  sort(ALL(dp), greater<pair<int, int>>());
  const int INF = 1001001001;
  vector dist(n, vector<int>(n, INF));
  rep(i, n) bfs(gr, dist.at(i), i);
  vector<int> flg(n, 0);
  vector vv(k, vector<int>());
  for (auto [d, p] : dp) {
    rep(i, n) {
      if (dist.at(p).at(i) < d) flg.at(i) = 1;
    }
  }
  string ans(n, '0');
  for (auto [d, p] : dp) {
    bool f = false;
    rep(i, n) {
      if (dist.at(p).at(i) == d && flg.at(i) == 0) {
        ans.at(i) = '1';
        f = true;
      }
    }
    if (!f) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (k == 0) ans.front() = '1';
  cout << "Yes" << endl;
  cout << ans << endl;
  return 0;
}