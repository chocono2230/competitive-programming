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

const int INF = 1001001001;

vector<vector<int>> matrix_mul(const vector<vector<int>> &p,
                               const vector<vector<int>> &q) {
  const int n = p.size();
  vector res(n, vector<int>(n, INF));
  rep(k, n) rep(i, n) rep(j, n) {
    res.at(i).at(j) = min(res.at(i).at(j), max(p.at(i).at(k), q.at(k).at(j)));
  }
  return res;
}

// 行列累乗
vector<vector<int>> matrix_exp(const vector<vector<int>> &now, ll lv) {
  const int n = now.size();
  if (lv == 0) {
    vector res(n, vector<int>(n, 0));
    return res;
  }
  if (lv == 1) return now;
  if (lv % 2 == 1) return matrix_mul(now, matrix_exp(now, lv - 1));
  auto r = matrix_exp(now, lv / 2);
  return matrix_mul(r, r);
}

int main() {
  int n, t, l;
  cin >> n >> t >> l;
  vector gr(n, vector<int>(n, INF));
  rep(i, t) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr.at(u).at(v) = i + 1;
  }
  auto r = matrix_exp(gr, l);
  vector<int> ans(n, -1);
  rep(i, n) ans.at(i) = r.at(0).at(i);
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << (ans.at(i) == INF ? -1 : ans.at(i));
  }
  cout << endl;
  return 0;
}