#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        // int n = s.length();
        string ans = "";
        int start=0;
        char letter = s[0];
        for(int i=1; i<n; i++){
           if(letter == s[i]){
                ans+=letter;
                letter = s[i+1];
                i++;
           }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}