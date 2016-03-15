#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g = 0;

void* foo(void* arg)
{
	int i;
	printf("Starting foo \n");
	for(i=0; i<1000000000;++i)
	{
		asm("lock incl %0" : "+m"(g) : : "memory");
	}
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1,NULL,foo, NULL))
	{
		fprintf(stderr, "Error creating t1\n");
		exit(1);
	}

	if (pthread_create(&t2,NULL,foo,NULL))
	{
		fprintf(stderr, "Error creating t2\n");
		exit(1);
	}

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("g = %d\n", g);

	return 0;
}
