CC=clang
CCFLAGS=
AR=ar
ARFLAGS=

EXEC=bin/librxc.a
OBJECTS=\
	src/usage.o \

HEADERS=\
	src/ceneric_closure.h \
	src/just_observable_t.h \
	 
default: run

%.o: %.c
	$(CC) -c $< -o $@ $(CCFLAGS)

$(EXEC): $(OBJECTS) $(HEADERS)
	$(AR) -r $(EXEC) $(OBJECTS) $(ARFLAGS)

run: $(EXEC);

clean:
	-rm -rf $(EXEC) $(OBJECTS)