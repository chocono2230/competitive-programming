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

const int INF = 2001001001;
multiset<int> se;

vector<string> make_vs(int now) {
  vector<string> res;
  string s;
  rrep(i, 30) {
    if ((now & (1 << i)) == 0)
      s.push_back('0');
    else
      s.push_back('1');
    res.push_back(s);
  }
  return res;
}

void add(map<string, int> &base, int target) {
  auto r = make_vs(target);
  for (auto &s : r) {
    base[s]++;
  }
  se.insert(target);
}

void expire(map<string, int> &base, int target) {
  auto r = make_vs(target);
  for (auto &s : r) {
    base[s]--;
    if (base[s] == 0) {
      base.erase(s);
    }
  }
  se.erase(se.lower_bound(target));
}

int s2n(const string &s) {
  int res = 0;
  rep(i, 30) {
    res *= 2;
    if (i < s.size() && s.at(i) == '1') res++;
  }
  return res;
}

int dfs(map<string, int> &base, string now) {
  int res = INF;
  if (now.size() == 30) {
    if (base[now] >= 2) return 0;
    return INF;
  }
  now.push_back('0');
  bool z = false;
  if (base.find(now) != base.end() && base[now] >= 2) {
    res = min(res, dfs(base, now));
    z = true;
  }
  now.pop_back();
  now.push_back('1');
  if (base.find(now) != base.end() && base[now] >= 2) {
    res = min(res, dfs(base, now));
    z = true;
  }
  if (z) return res;
  auto n0 = now;
  n0.back() = '0';
  if (base.find(n0) == base.end() || base.find(now) == base.end() ||
      base[n0] == 0 || base[now] == 0)
    return INF;
  int in1 = s2n(now), in0 = s2n(n0);
  auto p = se.lower_bound(in1), q = se.lower_bound(in0);
  assert(p != se.end() && q != se.end());
  return (*p) ^ (*q);
}

int main() {
  int qe;
  cin >> qe;
  map<string, int> base;
  while (qe--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      cin >> x;
      add(base, x);
    }
    if (mode == 2) {
      int x;
      cin >> x;
      expire(base, x);
    }
    if (mode == 3) {
      string now;
      int ans = dfs(base, now);
      cout << ans << endl;
    }
  }
  return 0;
}