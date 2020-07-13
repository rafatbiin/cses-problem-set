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

const long long INF = 1LL << 60 ;
typedef long long ll ;
typedef pair < long long , long long> pll ;

vector<vector<pll>> g1(N), g2(N) ;
int parent[N] ;
ll dist1[N], dist2[N] ;
bool visited[N] ;

void dijkstra(ll source, ll destination, vector<vector<pll>>&g, ll *dist){
    set<pll>active_vertices;
    active_vertices.insert({0LL, source}) ;
    dist[source] = 0LL ;

    while(!active_vertices.empty()){
        ll u = active_vertices.begin()->second ;
        active_vertices.erase(active_vertices.begin()) ;

        for(auto [v, val]: g[u]){
            if(dist[v] > dist[u] + val){
                active_vertices.erase({dist[v], v});
                dist[v] = dist[u] + val ;
                parent[v] = u ;
                active_vertices.insert({dist[v], v}) ;
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, a, b , w ;
    cin >> n >> m ;

    for(int i = 0 ;i<m ; i++){
        cin >> a >> b >> w ;
        g1[a].pb({b,w}) ;
        g2[b].pb({a,w}) ;
    }

    mem(dist1, 0x3f) ;
    mem(dist2, 0x3f);

    dijkstra(1, n, g1, dist1);
    dijkstra(n, 1, g2, dist2) ;

    ll ans = 1e18 ;

    for(int i= 1 ;i<=n ;i++){
        for(auto [first, second]: g1[i]){
            ans = min(ans, dist1[i]+dist2[first] + second/2) ;
        }
    }
    cout <<ans <<endl;


    return 0 ;
}
