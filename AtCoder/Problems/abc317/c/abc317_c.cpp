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
  vector gr(n, vector<int>(n, -1));
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    gr.at(a).at(b) = gr.at(b).at(a) = c;
  }
  int ans = 0;
  vector<int> p;
  rep(i, n) p.push_back(i);
  do {
    int add = 0;
    rep(idx, n - 1) {
      int now = p.at(idx), nx = p.at(idx + 1);
      if (gr.at(now).at(nx) == -1) break;
      add += gr.at(now).at(nx);
    }
    ans = max(ans, add);
  } while (next_permutation(ALL(p)));
  cout << ans << endl;
  return 0;
}