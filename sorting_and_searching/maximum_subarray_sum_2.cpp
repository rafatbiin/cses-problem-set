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
ll c[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b  ;
    ll ans = -1e18 ;
    cin >> n>> a >> b;


    for(int i = 0; i<n ;i++){
        cin >> c[i+1] ;
        c[i+1]+=c[i] ;
    }

    set<pair<ll,int>> s ;

    for(int i = a ; i<=n ;i++){
        if(i>=a){
            s.insert({c[i-a], i-a}) ;
        }
        if(s.size()){
            ans = max(c[i] - (*s.begin()).first, ans) ;
        }
        if(i>=b){
            s.erase({c[i-b],i-b}) ;
        }
    }

    cout << ans << endl ;



    return 0 ;
}