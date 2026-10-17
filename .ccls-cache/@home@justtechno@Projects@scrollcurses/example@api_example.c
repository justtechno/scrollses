#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>
#include "../src/scrollses.h"
#include "../src/util.h"

int main() {
	// testing lines counting
	int lines = get_lines();
	if (lines == -1) {
		printf("error");
		return 0;
	}
	printf("win_lines test: %d \n", lines);
	
	// scroll structure test test
	printf("Appending and printing elements");
	scroll_state example;
	scroll_init(&example, 20);
	scroll_append(&example, "just");
	scroll_append(&example, "an");
	scroll_append(&example, "example");
	scroll_append(&example, "of");
	scroll_append(&example, "scrolling");
	scroll_append(&example, "via");
	scroll_append(&example, "scrollses");
	scroll_append(&example, "it");
	scroll_append(&example, "have");
	scroll_append(&example, "both");
	scroll_append(&example, "vertical");
	scroll_append(&example, "and");
	scroll_append(&example, "horizontal");
	scroll_append(&example, "scrolling");
	scroll_append(&example, "and");
	scroll_append(&example, "it");
	scroll_append(&example, "can");
	scroll_append(&example, "scroll");
	scroll_append(&example, "up");
	scroll_append(&example, "btw");
	printf("\narray state: \ncapacity: %d. \nfilled: %d. \n", example.arr_cap, example.arr_count);

	// the actual scrollbar
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	scroll_print(example);
	bool running = true;
	int ch;
	while (running) {
		ch = getch();
		switch (ch) {
			case KEY_UP:
				scroll_up(&example);
				break;

			case KEY_DOWN:
				scroll_down(&example);
				break;

			case KEY_F(1):
				scroll_append(&example, "random text");
				break;

			case 'j':
				scroll_down(&example);
				break;

			case 'k':
				scroll_down(&example);
				break;

			case KEY_BACKSPACE: running = false;
				break;
		}
	}
	endwin();

	return 0;
}
