.extern __agbx_init

@ AGB IMAGE HEADER
@ ... through the courtesy of <https://problemkaputt.de/gbatek-gba-cartridge-header.htm>.
@ Please read this thoroughly, as to make sure to cater it to your own program.

@ Image entry point (4)
@ 32-bit ARM instruction that serves as the entry point of the image, which usually is a branch instruction. Must be "b __agbx_init" if agbx is used.
.ARM
.global _start
_start: @ We define this label to stop the linker from complaining
	b __agbx_init

@ Nintendo logo (156)
@ Must be equal to the following memory sequence. The bootloader locks up if it determines that this is not the case.
.byte 0x24,0xFF,0xAE,0x51,0x69,0x9A,0xA2,0x21,0x3D,0x84,0x82,0x0A,0x84,0xE4,0x09,0xAD,0x11,0x24,0x8B,0x98,0xC0,0x81,0x7F,0x21,0xA3,0x52,0xBE,0x19,0x93,0x09,0xCE,0x20,0x10,0x46,0x4A,0x4A,0xF8,0x27,0x31,0xEC,0x58,0xC7,0xE8,0x33,0x82,0xE3,0xCE,0xBF,0x85,0xF4,0xDF,0x94,0xCE,0x4B,0x09,0xC1,0x94,0x56,0x8A,0xC0,0x13,0x72,0xA7,0xFC,0x9F,0x84,0x4D,0x73,0xA3,0xCA,0x9A,0x61,0x58,0x97,0xA3,0x27,0xFC,0x03,0x98,0x76,0x23,0x1D,0xC7,0x61,0x03,0x04,0xAE,0x56,0xBF,0x38,0x84,0x00,0x40,0xA7,0x0E,0xFD,0xFF,0x52,0xFE,0x03,0x6F,0x95,0x30,0xF1,0x97,0xFB,0xC0,0x85,0x60,0xD6,0x80,0x25,0xA9,0x63,0xBE,0x03,0x01,0x4E,0x38,0xE2,0xF9,0xA2,0x34,0xFF,0xBB,0x3E,0x03,0x44,0x78,0x00,0x90,0xCB,0x88,0x11,0x3A,0x94,0x65,0xC0,0x7C,0x63,0x87,0xF0,0x3C,0xAF,0xD6,0x25,0xE4,0x8B,0x38,0x0A,0xAC,0x72,0x21,0xD4,0xF8,0x07

@ Game title (12)
@ Twelve character ASCII-string (with uppercase letters) signalling the title of the program. If the string does not take up twelve characters, it is padded to that size with zero.
.ascii "AGBXDEMO\x0\x0\x0\x0"

@ Game code (4)
@ Four character ASCII-string. This is the code that is printed on the cartridge sticker (following the "AGB-"-part).
@ The format of this code is ABBC, wherein:
	@ "A" indicates the game type and is one of the following:
		@ "A": Normal game released early on (as late as 2003);
		@ "B": Normal game released later (after 2003);
		@ "C": Currently unused, but could be reserved for even newer games (if ever);
		@ "F": Part of the "Famicom Mini Series";
		@ "K": "Koro Koro Puzzle Happy Panechu!", which uses a tilt-sensor chip;
		@ "P": The e-Reader scanner, or a DS PassMe image (where the gamecode is, cleverly, "PASS");
		@ "R": "WarioWare: Twisted!", which uses rumble and a gryo sensor;
		@ "U": "Boktai: The Sun Is In Your Hand" and "Boktai 2: Solar Boy Django", both of which use a sunlight sensor;
		@ "V": "Drill Dozer", which uses a vibration rumble motor;
	@ "BB" is a unique two-letter combination;
	@ "C" indicates the region and is one of the following:
		@ "D": Germany
		@ "E": UK/USA
		@ "F": France
		@ "I": Italy
		@ "J": Japan
		@ "P": Elsewhere
		@ "S": Spain
.ascii "CXXE"

@ Maker code (2)
@ Two character ASCII string. Identifies the (commerical) developer.
.ascii "00"

@ Constant (1)
@ Always has the value of one hundred and fifty.
.byte 0x96

@ Main unit code (1)
@ Identifies the required hardware.
.byte 0x0

@ Device type (1)
@ Is zero unless special hardware is used (such as Nintendo's own hardware debugger).
.byte 0x0

@ Reserved area (7)
@ Is zero-filled.
.fill 0x1,0x7,0x0

@ Software version (1)
@ The version of the program.
.byte 0x0

@ Complement check (1)
@ Checksum of the header. Use agbsum to patch this in the final image.
.byte 0x0

@ Reserved area (2)
@ Is zero-filled.
.fill 0x1,0x2,0x0
