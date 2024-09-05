#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"

int main(struct multiboot *mboot_ptr)
{
	// Initialise all the ISRs and segmentation
    init_descriptor_tables();

	monitor_clear();
	monitor_write("xvX Operating System, Kernel 0.3.5\n");

	asm volatile("int $0x3");
    asm volatile("int $0x4");

    asm volatile("sti");

    init_timer(50);

  	return 0;
} 