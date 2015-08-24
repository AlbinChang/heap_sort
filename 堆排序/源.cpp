#include <iostream>
using namespace std;

//�������������ѣ�������ᵽ�ĶѶ�������
//������Ĺؼ��ǶѵĲ�����
//ά���ѵĲ������Ѷ�Ԫ�ط����仯ʱ�����ϵؽ���С��Ԫ�ء����½�����ʹ�öѶ���Զ�����Ԫ��
//���ѵĲ�������һ����������鲻�ϵ�ͨ����ά���ѵĲ���������һ���ѡ�

//ά���ѵĲ���
void max_heapfiy(int* a, int top_index, int heap_size)
{
	int left_index = top_index * 2 + 1;//���ӵ�λ��
	int right_index = top_index * 2 + 2;//�Һ��ӵ�λ��
	int largest_index = top_index;//��¼���Ԫ�ص�λ��
	if (left_index <= heap_size && a[left_index] > a[largest_index])
	{
		largest_index = left_index;
	}
	if (right_index <= heap_size && a[right_index] > a[largest_index])
	{
		largest_index = right_index;
	}
	if (largest_index != top_index)
	{
		int temp = a[top_index];
		a[top_index] = a[largest_index];
		a[largest_index] = temp;
		max_heapfiy(a, largest_index, heap_size);
	}
}

//���ѵĲ���
void build_heap(int* a, int heap_size)
{
	//����ֻ��Ҫ�����з�Ҷ�ӽ�㲻�ϵؽ��С�ά���ѵĲ�����
	int index = (heap_size - 1) / 2;//���һ����Ҷ�ӽ���λ��
	for (; index >= 0; index--)
		max_heapfiy(a, index, heap_size);
}

void heap_sort(int* a, int length)
{
	int heap_size = length - 1;
	//����
	build_heap(a, heap_size);
	//����
	for (int i = 0; i < length; i++)
	{
		//��ȡ�Ѷ�Ԫ�أ����뵽���򲿷�
		int temp = a[0];
		a[0] = a[length - i - 1];
		a[length - i - 1] = temp;
		//��ȡ��󣬽��С�ά���ѵĲ�����
		max_heapfiy(a, 0, --heap_size);
	}
}
int main()
{
	int a[] = {
		454, 56, 454, 98, 5, -79879, 2, 2, 5, 45, 5, 4, 64, 5, 4646456, -565, 6, 8, 4, 0, 2
	};
	int length = sizeof(a) / sizeof(int);
	cout << "δ��������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;

	heap_sort(a, length);

	cout << "���������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");

}