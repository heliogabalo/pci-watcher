## Chat-GPT Copilot
1. Understanding PCI Subsystem.
 - PCI Overview: Familiarize with `pci_register_driver`, `probe`, `remove` functions.
 - Device detection: Detect and enumerate PCI devices:
	It might hook into `struct pci_driver`, and use `pci_get_device` helpers.
	
2. Data collection and logging.
 - Identify events and data points you want to log;(IDs, resource's usage, IRQs).
 - Where to log this information; dmesg, custom log file, user-space tool.
	
3. Interfacing with User Space.
 - Plan how user-space tools/scripts will interact with the driver:
 		- Exposing data via `/proc` or `/sys`.
 		- Providing a custom character device interface.
4. Building and testing
 - [x] Kernel headers for the VM in place.
 - Test incrementally, focus on one feature before adding complexity.
 
 
 
Can you bookmark this session to refer it later? The session name is pci_watcher,
the same as the driver name.
