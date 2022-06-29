CC := $(CROSS-COMPILE)gcc

# Stolen from Linux build system
comma = ,
try-run = $(shell set -e; ($(1)) >/dev/null 2>&1 && echo "$(2)" || echo "$(3)")
cc-option = $(call try-run, $(CC) $(1) -c -xc /dev/null -o /dev/null,$(1),$(2))

CFLAGS ?= -s
WFLAGS := -Wall \
	$(call cc-option,-Wno-unused-function) \
CFLAGS += $(WFLAGS)
# WFLAGS := -Wall \
# 	$(call cc-option,-Wextra) \
# 	$(call cc-option,-Wwrite-strings) \
# 	$(call cc-option,-Wno-sign-compare) \
# 	$(call cc-option,-Wno-unused-function)

release: clean
	$(CC) $(CFLAGS) QmiWwanCM.c GobiNetCM.c main.c MPQMUX.c QMIThread.c util.c udhcpc.c -o simcom-cm -lpthread

clean:
	rm -rf simcom-cm *~

