#include "stdio.h"				
#include "stdlib.h"				//提供malloc()和free()
#include "string.h"				//提供strcpy()等
#include "bsp_list.h"				

struct Node
{
	int a;				//数据域
	struct Node* next;	//指针域(指向节点的指针）
};

struct Node* List_head = NULL;
struct Node* List_end = NULL;


void AddListTill(int a)
{
	//创建一个节点
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));		//此处注意强制类型转换

	//节点数据进行赋值
	temp->a = a;
	temp->next = NULL;

	//连接分两种情况1.一个节点都没有2.已经有节点了，添加到尾巴上
	if (NULL == List_head)
	{

		List_head = temp;
		//	end=temp;
	}
	else
	{
		List_end->next = temp;
		//	end=temp;			//尾结点应该始终指向最后一个
	}
	List_end = temp;			//尾结点应该始终指向最后一个
}

void ScanList(void)
{
	struct Node* temp = List_head;		//定义一个临时变量来指向头
	while (temp != NULL)
	{
		printf("%d\n", temp->a);
		temp = temp->next;		//temp指向下一个的地址 即实现++操作
	}

}

struct Node* FindNode(int a)
{
	struct Node* temp = List_head;
	while (temp != NULL)
	{
		if (a == temp->a)
		{
			return temp;
		}
		temp = temp->next;
	}
	//没找到
	return NULL;
}

void FreeList(void)
{
	//一个一个NULL
	struct Node* temp = List_head;		//定义一个临时变量来指向头
	while (temp != NULL)
	{
		//	printf("%d\n",temp->a);
		struct Node* pt = temp;
		temp = temp->next;		//temp指向下一个的地址 即实现++操作
		free(pt);					//释放当前
	}
	//头尾清空	不然下次的头就接着0x10
	List_head = NULL;
	List_end = NULL;
}

void AddListRand(int index, int a)
{

	if (NULL == List_head)
	{
		printf("链表没有节点\n");
		return;
	}
	struct Node* pt = FindNode(index);
	if (NULL == pt)    //没有此节点
	{
		printf("没有指定节点\n");
		return;
	}
	//有此节点
	//创建临时节点，申请内存
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	//节点成员进行赋值
	temp->a = a;
	temp->next = NULL;
	//连接到链表上 1.找到的节点在尾部 2.找到的节点在中间 
	if (pt == List_end)
	{
		//尾巴的下一个指向新插入的节点
		List_end->next = temp;
		//新的尾巴
		List_end = temp;
	}
	else
	{
		// 先连后面 （先将要插入的节点指针指向原来找到节点的下一个）
		temp->next = pt->next;
		//后连前面
		pt->next = temp;
	}

}



void DeleteListTail(void)
{
	if (NULL == List_end)
	{
		printf("链表为空，无需删除\n");
		return;
	}
	//链表不为空 
	//链表有一个节点
	if (List_head == List_end)
	{
		free(List_head);
		List_head = NULL;
		List_end = NULL;
	}
	else
	{
		//找到尾巴前一个节点
		struct Node* temp = List_head;
		while (temp->next != List_end)
		{
			temp = temp->next;
		}
		//找到了，删尾巴
	   //释放尾巴
		free(List_end);
		//尾巴迁移
		List_end = temp;
		//尾巴指针为NULL
		List_end->next = NULL;
	}

}

void DeleteListHead(void)
{	//记住旧头
	struct Node* temp = List_head;
	//链表检测 
	if (NULL == List_head)
	{
		printf("链表为空\n");
		return;
	}

	List_head = List_head->next;//头的第二个节点变成新的头
	free(temp);

}

void DeleteListRand(int a)
{

	//链表判断 是不是没有东西
	if (NULL == List_head)
	{
		printf("链表没东西\n");
		return;
	}
	//链表有东西，找这个节点
	struct Node* temp = FindNode(a);
	if (NULL == temp)
	{
		printf("查无此点\n");
		return;
	}
	//找到了,且只有一个节点
	if (List_head == List_end)
	{
		free(List_head);
		List_head = NULL;
		List_end = NULL;
	}
	else if (List_head->next == List_end) //有两个节点
	{
		//看是删除头还是删除尾
		if (List_end == temp)
		{
			DeleteListTail();
		}
		else if (temp == List_head)
		{
			DeleteListHead();
		}
	}
	else//多个节点
	{
		//看是删除头还是删除尾
		if (List_end == temp)
			DeleteListTail();
		else if (temp == List_head)
			DeleteListHead();
		else	//删除中间某个节点
		{	//找要删除temp前一个，遍历
			struct Node* pt = List_head;
			while (pt->next != temp)
			{
				pt = pt->next;
			}
			//找到了
			//让前一个直接连接后一个 跳过指定的即可
			pt->next = temp->next;
			free(temp);

		}
	}


}
