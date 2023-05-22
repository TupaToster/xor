CC=g++
OBJ_ARGS=
CC_SRCS=main.cpp flog.cpp funcs.cpp
OBJDIR=obj/
DEPDIR=dep/
CC_ARGS=

all: $(OBJDIR) $(DEPDIR) xor

$(OBJDIR)%.o: %.cpp
	$(CC) -M $(CC_ARGS) $< -o $(DEPDIR)$(<:.cpp=.d)
	echo "$(OBJDIR)" > line.tmp
	mv $(DEPDIR)$(<:.cpp=.d) input.tmp
	head -c -1 -q line.tmp input.tmp > $(DEPDIR)$(<:.cpp=.d)
	rm input.tmp line.tmp
	$(CC) -c $(CC_ARGS) $< -o $@

include $(wildcard $(DEPDIR)/*.d)

xor: $(addprefix $(OBJDIR), $(CC_SRCS:.cpp=.o))
	$(CC) $^ -o $@ $(OBJ_ARGS)

$(OBJDIR):
	mkdir $@

$(DEPDIR):
	mkdir $@

clean:
	rm -rf *.o *.d *.dot xor *.xor
	rm -rf $(DEPDIR) $(OBJDIR)
	clear

.PHONY: clean all grind