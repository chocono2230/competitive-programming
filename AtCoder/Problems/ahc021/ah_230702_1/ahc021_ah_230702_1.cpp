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
const int BEAM_SIZE = 150;
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

struct State {
  vector<int> table;
  vector<int> opr;
  int score;
  int id;
  State(){};
  State(vector<int> table, vector<int> opr, int score, int id)
      : table(table), opr(opr), score(score), id(id){};
};

map<int, State> stateMap;

int p2idx(int i, int j) {
  int res = i * (i + 1) / 2;
  return res + j;
}

pair<int, int> idx2p(int idx) {
  int i = 0, co = 1, ss = 0;
  while (1) {
    if (ss + co > idx) {
      return {i, idx - ss};
    }
    i++;
    ss += co;
    co++;
  }
}

void update(vector<int> &table, int pi, int pj, int qi, int qj) {
  int idx = p2idx(pi, pj);
  int nxidx = p2idx(qi, qj);
  swap(table.at(idx), table.at(nxidx));
}

void update(vector<tuple<int, int, int, int>> &res, vector<int> &table, int pi,
            int pj, int qi, int qj) {
  res.push_back({pi, pj, qi, qj});
  update(table, pi, pj, qi, qj);
}

void update(vector<tuple<int, int, int, int>> &ans, vector<vector<int>> &table,
            int pi, int pj, int qi, int qj) {
  ans.push_back({pi, pj, qi, qj});
  swap(table.at(pi).at(pj), table.at(qi).at(qj));
}

void solve_opr(int now, State &s, vector<State> &nxs) {
  int si = -1, sj = -1;
  [&] {
    rep(i, N) rep(j, i + 1) {
      if (s.table.at(p2idx(i, j)) == now) {
        si = i;
        sj = j;
        return;
      }
    }
  }();
  vector tb(N, vector<int>(N + 1, -INF));
  vector memo(N, vector<pair<int, int>>(N + 1, {-1, -1}));
  tb.at(si).at(sj) = 0;
  int st = s.table.at(p2idx(si, sj));
  rrep(i, si + 1) {
    rep(j, i + 1) {
      if (tb.at(i).at(j) == -INF) continue;
      int nc = tb.at(i).at(j);
      if (j != 0) {
        int l = s.table.at(p2idx(i - 1, j - 1));
        if (l > st && tb.at(i - 1).at(j - 1) < nc + l) {
          tb.at(i - 1).at(j - 1) = nc + l;
          memo.at(i - 1).at(j - 1) = {i, j};
        }
      }
      if (j <= (i - 1)) {
        int r = s.table.at(p2idx(i - 1, j));
        if (r > st && tb.at(i - 1).at(j) < nc + r) {
          tb.at(i - 1).at(j) = nc + r;
          memo.at(i - 1).at(j) = {i, j};
        }
      }
    }
  }
  vector<pair<int, int>> v;
  rep(i, si) rep(j, i + 1) {
    if (j != 0 && s.table.at(p2idx(i - 1, j - 1)) > st) continue;
    if (j != i && s.table.at(p2idx(i - 1, j)) > st) continue;
    if (tb.at(i).at(j) == -INF) continue;
    v.push_back({i, j});
  }
  if (v.empty()) {
    assert((sj == 0 || s.table.at(p2idx(si - 1, sj - 1)) < st));
    assert((sj == si || s.table.at(p2idx(si - 1, sj)) < st));
    auto nxState = s;
    nxState.id = -1;
    nxState.opr.push_back(-1);
    nxs.push_back(nxState);
    return;
  }
  for (auto [nwi, nwj] : v) {
    auto nxState = s;
    nxState.id = -1;
    vector<pair<int, int>> vs;
    vs.push_back({nwi, nwj});
    while (nwi != si || nwj != sj) {
      auto [nxi, nxj] = memo.at(nwi).at(nwj);
      swap(nxi, nwi);
      swap(nxj, nwj);
      vs.push_back({nwi, nwj});
    }
    assert(vs.size() > 1);
    reverse(ALL(vs));
    rep(i, vs.size() - 1) {
      auto [ai, aj] = vs.at(i);
      auto [bi, bj] = vs.at(i + 1);
      update(nxState.table, ai, aj, bi, bj);
    }
    int addOpr = p2idx(vs.back().first, vs.back().second);
    nxState.opr.push_back(addOpr);
    nxState.score += vs.size() - 1;
    nxs.push_back(nxState);
  }
}

