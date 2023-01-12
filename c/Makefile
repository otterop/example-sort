include example/quicksort/deps.mk

CFLAGS?=-Werror -static -fPIC

GC_DEPENDENCIES=gc
GC_LIBRARIES=gc/.libs/libgc.a
GC_INCLUDES=-Igc/include

DEPENDENCIES=$(GC_DEPENDENCIES) $(EXAMPLE_QUICKSORT_DEPENDENCIES)
OBJS=$(EXAMPLE_QUICKSORT_QUICKSORT_OBJS)
LIBRARIES=$(GC_LIBRARIES) -lpthread -ldl $(EXAMPLE_QUICKSORT_LIBRARIES)
INCLUDES=-I. $(GC_INCLUDES) $(EXAMPLE_QUICKSORT_INCLUDES)
BIN=quicksort
LIBRARY=libquicksort.so

.PHONY: dependencies
dependencies:
	for DEP in $(DEPENDENCIES); do \
	$(MAKE) -C $${DEP}; \
	done;

.PHONY: clean_dependencies
clean_dependencies:
	for DEP in $(DEPENDENCIES); do \
	$(MAKE) -C $${DEP} clean; \
	done;

$(BIN): $(OBJS)
	make dependencies
	$(CC) -o $(BIN) $^ $(LDFLAGS) $(LIBRARIES)

$(LIBRARY): $(OBJS)
	make dependencies
	$(CC) -shared -o $(LIBRARY) $(INCLUDES) $^

%.o: %.c
	$(CC) -o $@ $(INCLUDES) $(CFLAGS) $< -c

clean: $(OBJS)
	rm -f $(BIN) $^

clean_all: clean_dependencies clean

.DEFAULT_GOAL := all
all: $(BIN)
