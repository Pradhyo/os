#### Receive input from one process, store it in a shared memory location and perform calculations on it from another process.

- Compile and run receiver.c first:
  1. gcc receiver.c -o a.out
  2. ./a.out

- Enter a line and press enter. (Segmentation fault occurs otherwise as there won’t be anything in the shared memory)

- Compile and run processor.c from another terminal window:
  1. gcc processor.c -o b.out
  2. ./b.out

- Once enough lines are entered in the first terminal window, open digits.out to check output.

---------------------------------------------------------------------