//#include "common.hpp"
/*
* jd create at 2018-02-28
* to build & run on Linux, just run :
* make
*/
//#pragma once
#pragma warning(disable:4996)
#pragma warning(disable:4018)

#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>  // uint64_t
#include <assert.h>

#include <vector>
#include <sstream>
#include <map>
#include <algorithm>    // std::sort
#include <utility>

#include <stack>
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <thread>
//#include <mutex>

#if __linux__
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
//#include <htslib/faidx.h>
#include <strings.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#if 0
	#include "htslib/tbx.h"
	#include "htslib/sam.h"
	#include "htslib/vcf.h"
	#include "htslib/kseq.h"
	#include "htslib/bgzf.h"
	#include "htslib/hts.h"
	#include "htslib/regidx.h"
	#include "hfile_internal.h"
	#include <unordered_map>
#endif 

#include <iomanip>
#include <list>
#include <unistd.h>
#include <sys/time.h>
#include <numeric>
#include <float.h>



#endif

#include <gperftools/profiler.h>

using namespace std; 

#ifdef __linux__
#define __P__  return 0;   //__
#else
#define __P__  system("pause");return 0;   //__
#define popen(fp, fr) _popen((fp),(fr))
#define pclose(fp) _pclose(fp)
#endif

#define DEL_ARR_MEM(P) if(NULL != (P)){delete [] (P); (P) = NULL;}



class td_args
{
public:

    int i; 
    int *p;

    td_args() 
    {
        i = 0;
        p = NULL;
    };
    td_args(int i_)
    {
        i = i_;
        p = new int[i];
    }
    ~td_args()
    {
        
        DEL_ARR_MEM(p);
        i = 0;
    }

};


void td_exec_(td_args &td_arg_)
{  

	float sum = 0; 	
	for (int i = 0; i < td_arg_.i; i++)
	{
		auto &e = td_arg_.p[i];
		if (e != -1)
		{
			sum += e;
		}
	}
	td_arg_.i = (int)sum;

}



void td_exec_0(td_args &td_arg_)
{  

	float sum = 0; 	
	for (int i = 0; i < td_arg_.i; i++)
	{
		auto &e = td_arg_.p[i];
		if (e != -1)
		{
			sum += e;
		}
	}
	td_arg_.i = (int)sum;

}

void td_exec_1(td_args &td_arg_)
{  

	float sum = 0; 	
	for (int i = 0; i < td_arg_.i; i++)
	{
		auto &e = td_arg_.p[i];
		if (e != -1)
		{
			sum += e;
		}
	}
	td_arg_.i = (int)sum;

}

//main_
int main(int argc, char **argv)
{
	char program[1024]={0};

	snprintf(program,1023,"%s_%d.prof",argv[0], getpid());




#if 1

	auto id_td_args_0 = td_args(1e8); 
	auto id_td_args_1 = td_args(1e8);

	id_td_args_0.p[0] = 9; 
	id_td_args_1.p[0] = 9; 

	ProfilerStart(program); // ProfilerStop()

	auto tid_0 = thread(td_exec_0, std::ref(id_td_args_0));
	auto tid_1 = thread(td_exec_1, std::ref(id_td_args_1));

	tid_0.join(); 
	tid_1.join();


	ProfilerStop(); 
	cout << id_td_args_0.i << endl; 
	cout << id_td_args_1.i << endl; 

	cout << "- end" << endl; 
#endif 


	__P__;
}


