#GPerfTools=/home/wuzhu/tools/gperftools
# one need set up the PATH to have pprof
# and LD_LIBRARY_PATH to have libprofiler.so

#$GPerfTools=/home/bgi902/t/t/gperftools-2.7/bin_out
ROOT=NULL
CCFLAGS=-fno-omit-frame-pointer -g -pthread

ALL_BINS=cpu_profiler_example
all:$(ALL_BINS)

cpu_profiler_example :cpu_profiler_example.o
	g++ $(CCFLAGS) -o $@ $^ -L./ -L$(ROOT)/lib -Wl,-Bdynamic -ltcmalloc_and_profiler

.cpp.o:
	g++ $(CCFLAGS) -c -I./ -I$(ROOT)/include -fPIC -o $@ $<
clean:
	rm -f $(ALL_BINS) *.o cpu_profiler_example_*.prof
