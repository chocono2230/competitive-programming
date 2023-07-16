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

const ll INF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> abc(m);
  vector wf(n, vector<ll>(n, INF));
  vector gr(n, vector<pair<int, ll>>(n, {-1, INF}));
  rep(i, n) wf.at(i).at(i) = 0;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    abc.at(i) = {a, b, c};
    wf.at(a).at(b) = wf.at(b).at(a) = c;
    gr.at(a).at(b) = gr.at(b).at(a) = {i, c};
  }
  vector chk(n, vector(n, false));
  rep(k, n) rep(i, n) rep(j, n) {
    if (wf.at(i).at(k) + wf.at(k).at(j) <= gr.at(i).at(j).second &&
        gr.at(i).at(j).first != -1 && k != i && k != j) {
      chk.at(i).at(j) = chk.at(j).at(i) = true;
    }
    wf.at(i).at(j) = min(wf.at(i).at(j), wf.at(i).at(k) + wf.at(k).at(j));
  }
  int ans = 0;
  rep(i, n) rep(j, n) if (chk.at(i).at(j)) ans++;
  ans /= 2;
  cout << ans << endl;
  return 0;
}