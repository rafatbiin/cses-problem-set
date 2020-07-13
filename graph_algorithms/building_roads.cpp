#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] ;
bool visited[N] ;

vector<int>graph[N] ;

void dfs(int s){
    visited[s] = true ;
    for(auto u: graph[s]){
        if(visited[u])continue ;
        dfs(u) ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m , a, b;
    vector<int>roads ;
    cin >> n >> m ;

    for(int i = 0 ;i<m ;i++){
        cin >> a >> b ;
        graph[a].pb(b) ;
        graph[b].pb(a) ;
    }

    for(int i = 1 ;i<=n ;i++){
        if(!visited[i]){
            dfs(i) ;
            roads.pb(i) ;

        }
    }

    int sz = roads.size() -1 ;
    cout << sz << endl;
    for(int i = 0 ;i<sz ;i++){
        cout << roads[i] << ' ' << roads[i+1] << endl;
    }

    return 0 ;
}