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
vector<pii>backedges ;
int p[N] ;
bool visited[N] ;

void dfs(int s){
    visited[s] = true ;
    for(auto u:g[s]){
        if(visited[u]){
            if(p[s] != u) backedges.pb({s,u}) ;
            continue ;
        }
        p[u] = s ;
        dfs(u) ;
    }
}
vector<int> check_length(int s, int dest){
    vector<int> nodes_in_cycle ;
    int temp = s ;
    while(temp!=dest){
        nodes_in_cycle.pb(temp) ;
        temp = p[temp] ;
    }
    nodes_in_cycle.pb(dest);
    nodes_in_cycle.pb(s) ;
    return nodes_in_cycle ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m , a , b ;

    cin >> n >> m ;

    for(int i = 1 ; i<=m ; i++){
        cin >> a >> b ;
        g[a].pb(b);
        g[b].pb(a) ;
    }

    for(int i = 1 ; i<=n ;i++){
        if(!visited[i]){
            dfs(i) ;
        }
    }

    for(int i = 0;i<backedges.size() ;i++){
        vector<int> nodes_in_cycle = check_length(backedges[i].first, backedges[i].second) ;
        if(nodes_in_cycle.size() > 2){
            cout << nodes_in_cycle.size() << endl;
            for(int i = 0 ;i<nodes_in_cycle.size() ; i++){
                cout << nodes_in_cycle[i] << ' ' ;
            }
            return 0 ;
        }
        
    }

    cout <<"IMPOSSIBLE" << endl;

    

    return 0 ;
}