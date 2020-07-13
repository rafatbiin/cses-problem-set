#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;

    cin >> n ;
    
    if(n == 2 || n == 3){
        cout <<"NO SOLUTION" << endl ;
        return 0 ;
    }
    for(int i = 2 ;i <=n ; i+=2) cout << i << ' ' ;
    for(int i = 1 ;i<=n ; i+=2) cout << i << ' ' ;

    return 0 ;
}