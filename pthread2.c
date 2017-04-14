#include<pthread.h>
#include<stdio.h>

void *add(void *a);
int main(){
	void *c;
	pthread_t tid;
	int a[]={1,2};
	pthread_create(&tid,NULL,&add,a);
	pthread_attr_setdetachstate(&tid,PTHREAD_CREATE_DETACHED);
	int d;
	d=pthread_join(tid,(void*)&c);
	if(d!=0)
	printf("signal detached");
	//int d = (int)c;
	printf("%d\n",c);
	return 0;
}
void *add(void *a)
{
int *b;
int sum;
b=(int*)a;
sum=b[0]+b[1];
return (void*) sum;
}
