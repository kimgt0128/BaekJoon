#include <string>
#include <vector>
#include<iostream>

using namespace std;

int dp[501][501];
int tri[501][501];


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=i; j++) {
            tri[i][j] = triangle[i - 1][j - 1];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
            answer = max(answer, dp[i][j]);
        }
    }


    return answer;
}

