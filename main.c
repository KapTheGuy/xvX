#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "multiboot.h"

char oem[] = "SPC";

int main(struct multiboot *mboot_ptr)
{
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    // Initialise the screen (by clearing it)
    monitor_clear();
    u32int a = kmalloc(8);
    initialise_paging();
    u32int b = kmalloc(8);
    u32int c = kmalloc(8);
    monitor_write("a: ");
    monitor_write_hex(a);
    monitor_write(", b: ");
    monitor_write_hex(b);
    monitor_write("\nc: ");
    monitor_write_hex(c);

    kfree(c);
    kfree(b);
    u32int d = kmalloc(12);
    monitor_write(", d: ");
    monitor_write_hex(d);

    monitor_write("\nxvX Operating System Kernel 0.5.7\nOEM: ");
    monitor_write(oem);
    monitor_write("\n");

    return 0;
}
