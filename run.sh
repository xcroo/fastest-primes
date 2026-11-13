#!/bin/sh
# Build once (cached), then run. Compile is NOT part of the timed run on repeats.
cd "$(dirname "$0")"
if [ ! -x ./primes ]; then
  cc -O3 -march=native -o primes primes.c
fi
exec ./primes
