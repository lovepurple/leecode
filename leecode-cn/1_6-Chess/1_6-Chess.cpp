/*
	 ʹ��һ��byte ��ʾ�� ˧��λ�ã����ܶ�����
*/
#include <iostream>

using namespace std;

#define ALL_POSITION_FULL_MASK 0b11111111
#define LEFT_MASK 0b11110000
#define RIGHT_MASK 0b00001111
#define GRID_SIZE 3

#define LEFT_SET(byteValue,setLeftValue) byteValue = ((setLeftValue << 4) | (byteValue & RIGHT_MASK))
#define LEFT_GET(byteValue) ((byteValue & LEFT_MASK) >> 4)

#define RIGHT_SET(byteValue,setRightValue) byteValue = ((byteValue  & LEFT_MASK)| setRightValue)
#define RIGHT_GET(byteValue) (byteValue & RIGHT_MASK)



int main()
{
	unsigned char b = '0';


	//����λ�����һ���������� ��4λ��ʾ���潫��λ�ã���4λΪ����˧��λ��
	for (LEFT_SET(b, 1); LEFT_GET(b) <= GRID_SIZE * GRID_SIZE; LEFT_SET(b, LEFT_GET(b) + 1))
	{
		for (RIGHT_SET(b, 1); RIGHT_GET(b) <= GRID_SIZE * GRID_SIZE; RIGHT_SET(b, RIGHT_GET(b) + 1))
		{
			if (LEFT_GET(b) % GRID_SIZE != RIGHT_GET(b) % GRID_SIZE)
			{
				std::cout << "A:" << LEFT_GET(b) << " B:" << RIGHT_GET(b) << endl;
			}
		}
	}

	return 0;
}

