#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a), greater<ll>());
  using P = pair<ll, vector<int>>;
  priority_queue<P> q;
  P st(0, vector<int>(n));
  st.second.at(0) = k;
  q.push(st);
  ll base = a.front() * k;
  set<vector<int>> se;
  rep(i, x) {
    auto [d, v] = q.top();
    q.pop();
    if (se.find(v) != se.end()) {
      i--;
      continue;
    }
    cout << base + d << endl;
    // for (auto now : v) cerr << now << " ";
    // cerr << endl;
    se.insert(v);
    rep(i, n - 1) {
      if (v.at(i) == 0) continue;
      ll dd = a.at(i + 1) - a.at(i) + d;
      v.at(i)--;
      v.at(i + 1)++;
      q.push({dd, v});
      v.at(i)++;
      v.at(i + 1)--;
    }
  }
  return 0;
}