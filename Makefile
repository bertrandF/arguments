CC = g++
CFLAGS = -Wall
LDFLAGS =
EXEC = args_parse
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEPFLAGS = 

all: dep $(EXEC)
dep: Makefile.dep
Makefile.dep: $(SRC)
	@touch Makefile.dep
	$(CC) -MM $(DEPFLAGS) $(SRC) > $@
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper dep
clean:
	rm -f $(OBJ)
mrproper: clean
	rm -f *~ $(EXEC) Makefile.dep

ifneq ($(wildcard Makefile.dep),)
include Makefile.dep
endif
