// Problem B:--- Agent Vinod - The Rightful Lefty

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s, ans = "";
    cin>>s;
    int m = s.size()/2 - (s.size()+1)%2;
    ans = s[m];
    for(int i = 1; i < s.size(); i ++){
        if(m+i < s.size()){
        ans+=s[m+i];  
        }
        if(m-i >= 0) {
            ans += s[m-i];
        }
    }
    cout<<ans;
    return 0;
}

// Solution of Team TLE Eliminators 	46 ms	40 KB

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n;
    if(s.size()%2==0){
        n = s.size()/2-1;
    }
    else{
        n = s.size()/2;
    }
    int left = n-1;
    int right = n+1;
    string ans = "";
    ans+=s[n];
    bool turn  = true;
    while(true){
        if(turn && right<s.size()){
            ans+=s[right++];
            turn  = !turn;
        }
        else if(!turn && left>=0){
            ans+=s[left--];
            turn  = !turn;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}