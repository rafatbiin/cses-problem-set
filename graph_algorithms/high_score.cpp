#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 2511
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<pii> g[N] ;
int a[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m ,a ,b, w;
    cin >> n >> m ;

    for(int i = 1 ;i<=m ;i++){
        cin >> a >> b >> w ;
        g[a].pb({b,-w}) ;
    }

    for(auto [first, second] : g[1]){
        if(first == n){
            if(second >=1e8 || second <= -1e8){
                cout << "-1"<<endl;
                return 0 ;
            }
        }
    }

    ll d[n+5] ;
    mem(d, 0x3f) ;
    d[1] = 0 ;

    for(int i =1 ; i<=n ; i++){
        for(int j = 1 ;j<=n; j++){
            for(auto [v, val]: g[j]){
                if(d[v] > d[j] + val){
                    d[v] = d[j] + val ;
                }
            }
        }
    }

    bool ok = false ;

    for(int i =1 ; i<=n ; i++){
        for(auto [v, val]: g[i]){
            if(d[v] > d[i] + val){
                for(auto [first, second]: g[1]){
                    if(first ==n){
                        cout << -second <<endl;
                        return 0 ;
                    }
                }
                cout <<-1 << endl;
                return 0 ;
            }
        }
    }

    cout << -d[n] <<endl;

    

    return 0 ;
}