#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/init.h>

static struct pci_device_id pciidlist[]= {
	{PCI_DEVICE(PCI_VENDOR_ID_NAME, PCI_DEVICE_ID_NAME_IDNUM),},
	{0,}
};

MODULE_DEVICE_TABLE(pci, ids);

static	unsigned char skel_get_revision(struct pci_dev *dev){
	u8 revision;
	
	pci_read_config_byte(dev, PCI_REVISION_ID, &revision);
	return revision;
}

static int probe(struct pci_dev *dev, const struct pci_device_id *id){
	/* Probing stuff here*/
	pci_enable_device(dev);
	
	if (skel_get_revision(dev)== 0x42)
		return -ENODEV;
		
	return 0;
}

static void remove(struct pci_dev *dev){
	/* clean up any allocated resources
	 * like call release_region()
	*/
}

static struct pci_driver pci_driver={
	.name = "pci.skel",
	id_table = ids,
	.probe = probe,
	.remove = remove,
};

static int __init pci_skel_init(void){
	return pci_register_driver(&pci_driver)
}

static void __exit pci_skel_exit(void){
	pci_unregister_driver(&pci_driver);
}

MODULE_LICENSE("GPL");
module_init(pci_skel_init);
module_exit(pci_skel_exit);
















