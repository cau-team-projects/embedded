#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xce929fa7, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x556b29aa, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0xc1162379, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x84bc974b, __VMLINUX_SYMBOL_STR(__arch_copy_from_user) },
	{ 0x8ff679d3, __VMLINUX_SYMBOL_STR(iom_fpga_itf_write) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


<<<<<<< HEAD
MODULE_INFO(srcversion, "23AFB84DBC7443D2F1FF6B7");
=======
MODULE_INFO(srcversion, "B7276705EFABEA0A5C7BB71");
>>>>>>> f273d94d19565f56d2e6f35f7b7b2c5be671a3fc
