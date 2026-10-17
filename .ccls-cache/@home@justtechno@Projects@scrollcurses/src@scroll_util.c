#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>
#include "scroll_util.h"

int get_win_lines() {
	struct winsize w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
		return w.ws_row;
	} else {
		return -1;
	}
}




























