
all: assignment3

depend: assignment3-depend

clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.assignment3 $(@)

.PHONY: assignment3
assignment3:
	@$(MAKE) -f Makefile.assignment3 all

.PHONY: assignment3-depend
assignment3-depend:
	@$(MAKE) -f Makefile.assignment3 depend

project_name_list:
	@echo assignment3
