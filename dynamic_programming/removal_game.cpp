#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 5002
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
ll a[N], dp[N][N] ;
bool visited[N] ;

ll solve(int l, int r){
    if(l>r)return 0 ;
    if(l==r) return a[l] ;

    if(dp[l][r] != -1) return dp[l][r] ;

    dp[l][r]= max(a[l] + min(solve(l+2,r), solve(l+1,r-1)),
        a[r]+min(solve(l+1,r-1),solve(l,r-2))) ;

    return dp[l][r] ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;
    for(int i = 0 ; i<n ; i++)cin >> a[i] ;

    mem(dp, -1) ;
    cout <<solve(0, n-1) << endl ;

    return 0 ;
}