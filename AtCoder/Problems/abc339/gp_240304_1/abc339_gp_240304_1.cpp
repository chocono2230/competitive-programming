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

struct MergeSortTree {
  using ll = long long;
  const int INF = 1001001001;
  unsigned int n;
  unsigned int width;
  vector<vector<int>> table;
  vector<vector<ll>> tableSum;
  MergeSortTree() {}
  MergeSortTree(unsigned int n) : n(n), width(bit_ceil(n)) {
    table.resize(bit_width(width));
    tableSum.resize(table.size());
    for (auto &v : table) v.resize(width, INF);
    for (auto &v : tableSum) v.resize(width, 0);
  }
  MergeSortTree(const vector<int> &input) : MergeSortTree(input.size()) {
    for (unsigned int i = 0; i < n; i++) {
      table.at(0).at(i) = input.at(i);
      tableSum.at(0).at(i) = input.at(i);
      assert(input.at(i) < INF);
    }
    for (unsigned int lv = 1, w = 2; lv < table.size(); lv++, w *= 2) {
      for (unsigned int l = 0; l < width; l += w) {
        unsigned int r = l + w;
        unsigned int i1 = l, i2 = l + (w / 2);
        for (unsigned int j = l; j < r; j++) {
          int p1 = INF + 5, p2 = INF + 5;
          if (i1 != l + w / 2) p1 = table.at(lv - 1).at(i1);
          if (i2 != r) p2 = table.at(lv - 1).at(i2);
          if (p1 < p2) {
            table.at(lv).at(j) = p1;
            tableSum.at(lv).at(j) = p1;
            i1++;
          } else {
            table.at(lv).at(j) = p2;
            tableSum.at(lv).at(j) = p2;
            i2++;
          }
          if (j != l) tableSum.at(lv).at(j) += tableSum.at(lv).at(j - 1);
        }
      }
    }
  }

  ll query(int l, int r, int x) { return qMain(l, r, x, table.size() - 1, 0); }
  ll qMain(int l, int r, int x, int lv, int base) {
    assert(lv >= 0);
    int w = (1 << lv);
    int wm = (w >> 1);
    if (l == base * w && r == (l + w)) return qSubAll(l, r, x, lv);
    int mid = base * w + wm;
    ll res = 0;
    if (l < mid) {
      res += qMain(l, min(r, mid), x, lv - 1, base * 2);
    }
    if (mid < r) {
      res += qMain(max(l, mid), r, x, lv - 1, base * 2 + 1);
    }
    return res;
  }
  ll qSubAll(int l, int r, int x, int lv) {
    int i1 = l - 1, i2 = r;
    while (i2 - i1 > 1) {
      int mid = (i2 + i1) / 2;
      if (table.at(lv).at(mid) <= x)
        i1 = mid;
      else
        i2 = mid;
    }
    if (i1 == l - 1) return 0;
    return tableSum.at(lv).at(i1);
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  MergeSortTree tree(a);
  int q;
  cin >> q;
  ll p = 0;
  while (q--) {
    ll x, y, z;
    cin >> x >> y >> z;
    x ^= p;
    y ^= p;
    z ^= p;
    x--;
    ll ans = tree.query(x, y, z);
    cout << ans << endl;
    p = ans;
  }
  return 0;
}