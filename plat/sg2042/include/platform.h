#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#define OPENSBI_ADDR	0x0
#define KERNEL_ADDR	0x2000000
#define RAMFS_ADDR	0x30000000
#define DEVICETREE_ADDR	0x20000000

#define BOOT_FROM_SD_FIRST	BIT(0)
#define MULTI_SOCKET_MODE	BIT(15)

#define SG2040_HART_COUNT	128
#define SG2040_HART_PER_CHIP	64
#define SG2042_MAX_CHIP_NUM	2
#define SG2042_CLUSTER_PER_CHIP	16

#define SG2042_MAX_PHY_ADDR_WIDTH	40
#define SG2040_CHIP_ADDR_SPACE		(1UL << 39)
#define SG2040_CHIP_ADDR_BASE(n)	((n) * SG2040_CHIP_ADDR_SPACE)
#define SG2040_CHIP_HARTID_BASE(n)	((n) * SG2040_HART_PER_CHIP)

#define SBI_SOPHGO_FEATURES	\
	 (SBI_PLATFORM_HAS_MFAULTS_DELEGATION | \
	 SBI_PLATFORM_HAS_TIMER_VALUE)

#define CSR_MCOR	0x7c2
#define CSR_MHCR	0x7c1
#define CSR_MCCR2	0x7c3
#define CSR_MHINT	0x7c5
#define CSR_MHINT2	0x7cc
#define CSR_MHINT4	0x7ce
#define CSR_MXSTATUS	0x7c0
#define CSR_PLIC_BASE	0xfc1
#define CSR_MRMR	0x7c6
#define CSR_MRVBR	0x7c7
#define CSR_MCOUNTERWEN	0x7c9
#define CSR_MCPUID	0xfc0
#define CSR_MSMPR	0x7f3

#define SBI_EXT_VENDOR_SG2040_SET_PMU		0x09000001
#define SBI_EXT_VENDOR_SG2040_BOOT_OTHER_CORE	0x09000003

#define SG2040_PLIC_BASE		0x7090000000UL
#define SG2040_MSIP_BASE		0x7094000000UL
#define SG2040_MTIMECMP_BASE		0x70ac000000UL

#define SG2040_PLIC_DELEG_OFFSET	0x001ffffc
#define SG2040_PLIC_DELEG_ENABLE	0x1

#define SG2040_UART0_ADDRBASE		0x7040000000
#define SG2040_UART0_FREQ		25000000
#define SG2040_CONSOLE_BDRATE		115200

#define MANGO_DEVICE_LOCK_REGISTER0	0x7030010140UL
#define MANGO_DEVICE_LOCK_REGISTER1	0x7030010144UL
#define MANGO_PA_BASE			0x0UL
#define MANGO_IO_BASE			0x7000000000UL
#define MANGO_HW_LOCK_BASE		MANGO_DEVICE_LOCK_REGISTER0
#define MANGO_CONSOLE_LOCK		MANGO_DEVICE_LOCK_REGISTER1

#define MANGO_CORES_PER_CLUSTER		4
#define MANGO_CLUSTER_ID(_vhartid)	((_vhartid) / MANGO_CORES_PER_CLUSTER)
#define MANGO_CORE_ID(_vhartid)		((_vhartid) % MANGO_CORES_PER_CLUSTER)

#define MANGO_MTIMECMP_SIZE_PER_CLUSTER	(64 * 1024)

#undef __SG_QEMU__

#endif
