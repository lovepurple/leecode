#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxQueue
{
public:
	MaxQueue();
	~MaxQueue();
	int max_value();
	void push_back(int value);
	int pop_front();

private:
	vector<int> m_queueData;

};

MaxQueue::MaxQueue()
{
	this->m_queueData = vector<int>();
}

MaxQueue::~MaxQueue()
{
}

int MaxQueue::max_value()
{
	int queueMax = -1;
	for (vector<int>::iterator it = this->m_queueData.begin(); it != m_queueData.end(); ++it)
		queueMax = max(queueMax, *it);

	return queueMax;
}

void MaxQueue::push_back(int value)
{
	m_queueData.push_back(value);
}

int MaxQueue::pop_front()
{
	if (this->m_queueData.size() > 0)
	{
		int queueFront = this->m_queueData[0];
		this->m_queueData.erase(this->m_queueData.begin());

		return queueFront;
	}

	return -1;
}
