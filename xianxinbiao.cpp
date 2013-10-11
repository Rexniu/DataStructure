# include <stdio.h>
# include <malloc.h>  //包含了malloc函数
# include <stdlib.h> //包含了exit函数

struct Arr
{
   int *pBase; //存储的是数组的第一个元素的地址
   int len; //数组所能容纳的最大元素的个数
   int cnt; //当前数组有效元素的个数
   int increment; //自动增长因子
};

void init_arr(struct Arr *pArr,int length);  //分号不能省
bool append_arr(struct Arr *pArr,int val); //追加
bool insert_arr(struct Arr *pArr,int pos,int val);  //pos的值从1开始，把插入值放在pos前
int delete_arr(struct Arr *pArr,int pos,int *pVal);   //返回删除的值
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr *pArr);

int main(void)
{
	struct Arr arr;
	int val;

	init_arr(&arr,6);
	
	//printf("%d\n",arr.len);	
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	append_arr(&arr,6);
	show_arr(&arr);

/*	if(delete_arr(&arr,4,&val))
	{	printf("删除成功！\n");
		printf("您删除的元素是%d \n",val);
	}
	else
	{
		printf("删除失败！\n");
	}
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	insert_arr(&arr,6,99);
	append_arr(&arr,6);
	append_arr(&arr,7);
	if ( append_arr(&arr,8))
	{
		printf("8追加成功\n");
	}
	else
	{
		printf("8追加失败!\n");
	};  */
	printf("倒置后的数组：\n");
	inversion_arr(&arr);
	show_arr(&arr);
	printf("从左到右从小到大排序后的数组：\n");
	sort_arr(&arr);
	show_arr(&arr);
	return 0;
}

void init_arr(struct Arr *pArr,int length)  //只能传递地址才能改变 传递数组改变不了
{
	//(*pArr).len = 99;
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败！\n");
		exit(-1);  //终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr * pArr) //形参是一个变量的地址
{
	if(0==pArr->cnt)
		return true;
	else
		return  false;
}
bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr))     //Watch This!!! pArr本身就是一个结构体变量的地址
		printf("数组为空!\n");
	else
	{
		for(int i=0;i<pArr->cnt;++i)
			printf("%d ",pArr->pBase[i]); //Watch Here!!!
		printf("\n");
	}
}

bool append_arr(struct Arr *pArr,int val)
{
	if( is_full(pArr) )
		return false;
	//不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

bool insert_arr(struct Arr *pArr,int pos,int val)  //对pos的值进行选择
{
	int i;
	
	if(is_full(pArr))
		return false;

	if(pos<1 || pos>pArr->cnt+1)  //????????????
		return false;

	for (i=pArr->cnt-1;i>=pos-1;--i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	(pArr->cnt)++;
	return true;
}

int delete_arr(struct Arr *pArr,int pos,int *pVal)
{
	if( is_empty(pArr))
		return false;
	if( pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos-1];
	for(int i=pos;i<pArr->cnt;++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
  
}

void inversion_arr(struct Arr *pArr)
{
	int i = 0;
	int j = pArr->cnt-1;  //Watch here!!  Why "-1"
	int t;

	while (i<j)
	{
		t=pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] =t;
		i++;
		j--;
	}
}

void sort_arr(struct Arr * pArr)
{
	int i,j,t;
	for (i=0;i<pArr->cnt;++i)
	{
		for (j=i+1;j<pArr->cnt;++j)
		{
			if(pArr->pBase[i] > pArr->pBase[j])
			{
			 t=pArr->pBase[i];
			 pArr->pBase[i] = pArr->pBase[j];
			 pArr->pBase[j] =t;
			}
		}
	}
}