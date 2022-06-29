#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x45cd1b70, "module_layout" },
	{ 0xdc820f8a, "usbnet_disconnect" },
	{ 0xfbb466b2, "usbnet_tx_timeout" },
	{ 0x368e9552, "usbnet_change_mtu" },
	{ 0x4d1979c4, "eth_validate_addr" },
	{ 0x3647328e, "usbnet_start_xmit" },
	{ 0x653e65b4, "usbnet_stop" },
	{ 0x565fe4b3, "usbnet_open" },
	{ 0x5fc674c5, "usb_deregister" },
	{ 0xef7a8e4d, "usb_register_driver" },
	{ 0x92c804b5, "skb_push" },
	{ 0x2e9e2dd8, "__dev_kfree_skb_any" },
	{ 0xd3f9056e, "skb_pull" },
	{ 0xef14f4c4, "usbnet_probe" },
	{ 0x91ed061f, "usbnet_suspend" },
	{ 0xfd864a39, "usbnet_resume" },
	{ 0xf0a97116, "usbnet_get_ethernet_addr" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0xb2722cc9, "_dev_err" },
	{ 0xdec09311, "usb_control_msg" },
	{ 0x28758140, "_dev_info" },
	{ 0x5ef42656, "usb_cdc_wdm_register" },
	{ 0x6e1b407e, "usbnet_get_endpoints" },
	{ 0xee9880ba, "usb_driver_claim_interface" },
	{ 0xa26a8f54, "usb_ifnum_to_if" },
	{ 0xfde1c3ec, "eth_commit_mac_addr_change" },
	{ 0xc3a65b89, "eth_prepare_mac_addr_change" },
	{ 0xa2597a9d, "usb_driver_release_interface" },
	{ 0x83296287, "usb_autopm_put_interface" },
	{ 0x4e653fc9, "usb_autopm_get_interface" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "cdc-wdm");

MODULE_ALIAS("usb:v1E0Ep9001d*dc*dsc*dp*ic*isc*ip*in05*");

MODULE_INFO(srcversion, "29480A58515EB2DB048A6C6");
