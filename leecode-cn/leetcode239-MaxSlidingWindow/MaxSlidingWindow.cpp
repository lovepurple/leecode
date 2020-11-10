#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//自己写的 ，用例大的情况下会有超时的问题， 
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> vecMaxWindowValue;
	if (nums.size() < k)
		return vecMaxWindowValue;

	int right = 0;
	int left = 0;

	int maxOfWindow = INT_MIN;
	while (right < nums.size())
	{
		while (right - left < k)
		{
			maxOfWindow = max(maxOfWindow, nums[right]);
			right++;
		}

		if (right - left == k)
		{
			vecMaxWindowValue.push_back(maxOfWindow);
			left++;

			//会有超时的问题。。。
			if (left < nums.size())
			{
				maxOfWindow = nums[left];
				for (int i = left; i < right; ++i)
					maxOfWindow = max(maxOfWindow, nums[i]);
			}
		}
	}

	return vecMaxWindowValue;
}

vector<int> maxSlidingWindowImplementViaDeque(vector<int>& nums, int k);

//双端队列求解 维护一个单调队列
class MonotonQueue
{
public:
	int max();
	int push(int pushVal);
	int pop(int popVal);
private:
	//deque为双端队列 能从两端插入会弹出
	deque<int> deque;
};


int main()
{
	vector<int> nums = { 1,  -1 };
	int k = 1;



	vector<int> maxWindow = maxSlidingWindowImplementViaDeque(nums, k);

	cout << maxWindow.size();

	return 0;
}

int MonotonQueue::max()
{
	if (!deque.empty())
		return deque.front();

	return INT_MIN;
}

int MonotonQueue::push(int pushVal)
{
	//将所有小于pushVal的都干掉
	while (!deque.empty() && deque.back() < pushVal)
		deque.pop_back();

	deque.push_back(pushVal);

	return max();
}

int MonotonQueue::pop(int popVal)
{
	if (popVal == max())
		deque.pop_front();

	return max();
}

vector<int> maxSlidingWindowImplementViaDeque(vector<int>& nums, int k)
{
	vector<int> vecMaxWindowValue;
	if (nums.size() < k)
		return vecMaxWindowValue;

	MonotonQueue monotonQueue;
	for (int i = 0; i < k - 1; ++i)
		monotonQueue.push(nums[i]);

	for (int i = k - 1; i < nums.size(); ++i)
	{
		monotonQueue.push(nums[i]);
		vecMaxWindowValue.push_back(monotonQueue.max());
		monotonQueue.pop(nums[i - k + 1]);		//pop 窗口最左边的元素
	}

	return vecMaxWindowValue;

}
