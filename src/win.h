
#ifndef _WIN_H
#define _WIN_H

#include <wchar.h>
#include <vterm.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xft/Xft.h>
#include <X11/extensions/sync.h>

#define ushort unsigned short
#define uint unsigned int
#define ulong unsigned long

#define MAX_COLORS 1024
#define MAX_ROWS 1000
#define MAX_COLS 500
#define SCROLLBACK_LINES 1000

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    VTermScreenCell *cells;
    int cols;
} ScrollbackLine;

extern ScrollbackLine scrollback[SCROLLBACK_LINES];
extern int sb_count;            // lines stored
extern int sb_offset;           // how far user has scrolled up (0 = live screen)

int sb_pushline(int cols, const VTermScreenCell *cells, void *user);
int sb_popline(int cols, VTermScreenCell *cells, void *user);

typedef struct {
    ushort red;
    ushort green;
    ushort blue;
    ushort alpha;
} Color;

typedef struct {
    int width;
    int height;
    int cols;
    int rows;
    int char_width;
    int char_height;
} Wnd;

extern Wnd window;

extern XftFont *xftFont;
extern XftDraw *draw;
extern Display *dpy;
extern Visual *visual;
extern Colormap colormap;
extern Window win;

#endif
