#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 111111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N], dp[N][105] ;
bool visited[N] ;

bool validate(int n, int m){
    if(a[n+1] == 0) return true ;
    if(a[n-1] == 0) return true ;
    return (abs(a[n-1] - m) <= 1 && abs(a[n+1] - m) <=1) ;

}

int solve(int n, int m){
    if(m<=0)return 0 ;
    if(n == 1) return 1 ;

    if(dp[n][m] != -1)return dp[n][m] ;

    if(a[n] != 0){
        return dp[n][m] = solve(n-1, m) ;
    }
    dp[n][m] = 0 ;
    if(validate(n,m)){
        cout << n << ' ' << m << endl;
        a[n] = m ;
        dp[n][m] = solve(n-1,m) ;
        a[n]= 0 ;
    }
    dp[n][m]+=solve(n,m-1) ;
    return dp[n][m] ;
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m ;
    cin >> n >> m ;

    for(int i =1 ;i<=n ;i++)cin >> a[i] ;

    mem(dp, -1) ;

    cout << solve(n,m) << endl;

    return 0 ;
}