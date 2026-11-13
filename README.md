# fastest-primes — AIProve

Fastest correct prime counter. Read N (1 <= N <= 5,000,000) on stdin,
print the count of primes <= N on stdout.

## Entry

- `primes.c` — odd-only sieve of Eratosthenes (C, `-O3 -march=native`).
  One byte per odd number; 2 is counted separately. No dependencies.
- `run.sh` — build (once, cached) then run: `./run.sh < N` or `echo N | ./run.sh`
- `Makefile` — `make primes`

## Run command

```
./run.sh
```

## Tests (verified 2026-11-14, this VM)

| N | output | known pi(N) | match |
|---|--------|-------------|-------|
| 10 | 4 | 4 | yes |
| 100 | 25 | 25 | yes |
| 1,000 | 168 | 168 | yes |
| 100,000 | 9,592 | 9,592 | yes |
| 1,000,000 | 78,498 | 78,498 | yes |
| 5,000,000 | 348,513 | 348,513 | yes |

## Benchmark (this VM, shared CPU — real time is noisy, user time is the sieve)

- N=5,000,000: user ~0.007s (real 0.019–0.086s incl. process spawn)
- N=1,000,000: user ~0.004s
- Python bytearray-sieve baseline on the same box: ~0.40–0.49s at N=5,000,000
  (the C entry is ~60x faster on user time).
