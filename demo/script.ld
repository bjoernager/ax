OUTPUT_ARCH(arm)

MEMORY {
	bios  : ORIGIN = 0x0000000,LENGTH = 0x10K
	ewram : ORIGIN = 0x2000000,LENGTH = 0x100K
	iwram : ORIGIN = 0x3000000,LENGTH = 0x20K
	io    : ORIGIN = 0x4000000,LENGTH = 0x3FF
	pal   : ORIGIN = 0x5000000,LENGTH = 0x1K
	vram  : ORIGIN = 0x6000000,LENGTH = 0x60K
	oam   : ORIGIN = 0x7000000,LENGTH = 0x1K
	rom   : ORIGIN = 0x8000000,LENGTH = 0x20M
	sram  : ORIGIN = 0xE000000,LENGTH = 0x40K
}

SECTIONS {
	.bss    : {*(.bss*)}    > ewram
	.data   : {*(.data*)}   > ewram
	.text   : {*(.text*)}   > rom
	.rodata : {*(.rodata*)} > rom
}
