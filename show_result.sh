### assump: you have build out gperftools under "gperftools-2.7/bin_out"
# download tar.gz from https://github.com/gperftools/gperftools/releases
# build it : (ROOT.tar.gz is an ubuntu version of gperltools2.7)

#   1. wget https://github.com/gperftools/gperftools/releases/download/gperftools-2.7/gperftools-2.7.tar.gz
#   2. tar xzf gperftools-2.7.tar.gz 
#   3. cd gperftools-2.7
#   4. mkdir ROOT
#   5. ./configure --prefix=`pwd`/ROOT
#   6. make install 
#   7. echo "set up : ROOT=pwd/ROOT, PATH += ROOT/bin, LD_LIBRARY_PATH += ROOT/lib, inc = ROOT/include"
    



rm -rf cpu_profiler_example_*.prof 

export ROOT=`pwd`/ROOT
if [ ! -d "$ROOT" ]; then
  tar xzf ROOT.tar.gz 2>/dev/null
fi

set -e 
export PATH=$ROOT/bin:$PATH
export LD_LIBRARY_PATH=$ROOT/lib

make -e -f Makefile
./cpu_profiler_example

pprof -text cpu_profiler_example cpu_profiler_example_*.prof
