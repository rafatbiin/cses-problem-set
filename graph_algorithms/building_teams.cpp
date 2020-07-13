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
int color[N] ;
bool ok = true ;

void dfs(int s){
    visited[s] = true ;

    for(int i = 0 ;i<g[s].size() && ok; i++){
        int v = g[s][i] ;
        if(visited[v]){
            if(color[s] == color[v]){
                ok = false ;
                return ;
            }
            continue ;
        }
        color[v]=(color[s]^1) ;
        dfs(v) ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m,a, b ;
    cin >> n >> m ;

    for(int i = 1 ;i<=m ;i++){
        cin >> a >> b ;
        g[a].pb(b) ;
        g[b].pb(a) ;
    }

    for(int i =1 ;i<=n ;i++){
        if(!visited[i]){
            dfs(i) ;
            if(!ok){
                cout <<"IMPOSSIBLE"<<endl;
                return 0 ;
            }
        }
    }

    for(int i = 1 ;i<=n ;i++){
        cout <<color[i]+1 << ' ';
    }

    return 0 ;
}