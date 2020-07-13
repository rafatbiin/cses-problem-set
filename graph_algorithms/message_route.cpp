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
int parent[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b ;
    cin >> n >> m ;

    for(int i = 1 ;i<=m ;i++){
        cin >> a >>b ;
        g[a].pb(b) ;
        g[b].pb(a) ;
    }

    queue<int>q ;
    q.push(1) ;
    visited[1] = true ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;

        if(u == n){
            break ;
        }
        for(int v: g[u]){
            if(visited[v]) continue ;
            q.push(v);
            visited[v] = true ;
            parent[v] = u ;
        }
    }

    if(!parent[n]){
        cout <<"IMPOSSIBLE"<<endl ;
    }else{
        vector<int>ans ;
        while(n != 0){
            ans.pb(n) ;
            n = parent[n] ;
        }
        cout << ans.size() << endl ;
        for(int i = ans.size() -1 ;i>=0 ; i--){
            cout << ans[i] << ' ' ;
        }
        cout << endl;
    }
    

    

    return 0 ;
}