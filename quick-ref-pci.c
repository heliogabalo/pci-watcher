#include <linux/pci.h>


/* Symbolic names for PCI registers, verdors and device id values. */
struct pci_dev;

/* This structure represents a device within the kernel.*/
struct pci_driver;

/* Represents a pci driver/ */
struct pci_device_id;

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


/* Read or write a PCI configuration register. */
int pci_read_config_byte(struct pci_dev *dev, int where, u8 *val);
int pci_read_config_word(struct pci_dev *dev, int where, u16 *val);
int pci_read_config_dword(struct pci_dev *dev, int where, u32 *val);
int pci_write_config_byte(struct pci_dev *dev, int where, u8 *val);
int pci_write_config_word(struct pci_dev *dev, int where, u16 *val);
int pci_write_config_dword(struct pci_dev *dev, int where, u32 *val);

/* Enable PCI */
int pci_enable_ddevice(struct pci_dev *dev);

/* Handle PCI device resources */
unsigned int long pci_resource_start(struct pci_dev *dev, int bar);
unsigned int long pci_resource_end(struct pci_dev *dev, int bar);
unsigned int long pci_resource_flags(struct pci_dev *dev, int bar);






