# include <stdio.h>
# include <malloc.h>  //������malloc����
# include <stdlib.h> //������exit����

struct Arr
{
   int *pBase; //�洢��������ĵ�һ��Ԫ�صĵ�ַ
   int len; //�����������ɵ����Ԫ�صĸ���
   int cnt; //��ǰ������ЧԪ�صĸ���
   int increment; //�Զ���������
};

void init_arr(struct Arr *pArr,int length);  //�ֺŲ���ʡ
bool append_arr(struct Arr *pArr,int val); //׷��
bool insert_arr(struct Arr *pArr,int pos,int val);  //pos��ֵ��1��ʼ���Ѳ���ֵ����posǰ
int delete_arr(struct Arr *pArr,int pos,int *pVal);   //����ɾ����ֵ
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
	{	printf("ɾ���ɹ���\n");
		printf("��ɾ����Ԫ����%d \n",val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n");
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
		printf("8׷�ӳɹ�\n");
	}
	else
	{
		printf("8׷��ʧ��!\n");
	};  */
	printf("���ú�����飺\n");
	inversion_arr(&arr);
	show_arr(&arr);
	printf("�����Ҵ�С�������������飺\n");
	sort_arr(&arr);
	show_arr(&arr);
	return 0;
}

void init_arr(struct Arr *pArr,int length)  //ֻ�ܴ��ݵ�ַ���ܸı� ��������ı䲻��
{
	//(*pArr).len = 99;
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);  //��ֹ��������
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr * pArr) //�β���һ�������ĵ�ַ
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
	if(is_empty(pArr))     //Watch This!!! pArr�������һ���ṹ������ĵ�ַ
		printf("����Ϊ��!\n");
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
	//����ʱ׷��
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

bool insert_arr(struct Arr *pArr,int pos,int val)  //��pos��ֵ����ѡ��
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