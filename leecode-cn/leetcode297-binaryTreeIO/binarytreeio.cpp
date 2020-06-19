/*
	你可以将以下二叉树：

	1
   / \
  2   3
	 / \
	4   5

序列化为 "[1,2,3,null,null,4,5]"

  二叉树的序列化和反序列化
	 queue + BFS

	 使用满二叉树可能会多出一堆null 节点，
  */

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
	Codec();
	~Codec();

	/// <summary>
	/// 序列化二叉树，使用BFS 将原二叉树视为完全二叉树 
	/// </summary>
	/// <param name="root"></param>
	/// <returns></returns>
	string serialize(TreeNode* root);

	TreeNode* deserialize(string data);

	/// <summary>
	/// 递归序列化二叉树
	/// </summary>
	/// <param name="root"></param>
	/// <returns></returns>
	string serializeRecursive(TreeNode* root);

	/// <summary>
	/// 递归反序列化二叉树
	/// </summary>
	/// <param name="strData"></param>
	/// <returns></returns>
	TreeNode* deserializeRecursive(string strData);

	vector<string> splitSerialzeStr(string serializedData, vector<string>& out);

private:
	/// <summary>
	/// 获取指定深度结点数量
	/// </summary>
	/// <param name="fullBinaryTreeDepth"></param>
	/// <returns></returns>
	int getNodeCountByDepth(int fullBinaryTreeDepth);

	int getDepthByIndex(int index);

	TreeNode* deserializeNodeRecursive(queue<string>& nodeValueQueue);


};

Codec::Codec()
{
}

Codec::~Codec()
{
}

string Codec::serialize(TreeNode* root)
{
	queue<TreeNode*> nodeQueue;

	nodeQueue.push(root);

	int currentIndex = 0;
	string strData;
	vector<TreeNode*> levelNodeQueue;
	//一层的所有结点都是NULL 结束

	while (nodeQueue.size() > 0)
	{
		TreeNode* pTreeNode = nodeQueue.front();
		nodeQueue.pop();

		levelNodeQueue.push_back(pTreeNode);

		if (pTreeNode == nullptr)
		{
			nodeQueue.push(nullptr);
			nodeQueue.push(nullptr);
		}
		else
		{
			nodeQueue.push(pTreeNode->left);
			nodeQueue.push(pTreeNode->right);
		}

		//每一层结束
		int currentDepth = getDepthByIndex(currentIndex);
		if (currentIndex == pow(2, currentDepth + 1) - 2)
		{
			bool hasValidNode = false;
			for (vector<TreeNode*>::iterator it = levelNodeQueue.begin(); it != levelNodeQueue.end(); ++it)
			{
				if (*it != nullptr)
				{
					hasValidNode = true;
					break;;
				}
			}

			if (hasValidNode)
			{
				for (vector<TreeNode*>::iterator it = levelNodeQueue.begin(); it != levelNodeQueue.end(); ++it)
				{
					if (*it == nullptr)
						strData.append("null");
					else
						strData.append(to_string((*it)->val));

					strData.append(",");
				}

				levelNodeQueue.clear();
			}
			else
				return strData;

		}
		currentIndex++;
	}

	return strData;
}

TreeNode* Codec::deserialize(string data)
{
	vector<string> nodeVec;
	nodeVec = this->splitSerialzeStr(data, nodeVec);

	int currentIndex = 0;
	int currentDepth = 0;

	queue<TreeNode*> parentNodeQueue;
	queue<TreeNode*> currentDepthNodeQueue;
	TreeNode* pRootNode = nullptr;

	if (currentIndex < nodeVec.size())
	{
		string nodeValue = nodeVec[currentIndex];

		if (currentIndex == 0)
		{
			pRootNode = new TreeNode(stoi(nodeValue));
			parentNodeQueue.push(pRootNode);
			currentIndex++;
		}

		while (parentNodeQueue.size() > 0 && currentIndex < nodeVec.size())
		{
			TreeNode* pParentNode = parentNodeQueue.front();
			parentNodeQueue.pop();

			for (int i = 0; i < 2; ++i)
			{
				string strNodeValue = nodeVec[currentIndex];
				TreeNode* pTreeNode = nullptr;
				if (strNodeValue != "NULL")
					pTreeNode = new TreeNode(stoi(strNodeValue));

				currentDepthNodeQueue.push(pTreeNode);

				if (pParentNode != nullptr)
				{
					if (i % 2 == 0)
						pParentNode->left = pTreeNode;
					else
						pParentNode->right = pTreeNode;
				}

				currentIndex++;
			}


			if (parentNodeQueue.size() == 0)
			{
				parentNodeQueue = currentDepthNodeQueue;
				currentDepthNodeQueue = queue<TreeNode*>();
			}
		}
	}

	return pRootNode;
}

