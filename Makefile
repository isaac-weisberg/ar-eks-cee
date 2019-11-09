CC=clang
CCFLAGS=
AR=ar
ARFLAGS=

EXEC=bin/librxc.a
OBJECTS=\
	src/usage.o \
	 
default: run

%.o: %.c
	$(CC) -c $< -o $@ $(CCFLAGS)

$(EXEC): $(OBJECTS)
	$(AR) -r $(EXEC) $(OBJECTS) $(ARFLAGS)

run: $(EXEC);

clean:
	-rm -rf $(EXEC) $(OBJECTS)