#include <iostream>
#include <vector>
using namespace std;

void SquareMatrix(vector<vector<long long> > new_matrix, vector<vector<long long> > matrix)
{
    for(int i=0;i<new_matrix.size();i++){
        for(int j=0;j<new_matrix.size();j++){
            long long tmp = 0;
            for(int k=0;k<new_matrix.size();k++){
                tmp += matrix[i][k] * matrix[k][j];
            }
            new_matrix[i][j] = tmp;
        }
    }
}

void CalcMatrix(vector<vector<long long> > matrix, vector<long long> ans)
{
    vector<long long> new_ans(ans.size());
    for(int i=0;i<new_ans.size();i++){
        long long tmp = 0;
        for(int j=0;j<new_ans.size();j++){
            tmp += matrix[i][j] * ans[j];
        }
        new_ans[i] = tmp;
    }
    for(int i=0;i<new_ans.size();i++){
        ans[i] = new_ans[i];
    }
}

int main()
{
    int length, multiple, number;
    cin >> length >> multiple >> number;
    
    vector<int> v(number);
    for(auto &i : v){
        cin >> i;
    }

    typedef vector<vector<long long > > matrix;
    matrix plain_matrix(multiple, vector<long long>(multiple, 0));
    vector<matrix> dp;

    matrix origin_matrix(multiple, vector<long long>(multiple, 0));
    for(auto &n : v){
        origin_matrix[0][n % multiple] ++;
    }
    for(int i=1;i<multiple;i++){
        for(int j=0;j<multiple;j++){
            origin_matrix[i][j] = origin_matrix[i-1][(j*10)%multiple];
        }
    }
    dp.push_back(origin_matrix);

    int tmp = 0;
    while((1 << tmp) < length){
        matrix new_matrix(multiple, vector<long long>(multiple, 0));
        SquareMatrix(new_matrix, dp[tmp]);
        dp.push_back(new_matrix);
        tmp ++;
    }

    vector<long long> ans(multiple, 0);
    for(auto &i : v){
        ans[i%multiple] ++;
    }

    for(int i=0;i<dp.size();i++){
        if((1 << i) & (length - 1)){
            CalcMatrix(dp[i], ans);
        }
    }

    cout << ans[0] << endl;

    return 0;
}