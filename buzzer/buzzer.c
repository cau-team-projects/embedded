#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <asm/ioctl.h>
#include <linux/delay.h>

#define DRIVER_AUTHOR "CAUEEE Lee JaeHyeon"
#define DRIVER_DESC "driver for buzzer"

#define BUZZER_NAME "buzzer"
#define BUZZER_MODULE_VERSION "buzzer V1.0"
#define BUZZER_ADDR 0x070

extern ssize_t iom_fpga_itf_read(unsigned int addr);
extern ssize_t iom_fpga_itf_write(unsigned int addr, unsigned short int value);

static int buzzer_in_use = 0;

int buzzer_open(struct inode *pinode, struct file *pfile) {
	if (buzzer_in_use != 0) {
		return -EBUSY;
	}

	buzzer_in_use = 1;
	return 0;
}

int buzzer_release(struct inode *pinode, struct file *pfile) {
	buzzer_in_use = 0;

	return 0;
}

ssize_t buzzer_write(struct file *pfile, const char *gdata, size_t len, loff_t *off_what) {
	const char *tmp = NULL;
	unsigned char value;
	
	tmp = gdata;

	if(copy_from_user(&value, tmp, 1)) {
		return -EFAULT;
	}

	iom_fpga_itf_write((unsigned int) BUZZER_ADDR, value);

	return len;
}

static struct file_operations buzzer_fops = {
	.owner = THIS_MODULE,
	.open = buzzer_open,
	.release = buzzer_release,
	.write = buzzer_write,
};

static struct miscdevice buzzer_driver = {
	.fops = &buzzer_fops,
	.name = BUZZER_NAME,
	.minor = MISC_DYNAMIC_MINOR,
};

int buzzer_init(void) {
	misc_register(&buzzer_driver);
	printk(KERN_INFO "driver : %s driver init\n", BUZZER_NAME);

	return 0;
}

void buzzer_exit(void) {
	misc_deregister(&buzzer_driver);
	printk(KERN_INFO "driver : %s driver exit\n", BUZZER_NAME);
}

module_init(buzzer_init);
module_exit(buzzer_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("Dual BSD/GPL");
