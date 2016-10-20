//
//  main.cpp
//  PackageProb
//
//  Created by Atina on 16/10/19.
//  Copyright © 2016年 Atina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/* 0-1背包 版本1
 * Time Complexity  O(N*V)
 * Space Complexity O(N*V)
 * 状态转移方程：dp[i][v] = max{ dp[i-1][v], dp[i-1][v-cost[i]]+val[i] }
 */
class binPackage1 {
public:
    void maxValue(const vector<int> &val, const vector<int> &cost, const int &N, const int &V, vector<vector<int>> &dp) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= V; j++) {
                if (i == 0) {
                    if (j >= cost[i]) {
                        dp[i][j] = val[i];
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                    if (j >= cost[i])
                        dp[i][j] = max(dp[i-1][j],  dp[i-1][j-cost[i]]+val[i]);
                }

            }
        }
    }
    
};
/* 0-1背包 版本2
 * Time Complexity  O(N*V)
 * Space Complexity O(V)
 * 状态转移方程：j = V,...,0 dp[j] = max{ dp[j], dp[j-cost[i]]+val[i] } 前i个物品中，容量为j时的最大价值
 */
class binPackage2 {
public:
    void maxValue(const vector<int> &val, const vector<int> &cost, const int &N, const int &V, vector<int> &dp) {
        
        for (int i = 0; i < N; i++) {
            for (int j = V; j >= cost[i]; j--) { //j从V至0逆序是防止物品放入背包多次
                dp[j] = max(dp[j], dp[j- cost[i]] + val[i]); // 滚动覆盖前一轮的dp[i]
            }
        }
    }
};
/* 完全背包 版本1
 * Time Complexity  大于O(N*V)
 * Space Complexity O(N*V)
 * 状态转移方程：dp[i][j] = max{ dp[i-1][j - k * cost[i]] + k * val[i] } 0<=k<=j/c[i]
 * 每件物品有j/c[i]种状态
 */
class completePackage1 {
public:
    void maxValue(const vector<int> &val, const vector<int> &cost, const int &N, const int &V, vector<vector<int>> &dp) {
        for (int i = 0; i < N; i++) {
            for (int j = cost[i]; j <= V; j++) {
                if (i == 0) {
                    if (j / cost[i] >= 1) {
                        dp[i][j] = j / cost[i] * val[i];
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                    if (j / cost[i] >= 1) {
                        int max_tmp = 0;
                        for (int k = 1; k <= j / cost[i]; k++) {
                            if (dp[i-1][j- k * cost[i]] + k * val[i] > max_tmp)
                                max_tmp = dp[i-1][j- k * cost[i]] + k * val[i];
                            dp[i][j] = max(dp[i][j], max_tmp);
                        }
                    }
                }
            }
        }
    }
};
/* 完全背包 版本2
 * Time Complexity  大于O(N*V)
 * Space Complexity O(N*V)
 * 状态转移方程：dp[i][j] = max{ dp[i-1][j - k * cost[i]] + k * val[i] } 0 <= k<= log(j/c[i])
 * 每件物品降低为 log(j/c[i]) 种状态
 */
class completePackage2 {
public:
    void maxValue(const vector<int> &val, const vector<int> &cost, const int &N, const int &V, vector<vector<int>> &dp) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= V; j++) {
                if (i == 0) {
                    if (j / cost[i] >= 1) {
                        dp[i][j] = j / cost[i] * val[i];
                    }
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    if (j / cost[i] >= 1) {
                        int max_tmp = 0;
                        for (int k = 1; k <= j / cost[i]; k <<= 1) {
                            if (dp[i - 1][j - k * cost[i]] + k * val[i] > max_tmp)
                                max_tmp = dp[i-1][j - k * cost[i]] + k * val[i];
                            dp[i][j] = max(dp[i][j], max_tmp);
                        }
                    }
                }
            }
        }
    }
};
/* 完全背包 版本3
 * Time Complexity  (N*V)
 * Space Complexity O(V)
 * 状态转移方程：dp[j] = max{ dp[j - k * cost[i]] + k * val[i] } 0 <= k <= j/c[i]
 * 每件物品降低为 log(j/c[i]) 种状态
 */

