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
int a[N], ans[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , k;
    cin >> n ;
    for(int i = 1 ; i<=n ; i++) cin >> a[i] ;

    ans[1] = 0 ;

    for(int i = 2 ; i<=n ;i++){
        if(a[i-1] < a[i])ans[i] = i-1 ;
        else {
            k = i -1 ;
            while(ans[k] != 0){
                if(a[ans[k]] < a[i]){
                    ans[i] = ans[k] ;
                    break ;
                }
                k = ans[k] ;
            }
            if(ans[k] == 0) ans[i] = 0 ;
        }
    }

    for(int i = 1 ;i<=n ;i++){
        cout << ans[i] <<  ' ' ;
    }
    cout << endl ;

    

    return 0 ;
}