Receive input from one process, store it in a shared memory location
and perform calculations on it from another process.


processor.c
receiver.c

1. Compile and run receiver.c first:
	a. gcc receiver.c -o a.out
	b. ./a.out

2. Enter a line and press enter. (Segmentation fault occurs otherwise
as there won’t be anything in the shared memory)

3. Compile and run processor.c from another terminal window:
	a. gcc processor.c -o b.out
	b. ./b.out

4. Once enough lines are entered in the first terminal window, open
digits.out to check output.

---------------------------------------------------------------------