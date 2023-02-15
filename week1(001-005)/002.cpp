#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

ll N;

bool judge(string str)
{
    ll tmp = 0;
    for(int i=0;i<N;i++){
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
    cin >> N;

    vector<string> v;

    for(ll i=0;i<(1<<N);i++){
        string tmp = "";
        for(int j=0;j<N;j++){
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
    
    sort(v.begin(),v.end());
    
    for(auto &i : v){
        cout << i << endl;
    }

    return 0;
}
