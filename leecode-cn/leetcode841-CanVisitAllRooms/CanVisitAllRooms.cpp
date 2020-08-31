#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms);

	/// <summary>
	/// 非递归实现DFS
	/// </summary>
	/// <param name="room"></param>
	/// <returns></returns>
	bool canVisitAllRoomsNonRecursion(vector<vector<int>>& room);

	bool dfs(vector<vector<int>>& rooms, int i, vector<bool>& visited);
};

int main()
{
	Solution s;
	//vector<vector<int>> rooms = { {1},{2},{3},{} };
	vector<vector<int>> rooms = { {1,3},{3,0,1},{2},{0} };
	cout << s.canVisitAllRooms(rooms);
	//cout << s.canVisitAllRoomsNonRecursion(rooms);

	return 0;
}

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms)
{
	vector<bool> visitedRoom(rooms.size());

	return dfs(rooms, 0, visitedRoom);
}

bool Solution::canVisitAllRoomsNonRecursion(vector<vector<int>>& room)
{
	vector<bool> visited(room.size());
	stack<int> roomStack;
	for (int i = 0; i < room[0].size(); ++i)
		roomStack.push(room[0][i]);
	visited[0] = true;

	while (!roomStack.empty())
	{
		int roomKey = roomStack.top();
		roomStack.pop();
		if (visited[roomKey])
			continue;

		visited[roomKey] = true;
		vector<int> roomKeys = room[roomKey];
		for (int i = 0; i < roomKeys.size(); ++i)
			roomStack.push(roomKeys[i]);
	}

	bool isVisited = true;
	for (int i = 0; i < visited.size(); ++i)
		isVisited = visited[i] && isVisited;


	return isVisited;
}

bool Solution::dfs(vector<vector<int>>& rooms, int roomIndex, vector<bool>& visited)
{
	if (visited[roomIndex])
		return true;

	visited[roomIndex] = true;
	vector<int> keysInRoom = rooms[roomIndex];
	for (int i = 0; i < keysInRoom.size(); ++i)
	{
		int key = keysInRoom[i];
		dfs(rooms, key, visited);
	}

	bool isVisitedAllRoom = true;
	for (int i = 0; i < visited.size(); ++i)
	{
		if (!visited[i])
		{
			isVisitedAllRoom = false;
			break;
		}
	}

	return isVisitedAllRoom;
}
