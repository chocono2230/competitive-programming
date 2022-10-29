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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector gr(n + 1, vector<pair<int, int>>());
  rep(i, n) {
    int sum = 0;
    rep2(j, i, n) {
      sum += a.at(j);
      gr.at(i).push_back({j + 1, sum});
    }
  }
  const int INF = 1001001001;
  vector<int> ans(m + 1, INF);
  vector<map<int, int>> vdp(n + 1);
  vdp.at(0)[0] = 0;

  return 0;
}