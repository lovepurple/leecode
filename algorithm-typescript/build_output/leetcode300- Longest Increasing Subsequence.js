"use strict";
function lengthOfLIS(nums) {
    if (nums.length <= 1)
        return nums.length;
    /**
     * 定义dp[i] 到第i个字符的最长上升子序列的长度
     *
     */
    let dp = new Array(nums.length);
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
let nums = [0, 1, 0, 3, 2, 3];
let lis = lengthOfLIS(nums);
console.log(lis);
//# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoibGVldGNvZGUzMDAtIExvbmdlc3QgSW5jcmVhc2luZyBTdWJzZXF1ZW5jZS5qcyIsInNvdXJjZVJvb3QiOiIiLCJzb3VyY2VzIjpbIi4uL2xlZXRjb2RlMzAwLSBMb25nZXN0IEluY3JlYXNpbmcgU3Vic2VxdWVuY2UudHMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IjtBQUFBLFNBQVMsV0FBVyxDQUFDLElBQWM7SUFFL0IsSUFBSSxJQUFJLENBQUMsTUFBTSxJQUFJLENBQUM7UUFDaEIsT0FBTyxJQUFJLENBQUMsTUFBTSxDQUFDO0lBRXZCOzs7T0FHRztJQUNILElBQUksRUFBRSxHQUFhLElBQUksS0FBSyxDQUFTLElBQUksQ0FBQyxNQUFNLENBQUMsQ0FBQztJQUNsRCxFQUFFLENBQUMsQ0FBQyxDQUFDLEdBQUcsQ0FBQyxDQUFDO0lBQ1YsSUFBSSxHQUFHLEdBQUcsQ0FBQyxDQUFDO0lBQ1osS0FBSyxJQUFJLENBQUMsR0FBRyxDQUFDLEVBQUUsQ0FBQyxHQUFHLElBQUksQ0FBQyxNQUFNLEVBQUUsRUFBRSxDQUFDLEVBQUU7UUFFbEMsRUFBRSxDQUFDLENBQUMsQ0FBQyxHQUFHLENBQUMsQ0FBQztRQUNWLEtBQUssSUFBSSxDQUFDLEdBQUcsQ0FBQyxFQUFFLENBQUMsR0FBRyxDQUFDLEVBQUUsRUFBRSxDQUFDLEVBQUU7WUFFeEIsZUFBZTtZQUNmLDhCQUE4QjtZQUM5Qix1Q0FBdUM7WUFDdkMsSUFBSSxJQUFJLENBQUMsQ0FBQyxDQUFDLEdBQUcsSUFBSSxDQUFDLENBQUMsQ0FBQyxFQUFFO2dCQUNuQixFQUFFLENBQUMsQ0FBQyxDQUFDLEdBQUcsSUFBSSxDQUFDLEdBQUcsQ0FBQyxFQUFFLENBQUMsQ0FBQyxDQUFDLEVBQUUsRUFBRSxDQUFDLENBQUMsQ0FBQyxHQUFHLENBQUMsQ0FBQyxDQUFDO2FBQ3RDO1NBQ0o7UUFFRCxHQUFHLEdBQUcsSUFBSSxDQUFDLEdBQUcsQ0FBQyxFQUFFLENBQUMsQ0FBQyxDQUFDLEVBQUUsR0FBRyxDQUFDLENBQUM7S0FDOUI7SUFFRCxPQUFPLEdBQUcsQ0FBQztBQUNmLENBQUM7QUFHRCxJQUFJLElBQUksR0FBYSxDQUFDLENBQUMsRUFBRSxDQUFDLEVBQUUsQ0FBQyxFQUFFLENBQUMsRUFBRSxDQUFDLEVBQUUsQ0FBQyxDQUFDLENBQUM7QUFDeEMsSUFBSSxHQUFHLEdBQUcsV0FBVyxDQUFDLElBQUksQ0FBQyxDQUFDO0FBQzVCLE9BQU8sQ0FBQyxHQUFHLENBQUMsR0FBRyxDQUFDLENBQUMifQ==