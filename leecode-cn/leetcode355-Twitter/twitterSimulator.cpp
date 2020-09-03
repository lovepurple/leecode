#include <iostream>
#include "Twitter.h"

int main()
{
	Twitter* pTwitter = new Twitter();
	pTwitter->postTweet(1, 5);
	pTwitter->unfollow(1, 1);
	//auto s0 = pTwitter->getNewsFeed(1);

	pTwitter->follow(1, 1);

	////pTwitter->postTweet(2, 6);

	//auto s4 = pTwitter->getNewsFeed(2);



	auto s1 = pTwitter->getNewsFeed(1);

	return 0;
}