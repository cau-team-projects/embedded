#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/ioctl.h>

#define DRIVER_AUTHOR "CAUSW Byeonggon Lee"
#define DRIVER_DESC "driver for dotmatrix"
#define DOTM_NAME "dotmatrix"
#define DOTM_MODULE_VERSION "dotmatrix V1.0"
#define DOTM_ADDR 0x210

#define DOTM_MAGIC 0xBC
#define DOTM_SET_ALL _IOW(DOTM_MAGIC, 0, int)
#define DOTM_SET_CLEAR _IOW(DOTM_MAGIC, 1, int)

extern ssize_t iom_fpag_itf_read(unsigned int addr);
extern ssize_t iom_fpga_itf_write(unsigned int addr, unsigned short int value);

static int dotm_in_use = 0;

unsigned char dotm_fontmap_decimal[7][10] = {
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x04, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x10, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x1c, 0x08, 0x00, 0x00, 0x00, 0x00},
};

unsigned char dotm_fontmap_full[10] = {
	0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f
};

unsigned char dotm_fontmap_empty[10] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int dotm_open(struct inode *pinode, struct file *pfile)
{
	if (dotm_in_use != 0) {
		return -EBUSY;
	}
	dotm_in_use = 1;
	return 0;
}

int dotm_release(struct inode *pinode, struct file *pfile)
{
	dotm_in_use = 0;
	return 0;
}

ssize_t dotm_write(struct file *pinode, const char *gdata, size_t len, loff_t *off_what) {
	int ret, i;
	unsigned char num;
	unsigned short wordvalue;
	if (len > 1) {
		printk(KERN_WARNING "only 1 byte data will be processed\n");
		len = 1;
	}
	ret = copy_from_user(&num, gdata, 1);
	if (ret < 0 || num < 0 || num > 6) {
		return -EFAULT;
	}
	for (i = 0; i < 10; i++) {
		wordvalue = dotm_fontmap_decimal[num][i] & 0x7f;
		iom_fpga_itf_write((unsigned int) DOTM_ADDR + (i * 2), wordvalue);
	}
	return len;
}

static long dotm_ioctl(struct file *pinode, unsigned int cmd, unsigned long data) {
	int i;
	unsigned short wordvalue;
	switch (cmd) {
		case DOTM_SET_ALL:
			for (i = 0; i < 10; i++) {
				wordvalue = dotm_fontmap_full[i] & 0x7f;
				iom_fpga_itf_write((unsigned int) DOTM_ADDR + (i * 2), wordvalue);
			}
			break;
		case DOTM_SET_CLEAR:
			for (i = 0 ; i < 10; i++) {
				wordvalue = dotm_fontmap_empty[i] & 0x7f;
				iom_fpga_itf_write((unsigned int) DOTM_ADDR + (i * 2), wordvalue);
			}
			break;
	}
	return 0;
}

static struct file_operations dotm_fops = {
	.owner = THIS_MODULE,
	.open = dotm_open,
	.write = dotm_write,
	.unlocked_ioctl = dotm_ioctl,
	.release = dotm_release,
};

static struct miscdevice dotm_driver = {
	.fops = &dotm_fops,
	.name = DOTM_NAME,
	.minor = MISC_DYNAMIC_MINOR,
};

int dotm_init(void)
{
	misc_register(&dotm_driver);
	printk(KERN_INFO "driver: %s driver init\n", DOTM_NAME);
	return 0;
}

void dotm_exit(void)
{
	misc_deregister(&dotm_driver);
	printk(KERN_INFO "driver: %s driver exit\n", DOTM_NAME);
}

module_init(dotm_init);
module_exit(dotm_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("Dual BSD/GPL");
