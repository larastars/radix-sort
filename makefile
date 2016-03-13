FLAGS=-Wall -g

RadixSort:
	gcc -o RadixSort RadixSort.c link.c -DNDEBUG $(CFLAGS)
clean:
	rm -f RadixSort

