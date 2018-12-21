### many interesting explation ###
# when try g++, if put params in different order, it will affect the linker
# a pragmatic method of handling this is always put "-o mainapp main.o ..."
# in the first place after "-std=c++11"

ROOT=NULL

CC = g++ -std=c++11 
#CC = g++ -std=c++11 -Wno-format
c_flag = -g  -I$(ROOT)/include -fno-omit-frame-pointer -pthread -Wl,-Bdynamic -ltcmalloc_and_profiler -fPIC 
c_ld_flag = -g -L$(ROOT)/lib   -fno-omit-frame-pointer -pthread -Wl,-Bdynamic -ltcmalloc_and_profiler

c_files =  \
$(wildcard *.cpp) $(wildcard *.c)
h_files = \
$(wildcard *.hpp) $(wildcard *.h)
o_files_mess = \
$(patsubst %.cpp,%.o,${c_files}) $(patsubst %.c,%.o,${c_files})
o_files = \
$(filter %.o, $(o_files_mess))
elf_file=  \
mainapp.exe

rm_files = \
*.o *.dep *.elf  *.s *.exe *.exe_*.prof


all:$(elf_file)

$(elf_file):$(o_files)
	$(CC) -o $@ $(o_files) $(c_ld_flag) 
main.o: main.cpp
	$(CC) -o $@ -c $< $(c_flag) 

clean:
	rm -rf $(rm_files)

run:$(elf_file)
	./$(elf_file)