vector<tuple<int, int, int, int>> rest_opr(State &ans) {
  vector<tuple<int, int, int, int>> res;
  vector<int> table;
  rep(i, N) rep(j, i + 1) table.push_back(B.at(i).at(j));
  rep(now, MX) {
    if (ans.opr.at(now) == -1) continue;
    int si = -1, sj = -1;
    [&] {
      rep(i, N) rep(j, i + 1) {
        if (table.at(p2idx(i, j)) == now) {
          si = i;
          sj = j;
          return;
        }
      }
    }();
    vector tb(N, vector<int>(N + 1, -INF));
    vector memo(N, vector<pair<int, int>>(N + 1, {-1, -1}));
    tb.at(si).at(sj) = 0;
    int st = table.at(p2idx(si, sj));
    rrep(i, si + 1) {
      rep(j, i + 1) {
        if (tb.at(i).at(j) == -INF) continue;
        int nc = tb.at(i).at(j);
        if (j != 0) {
          int l = table.at(p2idx(i - 1, j - 1));
          if (l > st && tb.at(i - 1).at(j - 1) < nc + l) {
            tb.at(i - 1).at(j - 1) = nc + l;
            memo.at(i - 1).at(j - 1) = {i, j};
          }
        }
        if (j <= (i - 1)) {
          int r = table.at(p2idx(i - 1, j));
          if (r > st && tb.at(i - 1).at(j) < nc + r) {
            tb.at(i - 1).at(j) = nc + r;
            memo.at(i - 1).at(j) = {i, j};
          }
        }
      }
    }
    auto [nwi, nwj] = idx2p(ans.opr.at(now));
    vector<pair<int, int>> vs;
    vs.push_back({nwi, nwj});
    while (nwi != si || nwj != sj) {
      auto [nxi, nxj] = memo.at(nwi).at(nwj);
      swap(nxi, nwi);
      swap(nxj, nwj);
      vs.push_back({nwi, nwj});
    }
    assert(vs.size() > 1);
    reverse(ALL(vs));
    rep(i, vs.size() - 1) {
      auto [ai, aj] = vs.at(i);
      auto [bi, bj] = vs.at(i + 1);
      update(res, table, ai, aj, bi, bj);
    }
  }
  return res;
}

vector<tuple<int, int, int, int>> solve() {
  vector<tuple<int, int, int, int>> res;
  vector<pair<int, int>> beam_queue;
  auto nx_beam_queue = beam_queue;
  auto add_queue = [&](vector<int> &table, vector<int> &opr,
                       int score) -> void {
    int idx = stateMap.size();
    stateMap[idx] = State(table, opr, score, idx);
    nx_beam_queue.push_back({score, idx});
  };
  [&] {
    vector<int> baseTable;
    rep(i, N) rep(j, i + 1) baseTable.push_back(B.at(i).at(j));
    vector<int> opr;
    add_queue(baseTable, opr, 0);
    swap(nx_beam_queue, beam_queue);
  }();
  rep(now, MX) {
    vector<State> nxs;
    for (auto [st, idx] : beam_queue) {
      assert(stateMap.find(idx) != stateMap.end());
      auto &s = stateMap[idx];
      solve_opr(now, s, nxs);
      stateMap.erase(idx);
    }

    [&] {
      map<vector<int>, State> cv;
      for (auto &s : nxs) {
        vector<int> chk;
        rep(i, N) rep(j, i + 1) {
          if (s.table.at(p2idx(i, j)) <= now) {
            chk.push_back(p2idx(i, j));
          }
        }
        sort(ALL(chk));
        auto itr = cv.find(chk);
        if (itr == cv.end() || itr->second.score > s.score) {
          cv[chk] = s;
        }
      }
      nxs.clear();
      for (auto p : cv) {
        nxs.push_back(p.second);
      }
    }();

    sort(ALL(nxs), [](const State &l, const State &r) -> bool {
      return l.score < r.score;
    });
    rep(i, min(BEAM_SIZE, (int)nxs.size())) {
      add_queue(nxs.at(i).table, nxs.at(i).opr, nxs.at(i).score);
    }

    beam_queue.clear();
    swap(beam_queue, nx_beam_queue);
  }

  auto tidx = beam_queue.front().second;
  assert(stateMap.find(tidx) != stateMap.end());
  auto &top = stateMap[tidx];

  return rest_opr(top);
}

int main() {
  input();

  int dbg_loop = 0;
  auto ans = solve();
  auto r = output(ans);

  if (local) {
    cerr << "artifacts:score:" << r << endl;
    cerr << "artifacts:loop_count:" << dbg_loop << endl;
    cerr << "artifacts:K:" << ans.size() << endl;
    cerr << "artifacts:tt:" << time_from_clock() << endl;
  }
  return 0;
}
