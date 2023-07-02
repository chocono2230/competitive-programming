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

#ifdef CHOCONO_LOCAL
const bool local = true;
#else
const bool local = false;
#endif

const int N = 30;
const int MX = 465;
const int INF = 1001001001;
vector B(N, vector<int>());

const clock_t start_time = clock();
double time_limit = 1.95;
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202307025,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

double xor_shift() {
  double b = xor128() % LLONG_MAX;
  return b / LLONG_MAX;
}

void random_shuffle(vector<int> &p) {
  rrep2(i, 1, p.size()) {
    int z = xor128() % (i + 1);
    swap(p.at(i), p.at(z));
  }
}

void local_time(const string &s) {
  if (local) {
    cerr << fixed << "time:" << s << ":" << time_from_clock() << endl;
  }
}

void input() {
  rep(i, N) {
    rep(j, i + 1) {
      int in;
      cin >> in;
      B.at(i).push_back(in);
    }
  }
}

int calc_score(vector<tuple<int, int, int, int>> &ans) {
  auto base = B;
  for (auto [x, y, x1, y1] : ans) {
    swap(base.at(x).at(y), base.at(x1).at(y1));
  }
  int err = 0;
  rep(i, N - 1) {
    rep(j, i + 1) {
      if (base.at(i).at(j) > base.at(i + 1).at(j)) err++;
      if (base.at(i).at(j) > base.at(i + 1).at(j + 1)) err++;
    }
  }
  if (err != 0) {
    return 50000 - 50 * err;
  }
  return 100000 - 5 * ans.size();
}

int output(vector<tuple<int, int, int, int>> &ans) {
  cout << ans.size() << endl;
  assert(ans.size() <= 10000);
  for (auto [x, y, x1, y1] : ans) {
    cout << x << " " << y << " " << x1 << " " << y1 << endl;
  }
  if (local) {
    return calc_score(ans);
  }
  return 0;
}

void update(vector<tuple<int, int, int, int>> &ans, vector<vector<int>> &table,
            int pi, int pj, int qi, int qj) {
  ans.push_back({pi, pj, qi, qj});
  swap(table.at(pi).at(pj), table.at(qi).at(qj));
}

vector<tuple<int, int, int, int>> solve() {
  auto table = B;
  vector<tuple<int, int, int, int>> res;
  rep(now, MX) {
    int si = -1, sj = -1;
    [&] {
      rep(i, N) rep(j, i + 1) {
        if (table.at(i).at(j) == now) {
          si = i;
          sj = j;
          return;
        }
      }
    }();
    vector tb(N, vector<int>(N + 1, -INF));
    vector memo(N, vector<pair<int, int>>(N + 1, {-1, -1}));
    tb.at(si).at(sj) = 0;
    rrep(i, si + 1) {
      rep(j, i + 1) {
        if (tb.at(i).at(j) == -INF) continue;
        int nc = tb.at(i).at(j);
        if (j != 0) {
          int l = table.at(i - 1).at(j - 1);
          if (l > table.at(si).at(sj) && tb.at(i - 1).at(j - 1) < nc + l) {
            tb.at(i - 1).at(j - 1) = nc + l;
            memo.at(i - 1).at(j - 1) = {i, j};
          }
        }
        if (j <= (i - 1)) {
          int r = table.at(i - 1).at(j);
          if (r > table.at(si).at(sj) && tb.at(i - 1).at(j) < nc + r) {
            tb.at(i - 1).at(j) = nc + r;
            memo.at(i - 1).at(j) = {i, j};
          }
        }
      }
    }
    double mx = -INF;
    int nwi = -1, nwj = -1;
    rep(i, si) rep(j, i + 1) {
      if (j != 0 && table.at(i - 1).at(j - 1) > table.at(si).at(sj)) continue;
      if (j != i && table.at(i - 1).at(j) > table.at(si).at(sj)) continue;
      if (tb.at(i).at(j) == -INF) continue;
      int z = si - i;
      if ((double)tb.at(i).at(j) / z > mx) {
        mx = (double)tb.at(i).at(j) / z;
        nwi = i;
        nwj = j;
      }
    }
    if (nwi == -1) continue;
    vector<pair<int, int>> vs;
    vs.push_back({nwi, nwj});
    while (nwi != si || nwj != sj) {
      auto [nxi, nxj] = memo.at(nwi).at(nwj);
      swap(nxi, nwi);
      swap(nxj, nwj);
      vs.push_back({nwi, nwj});
    }
    reverse(ALL(vs));
    rep(i, vs.size() - 1) {
      auto [ai, aj] = vs.at(i);
      auto [bi, bj] = vs.at(i + 1);
      update(res, table, ai, aj, bi, bj);
    }
  }
  return res;
}

int main() {
  input();

  int dbg_loop = 0;
  // if (local) {
  //   local_time("start");
  // }
  // // while (time_from_clock() < time_limit) {
  // //   dbg_loop++;
  // // }
  // if (local) {
  //   local_time("end");
  // }
  auto ans = solve();
  auto r = output(ans);

  if (local) {
    cerr << "artifacts:score:" << r << endl;
    cerr << "artifacts:loop_count:" << dbg_loop << endl;
    cerr << "artifacts:K:" << ans.size() << endl;
  }
  return 0;
}
