#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

ll n;

bool judge(string str)
{
    ll tmp = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '('){
            tmp ++;
        }else{
            tmp --;
        }
        if(tmp < 0){
            return false;
        }
    }
    if(tmp == 0){
        return true;
    }else{
        return false;
    }
}

int main()
{
    //入力
    cin >> n;

    vector<string> v;

    for(int i=0;i<(1<<n);i++){
        string tmp = "";
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                tmp += "(";
            }else{
                tmp += ")";
            }
        }
        if(judge(tmp)){
            v.push_back(tmp);
        }
    }
    
    for(auto &i : v){
        cout << i << endl;
    }

    return 0;
}
