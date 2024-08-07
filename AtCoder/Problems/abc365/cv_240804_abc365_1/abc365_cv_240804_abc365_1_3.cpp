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
  ll m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  const int INF = 1001001001;
  int ok = 0, ng = INF;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    auto fc = [&]() {
      ll sum = 0;
      rep(i, n) { sum += min(a.at(i), mid); }
      return sum <= m;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  if (ng == INF) {
    cout << "infinite" << endl;
  } else {
    cout << ok << endl;
  }
  return 0;
}