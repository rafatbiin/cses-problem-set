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

ll solve(int n){
    ll result, temp1, temp2 ;
    temp1 = n*n*1LL ;
    temp2 = (n-4)*(n-4)*1LL ;

    result = temp1*(temp1-1)  - 40*(n-4) -8*temp2 - 48 ;
    return result>> 1 ;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n ;

    for(int i = 1 ; i<=n; i++) cout << solve(i) << endl ;

    return 0 ;
}