#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
struct Edge {
    int a, b, f, c, l;
};
 
const long long maximumValue = 2e9 + 8;
const int MAXN = 105;
 
int n, m;
vector <Edge> e;
int pt[MAXN];
vector <int> g[MAXN];
long long flow = 0;
queue <int> q;
int d[MAXN];
int limit;
int s, t;
 
void addEdge(int a, int b, int c, int l){
    Edge ed;
 
    ed.a = a; ed.b = b; ed.f = 0; ed.c = c, ed.l = l;
    g[a].push_back(e.size());
    e.push_back(ed);
 
    ed.a = b; ed.b = a; ed.f = c; ed.c = c, ed.l = l;
    g[b].push_back(e.size());
    e.push_back(ed);
}
 
bool BFS () {

    for(int i = s; i <= t; i++) {
        d[i] = maximumValue;
	}

    d[s] = 0;
    q.push(s);
    while(!q.empty() && d[t] == maximumValue){

        int current = q.front(); 
		q.pop();

        for(size_t i = 0; i < g[current].size(); i++){
            int id = g[current][i];
            int to = e[id].b;
 
            if(d[to] == maximumValue && e[id].c - e[id].f >= limit){
                d[to] = d[current] + 1;
                q.push(to);
            }
        }

    }

    while(!q.empty()) {
		q.pop();
	}

    return d[t] != maximumValue;
}
 
bool DFS (int v, int flow) {

    if(!flow) {
		return false;
	}

    if(v == t) {
		return true;
	}

    for(; pt[v] < g[v].size(); pt[v]++){
        int id = g[v][pt[v]];
        int to = e[id].b;
 
        if(d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
            int pushed = DFS(to, flow);
            if(pushed) {
                e[id].f += flow;
                e[id ^ 1].f -= flow;
                return true;
            }
        }
    }

    return false;
}
 
void Dinix () {

    for(limit = (1 << 30); limit >= 1;){
        if (!BFS()) {
            limit >>= 1;
            continue;
        }
 
        for(int i = s; i <= t; i++)
            pt[i] = 0;
 
        int pushed;
 
        while(pushed = DFS(s, limit)) {
			flow += limit;
		}
    }
}
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
 
    cin >> n >> m;
 
    vector<long long> input(1001), output(1001);
 
    long long sum = 0;

    for(int i = 0; i < m; i++){
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        addEdge(u, v, c-l, l);
        input[v] += l;
        output[u] += l;
        sum += l;
    }
 
    s = 0, t = n+1;

    for(int i = 1; i < t; ++i) {
        addEdge(s, i, input[i], input[i]);
        addEdge(i, t, output[i], output[i]);
    }
 
    Dinix ();
 
    if(sum == flow){
        cout << "YES" << endl;
        for(int i = 0; i < m*2; i+=2){
            cout << e[i].f + e[i].l << endl;
        }
        return 0;
    }
 
    cout << "NO" << endl;
 
    return 0;
}