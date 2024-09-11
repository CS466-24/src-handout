
all: cpu mem thread

cpu: cpu.c common.h
	gcc cpu.c -lpthread -o cpu

mem: mem.c common.h
	gcc mem.c -lpthread -o mem

thread: threads.v0.c common.h
	gcc threads.v0.c -lpthread -o thread


tcpu: cpu
	./cpu A & 
	./cpu B & 
	nice -n 10 ./cpu C & 
	./cpu D &


tmem: mem
	setarch `uname -m` -R ./mem & 
	setarch `uname -m` -R ./mem 


tthread: thread
	@./thread 10
	@./thread 100
	@./thread 1000
	@./thread 10000
	@./thread 100000



.PHONY: clean
clean:
	/bin/rm cpu mem thread
