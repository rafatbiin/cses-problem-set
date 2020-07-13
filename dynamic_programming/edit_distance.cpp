#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 5005
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int dp[N][N] ;
char a[N], b[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2 ;
    int n, m ;
    cin >> s1 >> s2;
    n = s1.length() ;
    m = s2.length() ;

    for(int i = 0 ; i<=n ; i++)dp[i][0] = i ;
    for(int i = 0 ; i<=m ; i++)dp[0][i] = i ;

    for(int i =1 ;i<=n ; i++){
        for(int j = 1 ; j<=m; j++){
            dp[i][j] = INF ;
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] ;
            }else {
                dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j], dp[i][j-1])+1) ;
            }
        }
    }
    cout << dp[n][m]<<endl;


    

    return 0 ;
}