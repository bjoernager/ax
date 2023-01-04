OUTPUT_ARCH(arm)

MEMORY {
	bios  : ORIGIN = 0x0000000,LENGTH = 0x4000
	ewram : ORIGIN = 0x2000000,LENGTH = 0x40000
	iwram : ORIGIN = 0x3000000,LENGTH = 0x8000
	io    : ORIGIN = 0x4000000,LENGTH = 0x3FF
	pal   : ORIGIN = 0x5000000,LENGTH = 0x400
	vram  : ORIGIN = 0x6000000,LENGTH = 0x18000
	oam   : ORIGIN = 0x7000000,LENGTH = 0x400
	rom   : ORIGIN = 0x8000000,LENGTH = 0x2000000
	sram  : ORIGIN = 0xE000000,LENGTH = 0x10000
}

SECTIONS {
	.bss    : {*(.bss*)}    > ewram
	.data   : {*(.data*)}   > ewram
	.text   : {*(.text*)}   > rom
	.rodata : {*(.rodata*)} > rom
}
