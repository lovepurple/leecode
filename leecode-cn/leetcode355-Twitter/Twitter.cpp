#include "Twitter.h"

Twitter::Twitter()
{
	this->mFollowerMap = unordered_map<int, unordered_set<int>>();
	this->mUserTweetMap = unordered_map<int, vector<TweetData>>();
}

void Twitter::postTweet(int userId, int tweetId)
{
	unordered_map<int, unordered_set<int>>::const_iterator followerMap = this->mFollowerMap.find(userId);
	if (followerMap == this->mFollowerMap.end())
	{
		this->mFollowerMap.insert({ userId,unordered_set<int>() });
		this->mFollowerMap[userId].insert(userId);
		followerMap = this->mFollowerMap.find(userId);
	}

	unordered_map<int, vector<TweetData>>::const_iterator userTweetMap = this->mUserTweetMap.find(userId);
	if (userTweetMap == this->mUserTweetMap.end())
	{
		this->mUserTweetMap.insert({ userId,vector<TweetData>() });
		userTweetMap = this->mUserTweetMap.find(userId);
	}

	TweetData tweetData(tweetId);

	this->mUserTweetMap[userId].push_back(tweetData);
}

vector<int> Twitter::getNewsFeed(int userId)
{
	vector<int> vecTwett;
	vector<TweetData> allFolloweeTweenDataList = vector<TweetData>();
	unordered_map<int, unordered_set<int>>::const_iterator followerMap = this->mFollowerMap.find(userId);
	if (followerMap == this->mFollowerMap.end())		//C++各种判空 太麻烦了
		return vecTwett;

	for (unordered_set<int>::const_iterator it = followerMap->second.begin(); it != followerMap->second.end(); ++it)
	{
		//每个follower 取10条 做到时间上没问题
		int followeeUserID = *it;
		unordered_map<int, vector<TweetData>>::const_iterator followeeIter = this->mUserTweetMap.find(followeeUserID);
		if (followeeIter == this->mUserTweetMap.end())
			continue;

		if (followeeIter->second.size() <= 10)
			allFolloweeTweenDataList.insert(allFolloweeTweenDataList.end(), followeeIter->second.begin(), followeeIter->second.end());
		else
			allFolloweeTweenDataList.insert(allFolloweeTweenDataList.end(), followeeIter->second.end() - 10, followeeIter->second.end());
	}

	sort(allFolloweeTweenDataList);

	for (vector<TweetData>::iterator it = allFolloweeTweenDataList.begin(); it < allFolloweeTweenDataList.end(); ++it)
	{
		if (vecTwett.size() > 10)
			break;

		vecTwett.push_back((*it).tweetID);
	}


	return vecTwett;
}

void Twitter::follow(int followerId, int followeeId)
{
	unordered_map<int, unordered_set<int>>::const_iterator followerMap = this->mFollowerMap.find(followerId);
	if (followerMap == this->mFollowerMap.end())
	{
		this->mFollowerMap.insert({ followerId,unordered_set<int>() });
		this->mFollowerMap[followerId].insert(followerId);
	}

	if (followeeId == followerId)
		return;

	this->mFollowerMap[followerId].insert(followeeId);
}

void Twitter::unfollow(int followerId, int followeeId)
{
	unordered_map<int, unordered_set<int>>::const_iterator followerMap = this->mFollowerMap.find(followerId);
	if (followerMap == this->mFollowerMap.end())
	{
		this->mFollowerMap.insert({ followerId,unordered_set<int>() });
		this->mFollowerMap[followerId].insert(followerId);
	}

	if (followeeId == followerId)
		return;

	 this->mFollowerMap[followerId].erase(followeeId);
 
}


using namespace std::chrono;
void Twitter::sort(vector<TweetData>& tweetDatas)
{
	sort(tweetDatas, 0, tweetDatas.size() - 1);

}
void Twitter::sort(vector<TweetData>& tweetData, int left, int right)
{
	if (left >= right)
		return;

	TweetData pivotData = tweetData[left];
	int cursorLeft = left + 1;
	int cursorRight = right;

	//从大到小
	while (cursorLeft < cursorRight)
	{
		while (tweetData[cursorRight].postTweetTime < pivotData.postTweetTime && cursorLeft < cursorRight)
			cursorRight--;

		while (tweetData[cursorLeft].postTweetTime > pivotData.postTweetTime && cursorLeft < cursorRight)
			cursorLeft++;

		if (cursorLeft < cursorRight)
		{
			TweetData tmp = tweetData[cursorLeft];
			tweetData[cursorLeft] = tweetData[cursorRight];
			tweetData[cursorRight] = tmp;
		}
	}

	int partitionIndex = cursorLeft;
	if (pivotData.postTweetTime < tweetData[partitionIndex].postTweetTime)
	{
		TweetData tmp = tweetData[left];
		tweetData[left] = tweetData[partitionIndex];
		tweetData[partitionIndex] = tmp;
	}
	else
		partitionIndex = left;

	sort(tweetData, left, partitionIndex - 1);
	sort(tweetData, partitionIndex + 1, right);
}

long Twitter::getCurrentTime()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	return ms.count();
}



