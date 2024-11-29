#include <linux/pci.h>


/* Symbolic names for PCI registers, verdors and device id values. */
struct pci_dev;

/* This structure represents a device within the kernel.*/
struct pci_driver;

/* Represents a pci driver/ */
struct pci_device_id;

/* Helper macros used to initialize a pci_device_id() structure.
Creates a pci_device_id structure that matches specific vendor
and device Ids
	 @ vendor - __u32, specific vendor ID that supports the driver.
	 @ device - __u32, specific device ID that supports the driver. */
PCI_DEVICE(vendor, device);

/* Creates a pci_device_id structure that matches specific PCI class 
	 @ device_class - __u32, Specific device class, that supports the driver.
	 @ device_class_mask - __u32, Specific device mask, that supports the driver. */
PCI_DEVICE_CLASS(device_class, device_class_mask);

/* Macro to export to user space the pci_device_id() device structure
	 to allow the hotplug and module loading.
		 @pci - driver or module.
		 @structListAlias - hardware device. Specific driver alias
		 definition(i.e: intel_*, amd_*). */
MODULE_DEVICE_TABLE(pci, structListAlias);

/* Register or unregister a PCI from the kernel*/
int pci_register_driver(struct pci_driver *drv);
int pci_module_init(struct pci_driver *drv);
int pci_unregister_driver(struct pci_driver *drv);

/* Search the device list of devices */
struct pci_dev *pci_find_device(unsigned int vendor, unsigned int device,
															 struct pci_dev *from);
															 
struct pci_dev *pci_find_device_reverse(unsigned int vendor,
													unsigned int device, const struct pci_dev *from);

struct pci_dev *pci_find_subsys(unsigned int vendor, unsigned int device,
						unsigned int ss_vendor, unsigned int ss_device,
						const struct pci_dev *from);
struct pci_dev *pci_find_class(unsigned int class, struct pci_dev *from);


/* Search the device list of devices with specific signature or class */
struct pci_dev pci_get_device(unsigned int vendor, unsigned int device,
															 struct pci_dev *from);

struct pci_dev *pci_get_subsys(unsigned int vendor, unsigned int device,
						unsigned int ss_vendor, unsigned int ss_device,
						struct pci_dev *from);

struct pci_dev pci_get_slot(struct pci_bus *bus, unsigned int devfn);


/* Read or write a PCI configuration register. 
	 OLD NAME of functions to read/write in user-space configuration:
	 		pci_VERB_config_byte()
	 The following function name's are defined as shown in kernel source: */
int pci_user_read_config_byte(struct pci_dev *dev, int where, u8 *val);
int pci_user_read_config_word(struct pci_dev *dev, int where, u16 *val);
int pci_user_read_config_dword(struct pci_dev *dev, int where, u32 *val);
int pci_user_write_config_byte(struct pci_dev *dev, int where, u8 *val);
int pci_user_write_config_word(struct pci_dev *dev, int where, u16 *val);
int pci_user_write_config_dword(struct pci_dev *dev, int where, u32 *val);

/* Enable PCI */
int pci_enable_ddevice(struct pci_dev *dev);

/* Handle PCI device resources */
unsigned int long pci_resource_start(struct pci_dev *dev, int bar);
unsigned int long pci_resource_end(struct pci_dev *dev, int bar);
unsigned int long pci_resource_flags(struct pci_dev *dev, int bar);






