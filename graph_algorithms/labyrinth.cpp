#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1011
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
char a[N][N] ;
bool visited[N][N] ;
pii parent[N][N] ;
char d[N][N] ;
char dc[] = {'D', 'R', 'U', 'L'} ;
int dx[] = {1, 0, -1, 0} ;
int dy[] = {0, 1, 0, -1} ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m , sx, sy, dsx,dsy;
    cin >> n  >> m ;

    for(int i = 0 ;i<n ;i++){
        cin >>a[i] ;
        for(int j = 0; j<m; j++){
            if(a[i][j] == 'A')
                sx = i, sy = j ;
            if(a[i][j] == 'B')
                dsx = i, dsy = j ;
        }
    }
    queue<pii>q ;
    q.push({sx,sy});
    visited[sx][sy] = true ;

    while(!q.empty()){
        pair<int,int> p = q.front() ;
        q.pop() ;

        if(a[p.first][p.second] == 'B')
            break ;

        for(int i = 0 ;i<4 ; i++){
            int x = p.first + dx[i] ;
            int y = p.second+ dy[i] ;

            if(x<0 || x >=n || y<0 || y>=m)continue ;
            if(visited[x][y]) continue ;

            if(a[x][y] != '#'){
                visited[x][y] = true ;
                q.push({x,y}) ;
                parent[x][y] = {p.first, p.second} ;
                d[x][y] = dc[i];

            }
        }
    }

    if(parent[dsx][dsy]==pii(0,0)){
        cout <<"NO"<<endl;
    }else {
        cout <<"YES"<<endl;
        string ans ;
        while(dsx != sx || dsy != sy){
            ans.push_back(d[dsx][dsy]) ;
            pii new_parent = parent[dsx][dsy] ;
            dsx = new_parent.first ;
            dsy = new_parent.second ;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.length() << endl;
        cout << ans <<endl;
    }
    return 0 ;
}