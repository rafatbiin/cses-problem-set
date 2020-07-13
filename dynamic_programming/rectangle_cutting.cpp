#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 505
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] , dp[N][N] ;
bool visited[N] ;

int solve(int n, int m){
    if(n==m) return 1 ;

    if(dp[n][m] != -1)return dp[n][m] ;

    int max_vertical = INF, max_horizontal = INF ;

    for(int i = 1 ; i<=(m/2) ; i++){
        max_vertical= min(max_vertical, (solve(n,i)+solve(n,m-i))) ;
    }
    for(int i = 1 ; i<=(n/2); i++){
        max_horizontal =min(max_horizontal, (solve(i,m)+solve(n-i,m)));
    }

    return dp[n][m] = min(max_vertical, max_horizontal) ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m ;
    cin >> n >> m ;

    mem(dp, -1) ;
    cout << solve(n,m)-1 << endl ;

    return 0 ;
}