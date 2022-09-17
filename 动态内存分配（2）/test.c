#include <stdio.h>


////calloc函数  - 在内存中开辟一个空间，并把元素改成0
//
//// void* calloc(size_t num,size_t size)   元素的个数 和 每个元素的长度（字节）
//
//#include <stdlib.h>
//#include <errno.h>
//// malloc算总大小的字节数，而calloc算有几个元素，每个元素是几个字节
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
//	//释放空间
//	//free函数是用来释放动态开辟的空间的
//	free(p);
//	p = NULL;
//	return 0;
//}

//    realloc函数   -   出现让动态内存空间管理更加灵活，调整动态内存空间的大小
//void* realloc(void* memblock,size_t size);  已经开辟好的空间的地址 和 新的需要的大小


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
	//就是在使用malloc开辟的20个字节空间
	//假设这里，20个自字节不能满足我们的使用了
	//希望我们能够有40个字节的空间
	//这里就可以使用realloc来调整动态开辟的内存
	//
	//realloc使用的注意事项：
	//1. 如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
	//2. 如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
	//  开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间
	//  最后返回新开辟的内存空间地址
	//3. 得用一个新的变量来接受realloc函数的返回值
	
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
	//释放内存
	free(p);
	p = NULL;
	return 0;
}


//// 常见的动态内存错误
//
//
//int main()
//{
//	//// 1.对空指针（NULL）进行解引用，不判断malloc函数是否返回正确
//	//int* p = (int*)malloc(40);
//	////万一malloc函数失败了，可能p就被赋值为 NULL
//	//// *p = 0;  //error,不能直接赋值
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;
//	//}                            //error,p未经判断，不能直接赋值
//	//free(p);
//	//p = NULL;
//	
//	//// 2.对动态开辟的内存的越界访问
//	//int* p = (int*)malloc(5 * sizeof(int));
//	//if (p == NULL)
//	//{
//	//	return 0;
//	//}
//	//else
//	//{
//	//	int i = 0;
//	//	for (i = 0; i < 10; i++)       //一共只有5个空间，这里却要访问10个空间
//	//	{
//	//		*(p + i) = i;      
//	//	}
//	//}
//
//	//// 3.对非动态开辟内存的释放 - free - 对堆里的才起作用这里的 a 是存在栈里面的，不是动态开辟的空间
//	//int a = 0;
//	//int* p = &a;
//	//*p = 20;
//	//free(p);
//	//p = NULL;
//
//	return 0;
//}