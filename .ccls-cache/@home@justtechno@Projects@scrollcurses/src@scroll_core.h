#ifndef SCROLLCORE
#define SCROLLCORE

typedef struct {
	// properties for view
	int visible_start;
	int visible_end;

	// properties for array
	int arr_count;
	int arr_cap;
	char **arr;
} ScrollState;

#endif
