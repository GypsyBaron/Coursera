#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> g[2000005];
vector<int> gt[2000005];
vector<bool> vis(2000005);
vector<int> ts;
vector<int> comp(2000005, -1);
 
void dfs(int c){
    vis[c] = 1;
    for(int& i : g[c])
        if(!vis[i])
            dfs(i);
    ts.push_back(c);
}
 
void dfs2(int c, int j){
    comp[c] = j;
    for(int& i : gt[c])
        if(comp[i] == -1)
            dfs2(i, j);
}
 
int id(int c){
    return c<0 ? -c*2+1 : 2*c;
}
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
 
    int v, c;
    cin >> v >> c;
 
    for(int i = 0; i < c; i++){
        int u,vv;
        cin >> u >> vv;
        g[id(-u)].push_back(id(vv));
        g[id(-vv)].push_back(id(u));
        gt[id(vv)].push_back(id(-u));
        gt[id(u)].push_back(id(-vv));
    }
 
    v = v*2;
    for(int i = 2; i <= v+1; i++)
        if(!vis[i])
            dfs(i);
 
    int j = 0;
    while(!ts.empty()){
        int c = ts.back();
        ts.pop_back();
        if(comp[c] == -1)
            dfs2(c, j++);
    }
 
    vector<bool> a;
    for(int i = 2; i <= v; i+=2){
        if(comp[i] == comp[i+1]){
            cout << "UNSATISFIABLE\n";
            return 0;
        }
        a.push_back(comp[i] > comp[i+1]);
    }
 
    cout << "SATISFIABLE\n";
    
    for(int i = 0; i < a.size(); i++){
        if(a[i]) {
            cout << i+1 << " ";
        }
        else {
            cout << -(i+1) << " ";
        }
    }
 
    return 0;
}