/*
	理解：
		广度优先的递归

*/
string Codec::serializeRecursive(TreeNode* pNode)
{
	if (pNode == nullptr)
		return "NULL,";

	string strSerializedData = to_string(pNode->val) + ",";

	//递归下去
	strSerializedData.append(serializeRecursive(pNode->left));
	strSerializedData.append(serializeRecursive(pNode->right));

	return strSerializedData;
}

int Codec::getNodeCountByDepth(int fullBinaryTreeDepth)
{
	return pow(2, fullBinaryTreeDepth);
}

int Codec::getDepthByIndex(int index)
{
	return log2(index + 1);
}

TreeNode* Codec::deserializeNodeRecursive(queue<string>& nodeValueQuue)
{
	string strNodeValue = nodeValueQuue.front();
	nodeValueQuue.pop();

	if (strNodeValue == "NULL")
		return nullptr;

	//递归下去。。。
	TreeNode* pNode = new TreeNode(stoi(strNodeValue));
	pNode->left = deserializeNodeRecursive(nodeValueQuue);
	pNode->right = deserializeNodeRecursive(nodeValueQuue);

	return pNode;
}

TreeNode* Codec::deserializeRecursive(string strData)
{
	stringstream input(strData);
	string strTemp;
	queue<string> strNodeQueue;

	while (getline(input,strTemp,','))
		strNodeQueue.push(strTemp);


	TreeNode* pRootNode = deserializeNodeRecursive(strNodeQueue);

	return pRootNode;
}

vector<string> Codec::splitSerialzeStr(string serializedData, vector<string>& out)
{
	//stringstream 处理字符串分割
	out.clear();

	stringstream strStream(serializedData);
	string strTemp;

	while (getline(strStream, strTemp, ',') && strTemp.find_first_not_of(' ') != string::npos && !strTemp.empty())
		out.push_back(strTemp);

	return out;
}