class completePackage3 {
    public:
    void maxValue(const vector<int> &val, const vector<int> &cost, const int &N, const int &V, vector<int> &dp){
        for (int i = 0; i < N; i++) {
            for (int j = cost[i]; j <= V; j++) {
                int max_tmp = 0;
                for (int k = 1; k <= j / cost[i]; k++) {
                    
                    max_tmp = max(max_tmp, dp[j- k * cost[i]] + k * val[i]);
                }
                dp[j] = max(dp[j], max_tmp);
            }
        }
    }

};
/* 多重背包 版本1
 * Time Complexity  大于O(N*V)
 * Space Complexity O(N*V)
 * 状态转移方程：dp[i][j] = max{ dp[i-1][j - k * cost[i]] + k * val[i] } 0<=k<=j/c[i])
 * 每件物品降低为 min{ j/c[i], num[i]} 种状态
 */
class mulPackage1 {
public:
    void maxValue(const vector<int> &val, const vector<int> &cost, const int &N, const int &V, const vector<int> &num, vector<vector<int>> &dp) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= V; j++) {
                if (i == 0) {
                    if (j >= cost[i])
                        dp[i][j] = min(j / cost[i], num[i]) * val[i];
                } else {
                    dp[i][j] = dp[i-1][j];
                    if (j >= cost[i]) {
                        int k = min(num[i], j / cost[i]);
                        int max_tmp = 0;
                        while (k > 0) {
                            
                            max_tmp = max(max_tmp, dp[i - 1][j - k * cost[i]] + k * val[i]);
                            
                            k --;
                        }
                        dp[i][j] = max(dp[i][j], max_tmp);
                    }
                }
            
            }
            
        }
    }
};

class mulPackage2 {
public:
    void maxValue(vector<int> &val, vector<int> &cost, const int N, const int V, vector<int> &num, vector<int> &dp){
        vector<int> num_tmp, cost_tmp, val_tmp;
        //将num[i]中的每一个数量，转换成每一个系数
        for (int i = 0; i < N; i++) {
            int p = 1;
            while (num[i] - pow(2, p) + 1 >= 0) {
                num_tmp.push_back(pow(2, p-1));
                cost_tmp.push_back(cost[i] * pow(2, p-1));
                val_tmp.push_back(val[i] * pow(2, p-1));
                
                p ++;
            }
            int x = num[i] - pow(2, p-1) + 1;
            if (x > 0) {
                num_tmp.push_back(x);
                cost_tmp.push_back(cost[i] * x);
                val_tmp.push_back(val[i] * x);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = V; j >= cost[i]; j--) {
                dp[j] = max(dp[j], dp[j - cost_tmp[i]] + val_tmp[i]);
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> val = {9, 9, 4, 1};
    vector<int> cost = {3, 5, 9, 8};
    vector<int> num = {3, 1, 2, 3};
    int N = 4, V = 20;
    vector<vector<int>> dp(N, vector<int>(V+1, 0));
    vector<int> d(V+1, 0);
//    binPackage1 pkg;
//    pkg.maxValue(val, cost, N, V, dp);
//    cout << dp[N-1][V];
//    binPackage2 pkg;
//    pkg.maxValue(val, cost, N, V, d);
//    cout << d[V] << endl;
//    completePackage1 pkg;
//    pkg.maxValue(val, cost, N, V, dp);
//    cout << dp[N-1][V] << endl;
//    completePackage2 pkg;
//    pkg.maxValue(val, cost, N, V, dp);
//    cout << dp[N-1][V] << endl;
//    completePackage3 pkg;
//    pkg.maxValue(val, cost, N, V, d);
//    cout << d[V] << endl;
    
//    mulPackage1 pkg;
//    pkg.maxValue(val, cost, N, V, num, dp);
//    cout << dp[N-1][V] << endl;
    mulPackage2 pkg;
    pkg.maxValue(val, cost, N, V, num, d);
    cout << d[V] << endl;

    
    return 0;
}