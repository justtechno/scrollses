#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>
#include <scrollses.h>

int main() {
	// initializing ncurses
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);

	// initializing scroll_state structure and appending elements
	scroll_state example;
	scroll_init(&example, stdscr, 1);
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

	// writing scroll to the screen
	scroll_print(example);

	// starting loop
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

			case KEY_F(2):
				scroll_pop_last(&example);
				break;
	
			case KEY_F(3):
				scroll_pop_target(&example, 0);
				break;

			case KEY_F(4):
				scroll_pop_target(&example, 5);
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
	scroll_clear(&example);
	return 0;
}
