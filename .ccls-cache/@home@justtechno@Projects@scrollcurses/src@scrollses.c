#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include "scrollses.h"

/* @brief Initialize scroll_state structure
 *
 * @param scroll Pointer to structure to initialize
 * @param scroll_cap Capacity of scroll_state
**/
void scroll_init(scroll_state *scroll, WINDOW *win, int scroll_cap) {
	scroll->arr_count=0;
	scroll->arr_cap=scroll_cap;
	scroll->arr=malloc((scroll->arr_cap+1) * sizeof(char *));
	scroll->window=win;
	scroll->visible_start=0;
	scroll->visible_end=getmaxy(scroll->window)-1;
}


/*
 * @brief Append element to scroll_state.
 *
 * @param scroll Pointer to structure where append.
 * @param new_str String you want to append.
 *	
 * @warning Dynamic features are still WIP and can end with segfault, be carefull, it also randomly appends a null, i have no idea why.
 *
 * @return Complete status(0 if succes, else - -1).
**/

int scroll_append(scroll_state *scroll, char *new_str) {
	// dynamic array extending
	if (scroll->arr_count >= scroll->arr_cap) {
		int new_cap = scroll->arr_cap + 2;
		char **tmp = realloc(scroll->arr, new_cap * sizeof(char *));
		if (tmp == NULL) {
			return -1;
		} else {
			scroll->arr = tmp;
			scroll->arr_cap = new_cap;
			for (int i = scroll->arr_count; i < scroll->arr_cap; i++) {
				scroll->arr[i] = NULL;
			}
		}
	}
	scroll->arr[scroll->arr_count] = strdup(new_str);
	scroll->arr_count++;
	scroll_print(*scroll);
	return 0;
}


/*
 * @brief Delete last element from scroll_state.
 *
 * @param scroll Pointer to structure where pop.
**/
void scroll_pop_last(scroll_state *scroll) {
	scroll->arr[scroll->arr_count-1] = NULL;
	scroll->arr_count--;
	scroll_print(*scroll);
}


/*
 * @brief Write all visible zone to screen
 *
 * @param scroll A scroll structure to output
**/
void scroll_print(scroll_state scroll) {
	clear();	
	for (int i = scroll.visible_start; i < scroll.visible_end; i++) {
		if (i < scroll.arr_count) {
			wprintw(scroll.window, "%s\n", scroll.arr[i]);
		} else {
		// breaking cycle of array index out of bounds
		break;
		}
	}
}

/*
 * @brief Scroll down visible zone.
 *
 * @param scroll Pointer to scrollbar to scroll.
**/
void scroll_down(scroll_state *scroll) {
	if (scroll->visible_end == scroll->arr_cap) { goto end; }
	scroll->visible_start++; scroll->visible_end++;
	scroll_print(*scroll);
end:
	;
}


/*
 * @brief Scroll up visible zone.
 *
 * @param scroll Pointer to scrollbar to scroll.
**/
void scroll_up(scroll_state *scroll) {
	if (scroll->visible_start == 0) { goto end; }
	scroll->visible_start--; scroll->visible_end--;
	scroll_print(*scroll);
end:
	;
}


/*
 * @brief Delete element from scroll_state by index.
 *
 * @param scroll Pointer to structure where pop.
 * @param index Index of element to pop.
**/
void scroll_pop_target(scroll_state *scroll, int index) {
	if (index < scroll->arr_count) {
		for (int i = index; i < scroll->arr_cap; i++) {
			if (i < scroll->arr_cap-1) {
				scroll->arr[i] = scroll->arr[i+1];
			}
		}
	scroll->arr_count--;
	scroll_print(*scroll);
	}
	end:
	;
}
