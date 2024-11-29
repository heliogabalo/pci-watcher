#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/init.h>

// struct pci_device_id amd_ids;
struct pci_device_id amd_ids[] = {};

MODULE_DEVICE_TABLE(pci, amd_ids);


