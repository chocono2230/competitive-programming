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
  int n, k;
  cin >> n >> k;
  pair<int, int> dp(0, 0);
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  dp.first = a.front();
  dp.second = b.front();
  const int INF = 1001001001;
  rep2(i, 1, n) {
    int aa = a.at(i);
    int bb = b.at(i);
    pair<int, int> nx(-INF, -INF);
    if (abs(aa - dp.first) <= k || abs(aa - dp.second) <= k) nx.first = aa;
    if (abs(bb - dp.first) <= k || abs(bb - dp.second) <= k) nx.second = bb;
    if (nx.first == -INF && nx.second == -INF) {
      cout << "No" << endl;
      return 0;
    }
    swap(nx, dp);
  }
  cout << "Yes" << endl;
  return 0;
}