CONFIG_MODULE_SIG=n
obj-m := qmi_wwan_simcom.o
KDIR := /usr/src/linux-headers-$(shell uname -r)/ 
PWD := $(shell pwd)
OUTPUTDIR=/lib/modules/$(shell uname -r)/kernel/drivers/net/usb/
all: clean
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .cache.mk .tmp_versions Module.* modules.order


