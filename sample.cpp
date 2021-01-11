#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 25010, M = 50010, INF = 501000000;
int total = 0;
bool v[N];
int id[N], rd[N], d[N];
vector<int>t[N];

struct bian {
    int y, gg, c;
} b[M * 3];
int h[N], len = 0;
void ins(int x, int y, int c) {
    b[++len].y = y;
    b[len].c = c;
    b[len].gg = h[x];
    h[x] = len;
}
void dfs(int x) {
    v[x] = 1;
    id[x] = total;
    t[total].push_back(x);

    for (int i = h[x]; i; i = b[i].gg) {
        int y = b[i].y;

        if (v[y])
            continue;

        dfs(y);
    }
}

struct node {
    int x, c;
};
bool operator<(const node &x, const node &y) {
    return x.c > y.c;
}
priority_queue<node>q;
queue<int>Q;
void ss(int now) {
    for (int i = 0; i < t[now].size(); i++)
        q.push((node) {
                t[now][i], d[ t[now][i] ]
        });

    while (!q.empty()) {
        node x = q.top();
        q.pop();

        if (v[x.x])
            continue;

        v[x.x] = 1;

        for (int i = h[x.x]; i; i = b[i].gg) {
            int y = b[i].y;

            if (d[y] > d[x.x] + b[i].c) {
                d[y] = d[x.x] + b[i].c;

                if (id[x.x] == id[y])
                    q.push((node) {
                            y, d[y]
                    });

            }

            if (id[x.x] != id[y] && --rd[id[y]] == 0) {
                Q.push(id[y]);
            }
        }
    }
}

int main() {
    //freopen("a.in","r",stdin);
    //freopen("b.out","w",stdout);
    int n, r, p, st;
    scanf("%d %d %d %d", &n, &r, &p, &st);

    for (int i = 1; i <= r; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        ins(x, y, c);
        ins(y, x, c);
    }

    memset(v, 0, sizeof(v));

    for (int i = 1; i <= n; i++)
        if (!v[i])
            ++total, dfs(i);

    memset(rd, 0, sizeof(rd));

    for (int i = 1; i <= p; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        ins(x, y, c);
        rd[id[y]]++;
    }

    Q.push(id[st]);

    for (int i = 1; i <= total; i++)
        if (!rd[i])
            Q.push(i);

    memset(d, 127, sizeof(d));
    memset(v, 0, sizeof(v));
    d[st] = 0;

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        ss(x);
    }

    for (int i = 1; i <= n; i++)
        if (d[i] < INF)
            printf("%d\n", d[i]);
        else
            printf("UNREACHABLE\n");

    return 0;
}