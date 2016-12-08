CC       = g++ -fno-elide-constructors
LINKER   = g++ -o
rm       = del

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
INCDIR   = include

CFLAGS   = -W -Wall -I. -I$(INCDIR) 
LFLAGS   = -W -Wall -I. -I$(INCDIR) -lm

all: $(BINDIR)/carre $(BINDIR)/setint $(BINDIR)/sett

$(BINDIR)/carre: $(OBJDIR)/carre.o
	$(CC) $(LFLAGS) $^ -o $@

$(BINDIR)/setint: $(OBJDIR)/main.o $(OBJDIR)/setint.o
	$(CC) $(LFLAGS) $^ -o $@

$(BINDIR)/sett: $(OBJDIR)/main_template.o
	$(CC) $(LFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compile $< OK"

.PHONY: clean
clean:
	@$(rm) $(OBJDIR)\*
	@echo "cleaned $(OBJDIR)/"

.PHONY: distclean
distclean: clean
	@$(rm) $(BINDIR)\*
	@echo "cleaned $(BINDIR)/"
