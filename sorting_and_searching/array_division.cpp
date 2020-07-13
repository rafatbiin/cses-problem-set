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

ll solve(unsigned long long lo, unsigned long long hi, int n , int k){
    unsigned long long mid, sum , cnt;

    while(lo<hi) {
        mid = (lo+hi)/2 ;
        sum = 0LL ;
        cnt = 0LL;

        for(int i = 0 ;i<n ;i++){
            if(a[i] > mid){
                cnt = INF ;
                break ;
            }
            if(sum+a[i] <=mid){
                sum+=a[i] ;
            }else{
                cnt++ ;
                sum = a[i] ;
            }
        }
        cnt++ ;

        if(cnt > k) lo = mid + 1;
        else hi = mid ;
    }

    return hi  ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k ;
    unsigned long long sum = 0LL ;
    cin >> n >> k; 

    for(int i = 0 ;i<n; i++){
        cin >>a[i] ;
        sum+=a[i] ;
    }

    cout << solve(0, sum, n, k) << endl ;

    return 0 ;
}
    
    