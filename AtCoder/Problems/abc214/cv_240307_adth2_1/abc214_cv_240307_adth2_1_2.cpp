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
  vector<int> s(n);
  rep(i, n) cin >> s.at(i);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      q;
  rep(i, n) {
    int in;
    cin >> in;
    q.push({in, i});
  }
  vector<ll> ans(n, -1);
  int co = 0;
  while (!q.empty()) {
    auto [a, b] = q.top();
    q.pop();
    if (ans.at(b) != -1) continue;
    ans.at(b) = a;
    co++;
    if (co == n) break;
    int nx = b + 1;
    if (nx == n) nx = 0;
    q.push({a + s.at(b), nx});
  }
  for (auto a : ans) cout << a << endl;
  return 0;
}