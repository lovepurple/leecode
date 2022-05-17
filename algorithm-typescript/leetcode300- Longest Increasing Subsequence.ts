function lengthOfLIS(nums: number[]): number {

    if (nums.length <= 1)
        return nums.length;

    /**
     * 定义dp[i] 到第i个字符的最长上升子序列的长度
     * 
     */
    let dp: number[] = new Array<number>(nums.length);
    dp[0] = 1;
    let lis = 1;
    for (let i = 1; i < nums.length; ++i) {

        dp[i] = 1;
        for (let j = 0; j < i; ++j) {

            //当前的数比之前的要大，更新
            //其中dp[j] 已经表示的是到j为止最大的上升子序列数量
            //而 num[j] < nums[i] 一定是 当前的数和j组成了上升子序列
            if (nums[j] < nums[i]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }

        lis = Math.max(dp[i], lis);
    }

    return lis;
}


let nums: number[] = [0, 1, 0, 3, 2, 3];
let lis = lengthOfLIS(nums);
console.log(lis);