# include <stdio.h>
# include <stdlib.h>
long f(long n)
{
	 if(1==n)
		return 1;
	  else
		return f(n-1)*n;

}

int main(void)
{
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n));
	return 0;
}