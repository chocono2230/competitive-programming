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
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

combination cb(100005);

void dfs(vector<vector<int>> &tree, int now, int bf, int k, mint &ans,
         vector<mint> &p) {
  int cld = tree.at(now).size() - 1;
  ans *= cb(k - 2, cld) * p.at(cld);
  for (auto nx : tree.at(now)) {
    if (nx == bf) continue;
    dfs(tree, nx, now, k, ans, p);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  mint ans = k;
  vector<mint> p(100005, 1);
  rep2(i, 1, p.size()) p.at(i) = p.at(i - 1) * i;
  rep(i, n) {
    if (tree.at(i).size() == 1) {
      if (k == 1) {
        ans = 0;
      } else {
        ans *= k - 1;
        dfs(tree, tree.at(i).front(), i, k, ans, p);
      }
      break;
    }
  }
  cout << ans.val() << endl;
  return 0;
}