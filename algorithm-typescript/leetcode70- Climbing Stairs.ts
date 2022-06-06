


/**
 * 爬楼梯求的是多少种方法，而不是多少步  到前 n-1 n-2后 就是最终的方法数
 * dp[i] 到第i步有多少种走法
 * @param n 
 */
function climbStairs(n: number): number {

    if (n <= 2)
        return n;

    let dp: number[] = new Array<number>(n + 1);
    dp[0] = 0
    dp[1] = 1;
    dp[2] = 2;

    for (let i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

let stairsCount = 4;
console.log(climbStairs(stairsCount));
