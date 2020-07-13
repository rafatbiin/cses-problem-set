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
ll n, sum = 0;

ll solve(int x, ll curr_sum){
    if(x<0){
        return abs((sum-curr_sum) - curr_sum) ;
    }

    return min(solve(x-1, curr_sum), solve(x-1, curr_sum-a[x])) ;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>n ;
 
    for(int i = 0 ;i<n ;i++){
        cin>>a[i] ;
        sum+=a[i] ;
    }

    cout << solve(n-1, sum) << endl ;

    return 0 ;
}