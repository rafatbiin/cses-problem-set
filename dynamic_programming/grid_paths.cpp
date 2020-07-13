#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int dp[N][N] ;
char a[N][N] ;
bool visited[N] ;

int dx[2] = {0,1} ;
int dy[2] = {1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y ;
    cin >> n ;

    for(int i = 0 ;i<n ;i++){
        cin>>a[i] ;
    }
    if(a[0][0] == '*' || a[n-1][n-1] == '*'){
        cout << 0 << endl;
        return 0 ;
    }
    dp[0][0] = 1 ;

    for(int i = 0 ;i<n ;i++){
        for(int j = 0; j<n ;j++){
            for(int k = 0; k<2 ; k++){
                x = i - dx[k] ;
                y = j - dy[k] ;
                if(x <0 || y <0 || a[x][y] == '*')continue ;
                dp[i][j] = (dp[i][j] + dp[x][y])%M ; 
            }
        }
    }
    cout << dp[n-1][n-1] << endl;



    

    return 0 ;
}