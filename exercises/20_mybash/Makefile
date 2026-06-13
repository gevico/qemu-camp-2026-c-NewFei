# =============================================
# 主 Makefile
# =============================================

PWD := $(shell pwd)
SUBDIRS := mysed myfile mywc mytrans

all: mybash

$(SUBDIRS):
	$(MAKE) -C src/$@ OBJDIR=$(PWD)/obj/$@ BINDIR=$(PWD)/bin

mybash: $(SUBDIRS)
	$(MAKE) -C src/mybash OBJDIR=$(PWD)/obj/mybash BINDIR=$(PWD)/bin LINKLIBS="-L$(PWD)/obj/mysed -L$(PWD)/obj/mywc -L$(PWD)/obj/mytrans -L$(PWD)/obj/myfile"
	cp $(PWD)/bin/mybash $(PWD)/20_mybash

clean:
	rm -rf obj bin 20_mybash

.PHONY: all $(SUBDIRS) mybash clean