#include <stdio.h>


////calloc����  - ���ڴ��п���һ���ռ䣬����Ԫ�ظĳ�0
//
//// void* calloc(size_t num,size_t size)   Ԫ�صĸ��� �� ÿ��Ԫ�صĳ��ȣ��ֽڣ�
//
//#include <stdlib.h>
//#include <errno.h>
//// malloc���ܴ�С���ֽ�������calloc���м���Ԫ�أ�ÿ��Ԫ���Ǽ����ֽ�
//int main()
//{
//	//malloc(10*sizeof(int));
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//�ͷſռ�
//	//free�����������ͷŶ�̬���ٵĿռ��
//	free(p);
//	p = NULL;
//	return 0;
//}

//    realloc����   -   �����ö�̬�ڴ�ռ���������������̬�ڴ�ռ�Ĵ�С
//void* realloc(void* memblock,size_t size);  �Ѿ����ٺõĿռ�ĵ�ַ �� �µ���Ҫ�Ĵ�С


#include <stdlib.h>
#include <errno.h>
int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	//������ʹ��malloc���ٵ�20���ֽڿռ�
	//�������20�����ֽڲ����������ǵ�ʹ����
	//ϣ�������ܹ���40���ֽڵĿռ�
	//����Ϳ���ʹ��realloc��������̬���ٵ��ڴ�
	//
	//reallocʹ�õ�ע�����
	//1. ���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
	//2. ���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
	//  ����һ����������Ŀռ䣬���Ұ�ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
	//  ��󷵻��¿��ٵ��ڴ�ռ��ַ
	//3. ����һ���µı���������realloc�����ķ���ֵ
	
	/*int* ptr = realloc(p, INT_MAX);*/
	int* ptr = realloc(p, 40);
	if (ptr != NULL)
	{
		p = ptr;
		int i = 0; 
		for (i = 5; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//�ͷ��ڴ�
	free(p);
	p = NULL;
	return 0;
}


//// �����Ķ�̬�ڴ����
//
//
//int main()
//{
//	//// 1.�Կ�ָ�루NULL�����н����ã����ж�malloc�����Ƿ񷵻���ȷ
//	//int* p = (int*)malloc(40);
//	////��һmalloc����ʧ���ˣ�����p�ͱ���ֵΪ NULL
//	//// *p = 0;  //error,����ֱ�Ӹ�ֵ
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;
//	//}                            //error,pδ���жϣ�����ֱ�Ӹ�ֵ
//	//free(p);
//	//p = NULL;
//	
//	//// 2.�Զ�̬���ٵ��ڴ��Խ�����
//	//int* p = (int*)malloc(5 * sizeof(int));
//	//if (p == NULL)
//	//{
//	//	return 0;
//	//}
//	//else
//	//{
//	//	int i = 0;
//	//	for (i = 0; i < 10; i++)       //һ��ֻ��5���ռ䣬����ȴҪ����10���ռ�
//	//	{
//	//		*(p + i) = i;      
//	//	}
//	//}
//
//	//// 3.�ԷǶ�̬�����ڴ���ͷ� - free - �Զ���Ĳ������������ a �Ǵ���ջ����ģ����Ƕ�̬���ٵĿռ�
//	//int a = 0;
//	//int* p = &a;
//	//*p = 20;
//	//free(p);
//	//p = NULL;
//
//	return 0;
//}