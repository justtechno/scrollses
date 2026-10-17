# Scrollses
Scrollses is a library implementing better scrolling with ncurses, it is simple but just enough average tools need as a scrolling(in my opinion).

## Installation

### From source
to install just run following commands:
```Shell
git clone https://github.com/justtechno/scrollses
sudo make install
```
to uninstall run following command:
```Shell
sudo make uninstall
```
and to reinstall run following command:
```Shell
sudo make reinstall
```

and to use it in project just add -lscrollses flag to gcc


## Using

### List of structures

Declaration:
```C
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
```
Purpose: A main scollbar structure
Properties:
- `int visible_start`(a index of first element to show)
- `int visible_end`(a index of last element to show)
- `int arr_cap`(capacity of array)
- `int arr_count`(count of elements in array)
- `char **arr`(an actual array with all elements)
- `WINDOW *window`(a window to display scrollbar)
Notes: usually there arent need to edit this properties directly - allmost all can be edited functions of library

### List of functions


Declaration: `void scroll_init(scroll_state *scroll, WINDOW *win, int scroll_cap)`
Purpose: Initialize `scroll_state` structure.
Arguments:
- `scroll_state *scroll` - a pointer to structure to initialize.
- `WINDOW *win` - a window to display scrollbar.
- `int scroll_cap` - an initial array capacity.


Declaration: `int scroll_append(scroll_state *scroll, char *new_str)`
Purpose: Appends element to `arr` property of `scroll_state` structure, dynaicaly extends array when needed.
Arguments:
- `scroll_state *scroll` - a poiner to structure to append.
- `char *new_str` - a string to append.


Declaration: `void scroll_print(scroll_state scroll)`
Purpose: Print scrollbar to the window.
Arguments:
- `scroll_state scroll` - a pointer to scroll_state structure to print.


Declaration: `void scroll_up(scroll_state *scroll)`
Purpose: Scroll scrollbar up.
Arguments:
- `scroll_state scroll` - a pointer to scrollbar to scroll.


Declaration: `void scroll_down(scroll_state *scroll)`
Purpose: Scroll scrollbar down.
Arguments:
- `scroll_state scroll` - a pointer to scrollbar to scroll.


Declaration: `void scroll_pop_last(scroll_state *scroll)`
Purpose: pop last element from scrollbar(set in to NULL).
Arguments:
- `scroll_state *scroll` - a pointer to scrollbar where pop element.



Declaration: `void scroll_pop_target(scroll_state *scroll, int index)`
Purpose: pop element from scrollbar(set in to NULL) by index and fix shifts.
Arguments:
- `scroll_state *scroll` - a pointer to scrollbar where pop element.
- `int index` - a index of element to pop.


Declaration: `void scroll_clear(scroll_state *scroll)`
Purpose: terminate scroll_state structure and free dynamic array in it.
Arguments:
- `scroll_state *scroll` - a pointer to scroll_state to terminate.
