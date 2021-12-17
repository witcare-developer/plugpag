INCS = -I./include 
OUTDIR = ./output
OBJS = $(OUTDIR)/totem.o 
LIBS = -lPPPagSeguro -lBTSerial -ldl

all: $(OUTDIR)/totem

clean: 
	rm -r $(OBJS) $(OUTDIR)/totem $(OUTDIR)

$(OUTDIR)/totem: main
	gcc  -o $(OUTDIR)/totem $(OBJS) $(LIBS)
	
main:
	mkdir -p $(OUTDIR)
	gcc -D__linux__ $(INCS)  -g3 -Wall -c totem.c -o $(OUTDIR)/totem.o

