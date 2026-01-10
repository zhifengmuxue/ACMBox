#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
using namespace std;

const ll NEG_INF = -1e18; // 负无穷，表示不可达状态
ll ans = NEG_INF; // 全局答案变量，记录到达对岸的最大冰冻指数

signed main(){
    IOS;
    int N, L, R;
    cin >> N >> L >> R;
    
    // a[i]存储位置i的冰冻指数
    vector<ll> a(N + 1);
    
    // dp[i]表示到达位置i时能获得的最大冰冻指数总和
    // 初始化为负无穷表示不可达，数组大小为N+R+1因为可能跳到N+R的位置
    vector<ll> dp(N + R + 1, ans);
    
    dp[0] = 0; // 起点位置0的初始分数为0（题目说明a[0]=0）
    
    // 读入每个位置的冰冻指数
    for (int i = 0; i <= N; i++) {
        cin >> a[i];
    }
    
    // 单调队列，存储位置的索引
    // 队列维护递减性：队首元素对应的dp值最大
    deque<int> dq;
    
    // 枚举当前位置i，从1到N+R
    // i > N表示已经跳到对岸
    for (int i = 1; i <= N + R; i++) {
        
        // 位置i可以从区间[i-R, i-L]的任意位置跳过来
        // left是刚进入合法前驱范围的位置（距离最近）
        // right是即将离开合法前驱范围的位置（距离最远）
        int left = i - L;  // i-L是第一次成为i的合法前驱
        int right = i - R; // i-R是最后一次作为i的合法前驱，再小就不合法了
        
        // 将新进入窗口的位置left加入单调队列
        // 条件：left必须在有效范围内[0, N]，且该位置可达（dp值不是负无穷）
        if (left >= 0 && left <= N && dp[left] != NEG_INF) {
            // 维护单调递减队列：从队尾移除所有dp值 <= dp[left]的元素
            // 这样保证队首始终是窗口内dp值最大的位置
            while (!dq.empty() && dp[dq.back()] <= dp[left]) {
                dq.pop_back();
            }
            dq.push_back(left); // 将left加入队尾
        }
        
        
        // 从队首移除已经不在合法窗口内的位置
        // 如果队首位置 < i-R，说明距离超过R，不再是合法前驱
        while (!dq.empty() && dq.front() < right) {
            dq.pop_front();
        }
        

        // 更新dp[i]或答案
        if (!dq.empty()) {
            // 队列不空，说明存在合法前驱
            // 队首元素就是所有合法前驱中dp值最大的位置
            if (i <= N) {
                // 位置i还在河内（0到N），更新dp[i]
                // dp[i] = 从最优前驱跳到i的最大值 + 位置i的冰冻指数
                dp[i] = dp[dq.front()] + a[i];
            } else {
                // 位置i已经到对岸（>N），更新最终答案
                // 从队首位置跳出去就到达对岸了
                ans = max(ans, dp[dq.front()]);
            }
        }
    }
    
    // 输出到达对岸的最大冰冻指数
    cout << ans << endl;
    
    return 0;
}