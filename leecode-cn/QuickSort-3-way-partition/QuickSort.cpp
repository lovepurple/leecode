/*
	���������㷨���Ż��㷨  ������λ����
*/

#include <iostream>

void swap(int* arr, int indexA, int indexB)
{
	int temp = arr[indexA];
	arr[indexA] = arr[indexB];
	arr[indexB] = temp;
}

void quickSort(int* arr, int low, int high);

/// <summary>
/// �����ָ�
/// </summary>
/// <param name="arr"></param>
/// <param name="low"></param>
/// <param name="high"></param>
/// <returns></returns>
int partition(int* arr, int low, int high);

void PrintArr(int* arr, int arrLength)
{
	for (int i = 0; i < arrLength - 1; ++i)
		std::cout << arr[i] << ",";

	std::cout << std::endl;
}

int main()
{
	int arr[] = { 3,7,8,5,2,1,9,5,4 };
	int arrSize = sizeof(arr) / sizeof(int);

	std::cout << "Original:";
	PrintArr(arr, arrSize);

	quickSort(arr, 0, arrSize - 1);

	std::cout << "After Sort:";
	PrintArr(arr, arrSize);



	return 0;
}

void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int partitionIndex = partition(arr, low, high);
		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}

}

/// <summary>
/// �ָ���������ָ��ֻ��һ������ʱ��return   !!!!�����˳�����
/// </summary>
/// <param name="arr"></param>
/// <param name="low"></param>
/// <param name="high"></param>
/// <returns></returns>
int partition(int* arr, int low, int high)
{
	if (high - low + 1 == 1)
		return low;

	int middle = (low + high) / 2;

	//ȷ����С��
	if (arr[low] > arr[middle])
		swap(arr, low, middle);

	if (arr[low] > arr[high])
		swap(arr, low, high);

	//ȷ������
	if (arr[middle] > arr[high])
		swap(arr, middle, high);

	if (high - low + 1 <= 3)			//����������  ֱ����
		return high;

	//���м��Ų����С���Ա�   Min Middle  ..... Max
	swap(arr, low + 1, middle);

	int i = low + 2;
	int j = high;

	int pivot = arr[low + 1];

	while (i < j)
	{
		while (arr[j] > pivot && i < j)
			j--;

		while (arr[i] < pivot && i < j)
			i--;

		swap(arr, i, j);
		j--;
	}

	if (arr[i] < pivot && i < high)
	{
		swap(arr, low + 1, i);
		return i;
	}

	return j;

}

