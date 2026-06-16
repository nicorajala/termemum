#include "win.h"

/*

    Copyright (C) 2026 Nico Rajala.

    This is a basic scrollback implementation.

*/

int sb_pushline(int cols, const VTermScreenCell *cells, void *user) {
    (void)user;

    // shift buf if full
    if(sb_count == SCROLLBACK_LINES) {
        free(scrollback[0].cells);
        memmove(&scrollback[0], &scrollback[1],
                sizeof(ScrollbackLine) * (SCROLLBACK_LINES - 1));
        sb_count--;
    }

    scrollback[sb_count].cells = malloc(sizeof(VTermScreenCell) * cols);
    memcpy(scrollback[sb_count].cells, cells, sizeof(VTermScreenCell) * cols);
    scrollback[sb_count].cols = cols;
    sb_count++;
    return 1;
}

int sb_popline(int cols, VTermScreenCell *cells, void *user) {
    (void)user;

    if (sb_count == 0) return 0;
    sb_count--;
    memcpy(cells, scrollback[sb_count].cells, sizeof(VTermScreenCell) * cols);
    free(scrollback[sb_count].cells);
    scrollback[sb_count].cells = NULL;
    return 1;
}