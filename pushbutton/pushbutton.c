#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <asm/ioctl.h>

#define DRIVER_AUTHOR "CAUEEE Lee JaeHyeon"
#define DRIVER_DESC "driver for pushbutton"

#define PUSHBUTTON_NAME "pushbutton"
#define PUSHBUTTON_MODULE_VERSION "pushbutton V1.0"
#define PUSHBUTTON_ADDR 0x050

#define PUSHBUTTON_MAGIC 0x44

extern ssize_t iom_fpga_itf_read(unsigned int addr);
extern ssize_t iom_fpga_itf_write(unsigned int addr, unsigned short int value);

static int pushbutton_in_use = 0;

int pushbutton_open(struct inode *pinode, struct file *pfile) {
	if (pushbutton_in_use != 0) {
		return -EBUSY;
	}

	pushbutton_in_use = 1;
	return 0;
}

int pushbutton_release(struct inode *pinode, struct file *pfile) {
	pushbutton_in_use = 0;

	return 0;
}

int pushbutton_read(struct inode *pinode, char *gdata, size_t len, loff_t *off_what) {
	unsigned int status = 0;
	unsigned short bytevalues[9];
	int i;
	char *tmp = NULL;

	tmp = gdata;

	for( i=0; i<9; i++) {
		bytevalues[i] = iom_fpga_itf_read((unsigned int)PUSHBUTTON_ADDR + 2 * i);
		status |= (bytevalues[i] % 2) << i;
	}

	if(copy_to_user(tmp, &status, 4)) {
		return -EFAULT;
	}
	printk(KERN_INFO "status = %d\n", status);
	return 0;
}

static struct file_operations pushbutton_fops = {
	.owner = THIS_MODULE,
	.open = pushbutton_open,
	.release = pushbutton_release,
	.read = pushbutton_read,
};

static struct miscdevice pushbutton_driver = {
	.fops = &pushbutton_fops,
	.name = PUSHBUTTON_NAME,
	.minor = MISC_DYNAMIC_MINOR,
};

int pushbutton_init(void) {
	misc_register(&pushbutton_driver);
	printk(KERN_INFO "driver : %s driver init\n", PUSHBUTTON_NAME);

	return 0;
}

void pushbutton_exit(void) {
	misc_deregister(&pushbutton_driver);
	printk(KERN_INFO "driver : %s driver exit\n", PUSHBUTTON_NAME);
}

module_init(pushbutton_init);
module_exit(pushbutton_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("Dual BSD/GPL");
