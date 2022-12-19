#if !defined(axd_hdr)
#define axd_hdr

#include <ax/bs.h>

typedef struct {
	ax_i8 x;
	ax_i8 y;
} axd_pos;

typedef struct {
	ax_i8   col;
	axd_pos pos;
	ax_i8   prevcol;
	axd_pos prevpos;
	ax_i02  vaddr;
} axd_dat;

typedef struct {
	bool done;
	bool err;
	bool drw;
	bool mv;
} axd_upd;

axd_upd axd_chkkeys(  axd_dat * dat);
void    axd_chgcol(   axd_dat * dat,  ax_i8  dir);
void    axd_drw(      axd_dat * dat);
void    axd_initdat(  axd_dat * dat);
void    axd_initgfx(  void);
bool    axd_loop(     axd_dat * dat);
void    axd_setcolbdr(ax_i02    vaddr,ax_i01 col);

#endif
