# include <stdio.h>

long sum(int n)
{
	if(1==n)
		return 1;
	else
		return sum(n-1)+n;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",sum(n));
	return 0;
}