int main()
{
	/*TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->right = new TreeNode(5);
	root->right->right->left = new TreeNode(6);



	string serializeStrData = solution.serialize(root);
	cout << "1:----------" << serializeStrData << endl;*/
	Codec solution;
	string serialzeStrData = "1,NULL,2,NULL,3,NULL,4,NULL,5,NULL,6,NULL,7,NULL,8,NULL,9,NULL,10,NULL,11,NULL,12,NULL,13,NULL,14,NULL,15,NULL,16,NULL,17,NULL,18,NULL,19,NULL,20,NULL,21,NULL,22,NULL,23,NULL,24,NULL,25,NULL,26,NULL,27,NULL,28,NULL,29,NULL,30,NULL,31,NULL,32,NULL,33,NULL,34,NULL,35,NULL,36,NULL,37,NULL,38,NULL,39,NULL,40,NULL,41,NULL,42,NULL,43,NULL,44,NULL,45,NULL,46,NULL,47,NULL,48,NULL,49,NULL,50,NULL,51,NULL,52,NULL,53,NULL,54,NULL,55,NULL,56,NULL,57,NULL,58,NULL,59,NULL,60,NULL,61,NULL,62,NULL,63,NULL,64,NULL,65,NULL,66,NULL,67,NULL,68,NULL,69,NULL,70,NULL,71,NULL,72,NULL,73,NULL,74,NULL,75,NULL,76,NULL,77,NULL,78,NULL,79,NULL,80,NULL,81,NULL,82,NULL,83,NULL,84,NULL,85,NULL,86,NULL,87,NULL,88,NULL,89,NULL,90,NULL,91,NULL,92,NULL,93,NULL,94,NULL,95,NULL,96,NULL,97,NULL,98,NULL,99,NULL,100,NULL,101,NULL,102,NULL,103,NULL,104,NULL,105,NULL,106,NULL,107,NULL,108,NULL,109,NULL,110,NULL,111,NULL,112,NULL,113,NULL,114,NULL,115,NULL,116,NULL,117,NULL,118,NULL,119,NULL,120,NULL,121,NULL,122,NULL,123,NULL,124,NULL,125,NULL,126,NULL,127,NULL,128,NULL,129,NULL,130,NULL,131,NULL,132,NULL,133,NULL,134,NULL,135,NULL,136,NULL,137,NULL,138,NULL,139,NULL,140,NULL,141,NULL,142,NULL,143,NULL,144,NULL,145,NULL,146,NULL,147,NULL,148,NULL,149,NULL,150,NULL,151,NULL,152,NULL,153,NULL,154,NULL,155,NULL,156,NULL,157,NULL,158,NULL,159,NULL,160,NULL,161,NULL,162,NULL,163,NULL,164,NULL,165,NULL,166,NULL,167,NULL,168,NULL,169,NULL,170,NULL,171,NULL,172,NULL,173,NULL,174,NULL,175,NULL,176,NULL,177,NULL,178,NULL,179,NULL,180,NULL,181,NULL,182,NULL,183,NULL,184,NULL,185,NULL,186,NULL,187,NULL,188,NULL,189,NULL,190,NULL,191,NULL,192,NULL,193,NULL,194,NULL,195,NULL,196,NULL,197,NULL,198,NULL,199,NULL,200,NULL,201,NULL,202,NULL,203,NULL,204,NULL,205,NULL,206,NULL,207,NULL,208,NULL,209,NULL,210,NULL,211,NULL,212,NULL,213,NULL,214,NULL,215,NULL,216,NULL,217,NULL,218,NULL,219,NULL,220,NULL,221,NULL,222,NULL,223,NULL,224,NULL,225,NULL,226,NULL,227,NULL,228,NULL,229,NULL,230,NULL,231,NULL,232,NULL,233,NULL,234,NULL,235,NULL,236,NULL,237,NULL,238,NULL,239,NULL,240,NULL,241,NULL,242,NULL,243,NULL,244,NULL,245,NULL,246,NULL,247,NULL,248,NULL,249,NULL,250,NULL,251,NULL,252,NULL,253,NULL,254,NULL,255,NULL,256,NULL,257,NULL,258,NULL,259,NULL,260,NULL,261,NULL,262,NULL,263,NULL,264,NULL,265,NULL,266,NULL,267,NULL,268,NULL,269,NULL,270,NULL,271,NULL,272,NULL,273,NULL,274,NULL,275,NULL,276,NULL,277,NULL,278,NULL,279,NULL,280,NULL,281,NULL,282,NULL,283,NULL,284,NULL,285,NULL,286,NULL,287,NULL,288,NULL,289,NULL,290,NULL,291,NULL,292,NULL,293,NULL,294,NULL,295,NULL,296,NULL,297,NULL,298,NULL,299,NULL,300,NULL,301,NULL,302,NULL,303,NULL,304,NULL,305,NULL,306,NULL,307,NULL,308,NULL,309,NULL,310,NULL,311,NULL,312,NULL,313,NULL,314,NULL,315,NULL,316,NULL,317,NULL,318,NULL,319,NULL,320,NULL,321,NULL,322,NULL,323,NULL,324,NULL,325,NULL,326,NULL,327,NULL,328,NULL,329,NULL,330,NULL,331,NULL,332,NULL,333,NULL,334,NULL,335,NULL,336,NULL,337,NULL,338,NULL,339,NULL,340,NULL,341,NULL,342,NULL,343,NULL,344,NULL,345,NULL,346,NULL,347,NULL,348,NULL,349,NULL,350,NULL,351,NULL,352,NULL,353,NULL,354,NULL,355,NULL,356,NULL,357,NULL,358,NULL,359,NULL,360,NULL,361,NULL,362,NULL,363,NULL,364,NULL,365,NULL,366,NULL,367,NULL,368,NULL,369,NULL,370,NULL,371,NULL,372,NULL,373,NULL,374,NULL,375,NULL,376,NULL,377,NULL,378,NULL,379,NULL,380,NULL,381,NULL,382,NULL,383,NULL,384,NULL,385,NULL,386,NULL,387,NULL,388,NULL,389,NULL,390,NULL,391,NULL,392,NULL,393,NULL,394,NULL,395,NULL,396,NULL,397,NULL,398,NULL,399,NULL,400,NULL,401,NULL,402,NULL,403,NULL,404,NULL,405,NULL,406,NULL,407,NULL,408,NULL,409,NULL,410,NULL,411,NULL,412,NULL,413,NULL,414,NULL,415,NULL,416,NULL,417,NULL,418,NULL,419,NULL,420,NULL,421,NULL,422,NULL,423,NULL,424,NULL,425,NULL,426,NULL,427,NULL,428,NULL,429,NULL,430,NULL,431,NULL,432,NULL,433,NULL,434,NULL,435,NULL,436,NULL,437,NULL,438,NULL,439,NULL,440,NULL,441,NULL,442,NULL,443,NULL,444,NULL,445,NULL,446,NULL,447,NULL,448,NULL,449,NULL,450,NULL,451,NULL,452,NULL,453,NULL,454,NULL,455,NULL,456,NULL,457,NULL,458,NULL,459,NULL,460,NULL,461,NULL,462,NULL,463,NULL,464,NULL,465,NULL,466,NULL,467,NULL,468,NULL,469,NULL,470,NULL,471,NULL,472,NULL,473,NULL,474,NULL,475,NULL,476,NULL,477,NULL,478,NULL,479,NULL,480,NULL,481,NULL,482,NULL,483,NULL,484,NULL,485,NULL,486,NULL,487,NULL,488,NULL,489,NULL,490,NULL,491,NULL,492,NULL,493,NULL,494,NULL,495,NULL,496,NULL,497,NULL,498,NULL,499,NULL,500,NULL,501,NULL,502,NULL,503,NULL,504,NULL,505,NULL,506,NULL,507,NULL,508,NULL,509,NULL,510,NULL,511,NULL,512,NULL,513,NULL,514,NULL,515,NULL,516,NULL,517,NULL,518,NULL,519,NULL,520,NULL,521,NULL,522,NULL,523,NULL,524,NULL,525,NULL,526,NULL,527,NULL,528,NULL,529,NULL,530,NULL,531,NULL,532,NULL,533,NULL,534,NULL,535,NULL,536,NULL,537,NULL,538,NULL,539,NULL,540,NULL,541,NULL,542,NULL,543,NULL,544,NULL,545,NULL,546,NULL,547,NULL,548,NULL,549,NULL,550,NULL,551,NULL,552,NULL,553,NULL,554,NULL,555,NULL,556,NULL,557,NULL,558,NULL,559,NULL,560,NULL,561,NULL,562,NULL,563,NULL,564,NULL,565,NULL,566,NULL,567,NULL,568,NULL,569,NULL,570,NULL,571,NULL,572,NULL,573,NULL,574,NULL,575,NULL,576,NULL,577,NULL,578,NULL,579,NULL,580,NULL,581,NULL,582,NULL,583,NULL,584,NULL,585,NULL,586,NULL,587,NULL,588,NULL,589,NULL,590,NULL,591,NULL,592,NULL,593,NULL,594,NULL,595,NULL,596,NULL,597,NULL,598,NULL,599,NULL,600,NULL,601,NULL,602,NULL,603,NULL,604,NULL,605,NULL,606,NULL,607,NULL,608,NULL,609,NULL,610,NULL,611,NULL,612,NULL,613,NULL,614,NULL,615,NULL,616,NULL,617,NULL,618,NULL,619,NULL,620,NULL,621,NULL,622,NULL,623,NULL,624,NULL,625,NULL,626,NULL,627,NULL,628,NULL,629,NULL,630,NULL,631,NULL,632,NULL,633,NULL,634,NULL,635,NULL,636,NULL,637,NULL,638,NULL,639,NULL,640,NULL,641,NULL,642,NULL,643,NULL,644,NULL,645,NULL,646,NULL,647,NULL,648,NULL,649,NULL,650,NULL,651,NULL,652,NULL,653,NULL,654,NULL,655,NULL,656,NULL,657,NULL,658,NULL,659,NULL,660,NULL,661,NULL,662,NULL,663,NULL,664,NULL,665,NULL,666,NULL,667,NULL,668,NULL,669,NULL,670,NULL,671,NULL,672,NULL,673,NULL,674,NULL,675,NULL,676,NULL,677,NULL,678,NULL,679,NULL,680,NULL,681,NULL,682,NULL,683,NULL,684,NULL,685,NULL,686,NULL,687,NULL,688,NULL,689,NULL,690,NULL,691,NULL,692,NULL,693,NULL,694,NULL,695,NULL,696,NULL,697,NULL,698,NULL,699,NULL,700,NULL,701,NULL,702,NULL,703,NULL,704,NULL,705,NULL,706,NULL,707,NULL,708,NULL,709,NULL,710,NULL,711,NULL,712,NULL,713,NULL,714,NULL,715,NULL,716,NULL,717,NULL,718,NULL,719,NULL,720,NULL,721,NULL,722,NULL,723,NULL,724,NULL,725,NULL,726,NULL,727,NULL,728,NULL,729,NULL,730,NULL,731,NULL,732,NULL,733,NULL,734,NULL,735,NULL,736,NULL,737,NULL,738,NULL,739,NULL,740,NULL,741,NULL,742,NULL,743,NULL,744,NULL,745,NULL,746,NULL,747,NULL,748,NULL,749,NULL,750,NULL,751,NULL,752,NULL,753,NULL,754,NULL,755,NULL,756,NULL,757,NULL,758,NULL,759,NULL,760,NULL,761,NULL,762,NULL,763,NULL,764,NULL,765,NULL,766,NULL,767,NULL,768,NULL,769,NULL,770,NULL,771,NULL,772,NULL,773,NULL,774,NULL,775,NULL,776,NULL,777,NULL,778,NULL,779,NULL,780,NULL,781,NULL,782,NULL,783,NULL,784,NULL,785,NULL,786,NULL,787,NULL,788,NULL,789,NULL,790,NULL,791,NULL,792,NULL,793,NULL,794,NULL,795,NULL,796,NULL,797,NULL,798,NULL,799,NULL,800,NULL,801,NULL,802,NULL,803,NULL,804,NULL,805,NULL,806,NULL,807,NULL,808,NULL,809,NULL,810,NULL,811,NULL,812,NULL,813,NULL,814,NULL,815,NULL,816,NULL,817,NULL,818,NULL,819,NULL,820,NULL,821,NULL,822,NULL,823,NULL,824,NULL,825,NULL,826,NULL,827,NULL,828,NULL,829,NULL,830,NULL,831,NULL,832,NULL,833,NULL,834,NULL,835,NULL,836,NULL,837,NULL,838,NULL,839,NULL,840,NULL,841,NULL,842,NULL,843,NULL,844,NULL,845,NULL,846,NULL,847,NULL,848,NULL,849,NULL,850,NULL,851,NULL,852,NULL,853,NULL,854,NULL,855,NULL,856,NULL,857,NULL,858,NULL,859,NULL,860,NULL,861,NULL,862,NULL,863,NULL,864,NULL,865,NULL,866,NULL,867,NULL,868,NULL,869,NULL,870,NULL,871,NULL,872,NULL,873,NULL,874,NULL,875,NULL,876,NULL,877,NULL,878,NULL,879,NULL,880,NULL,881,NULL,882,NULL,883,NULL,884,NULL,885,NULL,886,NULL,887,NULL,888,NULL,889,NULL,890,NULL,891,NULL,892,NULL,893,NULL,894,NULL,895,NULL,896,NULL,897,NULL,898,NULL,899,NULL,900,NULL,901,NULL,902,NULL,903,NULL,904,NULL,905,NULL,906,NULL,907,NULL,908,NULL,909,NULL,910,NULL,911,NULL,912,NULL,913,NULL,914,NULL,915,NULL,916,NULL,917,NULL,918,NULL,919,NULL,920,NULL,921,NULL,922,NULL,923,NULL,924,NULL,925,NULL,926,NULL,927,NULL,928,NULL,929,NULL,930,NULL,931,NULL,932,NULL,933,NULL,934,NULL,935,NULL,936,NULL,937,NULL,938,NULL,939,NULL,940,NULL,941,NULL,942,NULL,943,NULL,944,NULL,945,NULL,946,NULL,947,NULL,948,NULL,949,NULL,950,NULL,951,NULL,952,NULL,953,NULL,954,NULL,955,NULL,956,NULL,957,NULL,958,NULL,959,NULL,960,NULL,961,NULL,962,NULL,963,NULL,964,NULL,965,NULL,966,NULL,967,NULL,968,NULL,969,NULL,970,NULL,971,NULL,972,NULL,973,NULL,974,NULL,975,NULL,976,NULL,977,NULL,978,NULL,979,NULL,980,NULL,981,NULL,982,NULL,983,NULL,984,NULL,985,NULL,986,NULL,987,NULL,988,NULL,989,NULL,990,NULL,991,NULL,992,NULL,993,NULL,994,NULL,995,NULL,996,NULL,997,NULL,998,NULL,999,NULL,1000";

	TreeNode* pRoot = solution.deserialize(serialzeStrData);

	cout << "2:*********" << solution.serializeRecursive(pRoot) << endl;

	system("pause");
	return 0;
}