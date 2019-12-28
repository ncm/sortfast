CC=g++
ARCH=native
CHECK=NOCHECK

ALL = \
  STD \
  RADIX256 \
  RADIX2 \
  BOG \
  ANDANDOR \
  INDEXED \
  INDEXED_PESSIMAL_ON_GCC \
  ROT \
  CMOV \
  INDEXED_ALT1 \
  INDEXED_ALT2 \
#

.PHONY: all ${ALL} NONE

all: ${ALL}

clean:; rm 1e8ints a.out

1e8ints:; dd if=/dev/urandom of=1e8ints bs=1000000 count=400

${ALL} NONE: 1e8ints
	@ CMD='${CC} -D${CHECK} -O3 -march=${ARCH} -D$@ sorts.cc && time ./a.out && echo ok'; \
    echo "$$CMD"; bash -c "$$CMD"

