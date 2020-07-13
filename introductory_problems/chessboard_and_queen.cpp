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
int a[N] ;
bool visited[N] ;

vector<string> grid ;
bool col[10],diag1[10], diag2[10] ;
int n = 8 ;

int nqueen(int x){
    if(x == n) return 1 ;

    int cnt = 0 ;

    for(int y = 0 ;y<n; y++){
        if(col[y] || diag1[x+y] || diag2[x-y+n-1] || grid[x][y] == '*')continue ;
        col[y] = diag1[x+y] = diag2[x-y+n-1] = true ;
        cnt+= nqueen(x+1) ;
        col[y] = diag1[x+y] = diag2[x-y+n-1] = false ;
    }

    // cout << cnt << endl ;

    return cnt ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s ;
    for(int i = 0 ;i<8 ;i++){
        cin >> s ;
        grid.pb(s) ;
    }

    cout <<nqueen(0)<<endl ;

    

    return 0 ;
}