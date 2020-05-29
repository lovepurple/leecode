#include <iostream>

using namespace std;

void mergeSort(int* arr, int arrayLength);


void merge(int* arr, int leftIndex, int rightIndex)
{
	int i = leftIndex;
	int j = rightIndex;

	int mid = leftIndex + (i + j) / 2;
	int tempIndex = 0;
	int* pTempArray = new int[j - i + 1];

	while (i <= mid && j <= rightIndex)
	{
		if (arr[i] < arr[j])
		{
			pTempArray[tempIndex++] = arr[i];
			i++;
		}
		else
		{
			pTempArray[tempIndex++] = arr[j];
			j++;
		}
	}

	while (i <= mid)
	{
		pTempArray[tempIndex++] = arr[i];
		i++;
	}

	while (j <= rightIndex)
	{
		pTempArray[tempIndex++] = arr[j];
		j++;
	}

	tempIndex = 0;
	for (int i = leftIndex; i <= rightIndex; ++i)
		arr[i] = pTempArray[tempIndex++];

	delete[] pTempArray;
}

void sort(int* arr, int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int mid = (leftIndex + rightIndex) / 2;
		sort(arr, leftIndex, mid);
		sort(arr, mid + 1, rightIndex);
		merge(arr, leftIndex, rightIndex);
	}
}



int main()
{
	int arr[] = { 25,1,5,8,6,33,4,7,9 };

	mergeSort(arr, 9);

	return 0;
}


void mergeSort(int* arr, int arrayLength)
{
	sort(arr, 0, arrayLength - 1);

}