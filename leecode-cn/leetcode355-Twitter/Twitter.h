#pragma once
#include <vector>
#include <unordered_map>
#include <chrono>				//取时间
#include <unordered_set>

using namespace std;
class Twitter
{
	struct TweetData
	{
		int tweetID;
		long postTweetTime;

		TweetData(int id) :tweetID(id) {
			postTweetTime = Twitter::getCurrentTime();
		}
	};

public:
	Twitter();

	void postTweet(int userId, int tweetId);

	vector<int> getNewsFeed(int userId);

	void follow(int followerId, int followeeId);

	void unfollow(int followerId, int followeeId);

private:
	unordered_map<int, vector<TweetData>> mUserTweetMap;
	unordered_map<int, unordered_set<int>> mFollowerMap;

	void sort(vector<TweetData>& tweetDatas);

	void sort(vector<TweetData>& tweetData, int left, int right);

	static long getCurrentTime();

};

