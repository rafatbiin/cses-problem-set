#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 125111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] ;
int dp[N];
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum ;
    cin >> n ;
    sum = (n*(n+1))>>1 ;
    if(sum &1){
        cout <<0 << endl;
        return 0 ;
    }
    sum/=2 ;
    dp[0] = 1 ;

    for(int i = 1 ;i<=n ;i++){
        for(int j = sum ; j>=i ; j--){
            dp[j]=(dp[j]+ dp[j-i])%M ;
        }
    }

    cout <<dp[sum]*1LL*((M+1)/2)%M << endl;
    

    return 0 ;
}