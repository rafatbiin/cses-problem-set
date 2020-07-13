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
bool visited[N][N] ;
char a[N][N] ;

int dx[] = {1,0,-1,0} ;
int dy[] = {0,1, 0, -1} ;
int n, m ;

void dfs(int i, int j){
    visited[i][j] = true ;

    for(int idx = 0 ;idx<4 ;idx++){
        int x = i+dx[idx] ;
        int y = j+dy[idx] ;

        if(x<0 || x>=n || y<0 ||y>=m)continue;
        if(visited[x][y] || a[x][y] == '#')continue ;

        dfs(x,y) ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0 ;
    cin >>n >> m ;

    for(int i = 0 ; i<n ;i++){
        cin >> a[i] ;
    }

    for(int i = 0;i<n ; i++){
        for(int j = 0 ; j<m ;j++){
            if(a[i][j] == '.' && !visited[i][j]){
                ans++ ;
                dfs(i,j) ;
            }
        }
    }
    cout<<ans<<endl;


    return 0 ;
}