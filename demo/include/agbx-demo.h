#if !defined(agbxd_hdr)
#define agbxd_hdr

#include <agbx/bs.h>

typedef struct {
	agbx_i8 x;
	agbx_i8 y;
} agbxd_pos;

typedef struct {
	agbx_i8   col;
	agbxd_pos pos;
	agbx_i8   prevcol;
	agbxd_pos prevpos;
	agbx_i20  vaddr;
} agbxd_dat;

typedef struct {
	bool done;
	bool err;
	bool drw;
	bool mv;
} agbxd_upd;

agbxd_upd agbxd_chkkeys(agbxd_dat * dat);
void      agbxd_chgcol( agbxd_dat * dat,agbx_i8 dir);
void      agbxd_drw(    agbxd_dat * dat);
void      agbxd_initdat(agbxd_dat * dat);
void      agbxd_initgfx(void);
bool      agbxd_loop(   agbxd_dat * dat);

#endif
