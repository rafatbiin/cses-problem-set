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
ll a[N] ;
bool visited[N] ;

ll n, t ;

ll solve(ll mx_element){
    ll lo = 0, hi = mx_element*t ;
    unsigned long long int cnt = 0ULL ;

    while(lo<hi){
        ll mid = (lo+hi)/2 ;
        cnt = 0LL ;
        for(int i = 0 ;i<n ;i++){
            cnt+=ll(mid/a[i]);
        }
        if(cnt >=t){
            hi = mid ;
        }
        else lo = mid+1 ;
        
    }
    return hi ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t ;

    for(int i = 0 ;i<n ;i++)cin>>a[i] ;
    auto it = max_element(a, a+n) ;
    cout << solve(*it) << endl ;

    return 0 ;
}