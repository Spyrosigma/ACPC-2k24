// Problem E:--- Shaktiman and the Underworld Countdown: A Race Against Tamraj Kilvish!

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> a(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            a[i] = a[i + 1] + (s[i] - '0');
        }
        string res;
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += a[i];
            res += (char)(c % 10 + '0');
            c /= 10;
        }
        res += (char)(c + '0');
        while (res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
    return  0;
}

// -----------------------------------------------------------------------------------------------------------
// Solution of team PCxSI 	62 ms	8824 KB

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define yesno(x) cout << ((x) ? "Yes\n" : "No\n")
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9+7;

/*
    FUNCTIONS
*/
//nCr
int NCR[1000][1000];
int nCr(int n, int r){
    if(n==r) return NCR[n][r] = 1;
    if(r==0) return NCR[n][r] = 1;
    if(r==1) return NCR[n][r] = n;
    if(NCR[n][r]) return NCR[n][r];
    return NCR[n][r] = (nCr(n-1,r)%MOD + nCr(n-1,r-1)%MOD)%MOD;
}

//power
long long power(int N, int R){
    if(R == 1) return N;
    if(R == 0) return 1;
    long long temp = power(N,R/2);
    return (R&1)?(((temp*temp)%MOD)*N)%MOD:(temp*temp)%MOD;
}

//modular arithmetic
int add(int a, int b, int m = MOD) { return (a+b)%m; }
int sub(int a, int b, int m = MOD) { return (a-b+m)%m; }
int mul(int a, int b, int m = MOD) { return (a*b)%m; }
int divi(int a, int b, int m = MOD) { return (a*power(b,m-2))%m; }
int mod(int a, int m = MOD) { return (a%m+m)%m; }

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int pref[n];
    for(int i=0;i<n;i++){
        pref[i] = s[i] - '0';
    }
    for(int i=1;i<n;i++){
        pref[i] += pref[i-1];
    }
    string ans = "";
    int carry = 0;
    for(int i=n-1;i>=0;i--){
        pref[i] += carry;
        int x = pref[i] % 10;
        carry = pref[i] / 10;
        ans += x + '0';
    }
    ans += carry + '0';
    while(ans[ans.size() - 1] == '0'){
        ans.pop_back();   
    }
    reverse(all(ans));
    cout<<ans<<"\n";
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}