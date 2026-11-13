CC=cc
CFLAGS=-O3 -march=native
primes: primes.c
	$(CC) $(CFLAGS) -o primes primes.c
clean:
	rm -f primes
