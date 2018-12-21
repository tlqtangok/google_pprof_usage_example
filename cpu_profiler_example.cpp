#include <cstdio>
#include <pthread.h>
#include <gperftools/profiler.h>

#include <sys/types.h>
#include <unistd.h>

void *FastFunc(void *_arg)
{
	double sum = 0;
	for(int i = 0; i < 100000000; i++)
	{
		sum += 1;
	}
	return (NULL);
}

void *SlowFunc(void *_arg)
{
	double sum = 0;
	for(int i = 0; i < 100000000; i++)
	{
		sum *= 3;
		sum /= 3;
		sum += 1;
	}
	return (NULL);
}

void *AllFunc(void *_arg)
{
	FastFunc(NULL);
	SlowFunc(NULL);
	return (NULL);
}

int main(int argc, char *argv[])
{
	char program[1024]={0};

	snprintf(program,1023,"%s_%d.prof",argv[0], getpid());

	ProfilerStart(program);

	pthread_t tidFast = 0, tidSlow = 0, tidAll = 0;
	pthread_create(&tidFast, NULL, FastFunc, NULL);
	pthread_create(&tidSlow, NULL, SlowFunc, NULL);
	pthread_create(&tidAll, NULL, AllFunc, NULL);

	pthread_join(tidFast, NULL);
	pthread_join(tidSlow, NULL);
	pthread_join(tidAll, NULL);
	ProfilerStop(); 
	return (0);
}
