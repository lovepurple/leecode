/*
	https://leetcode-cn.com/problems/hanota-lcci/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution();
	~Solution();

	void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
	{
		if (A.size() == 1)
		{
			int item = A.back();
			A.pop_back();
			C.push_back(item);

			 //第" + (++m) +" 次移动 : " +" 把 "+ disks+" 号圆盘从 " + N +" ->移到->  " + M);
		}
		else
		{
			int currentSize = A.size();

		}
	}


private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
	return 0;
}