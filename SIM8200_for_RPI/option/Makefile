ifneq ($(KERNELRELEASE),)
obj-m := option.o
else  
KDIR := /usr/src/linux-headers-$(shell uname -r)/ 
PWD := $(shell pwd)
all:
	make -C $(KDIR)-I ./usb_wwan M=$(PWD) modules
clean:
	rm *.o *.ko *.mod.c modules.order Module.symvers
.PHONY:clean
endif