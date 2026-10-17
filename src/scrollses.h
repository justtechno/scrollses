/*
 * @file scrollses.h
 *
 * @brief A library for scrolling in ncurses.
**/

#ifndef SCROLLCORE
#define SCROLLCORE
#include <ncurses.h>

typedef struct {
	// properties for view
	int visible_start;
	int visible_end;

	// properties for array
	int arr_cap;
	int arr_count;
	char **arr;

	// other properties
	WINDOW *window;
} scroll_state;



/* @brief Initialize scroll_state structure
 *
 * @param scroll Pointer to structure to initialize
 * @param scroll_cap Capacity of scroll_state
**/
void scroll_init(scroll_state *scroll, WINDOW *win, int scroll_cap);

/*
 * @brief Edit index of array.
 *
 * @param scroll Pointer to scroll where edit.
 * @param index Index to edit.
 * @param newwal New value.
**/
void scroll_edit(scroll_state *scroll, int index, char *newwal);

/*
 * @brief Append element to scroll_state.
 *
 * @param scroll Pointer to structure where append.
 * @param new_str String you want to append.
 *
 * @return Complete status(0 if succes, else - -1).
**/
int scroll_append(scroll_state *scroll, char *new_str);


/*
 * @brief Write all visible zone to screen
 *
 * @param scroll A scroll structure to output
**/
void scroll_print(scroll_state scroll);


/*
 * @brief Scroll up visible zone.
 *
 * @param scroll Pointer to scrollbar to scroll.
**/
void scroll_up(scroll_state *scroll);


/*
 * @brief Scroll down visible zone.
 *
 * @param scroll Pointer to scrollbar to scroll.
**/
void scroll_down(scroll_state *scroll);


/*
 * @brief Delete last element from scroll_state.
 *
 * @param scroll Pointer to structure where pop.
**/
void scroll_pop_last(scroll_state *scroll);


/*
 * @brief Delete element from scroll_state by index.
 *
 * @param scroll Pointer to structure where pop.
 * @param index Index of element to pop.
**/
void scroll_pop_target(scroll_state *scroll, int index);


/* @brief Terminate scroll structure
 *
 * @param scroll Pointer to scroll to terminate
**/
void scroll_clear(scroll_state *scroll);

#endif
