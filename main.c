#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"

int main(struct multiboot *mboot_ptr)
{
	// Initialise all the ISRs and segmentation
    init_descriptor_tables();

	monitor_clear();

	initialise_paging();
	monitor_write("xvX Operating System, Kernel 0.3.8\n");

	// asm volatile("int $0x3");
 //    asm volatile("int $0x4");

 //    asm volatile("sti");

    // Page fault!
   	u32int *ptr = (u32int*)0xA0000000;
   	u32int do_page_fault = *ptr;

    //init_timer(50);

  	return 0;
} 