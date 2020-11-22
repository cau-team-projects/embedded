CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

obj-m := buzzer.o

KDIR := /home/$(shell whoami)/android_build/out/target/product/evk_8mq/obj/KERNEL_OBJ/

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -f *.ko *.o *.mod.* .*.cmd modules.order Module.symvers
