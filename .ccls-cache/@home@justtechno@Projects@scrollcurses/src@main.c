#include <stdio.h>
#include "scrollutil.h"

int main() {
	int lines = get_win_lines();
	if (lines == -1) {
		printf("error");
		return 0;
	}
	printf("win_lines test: %d \n", lines);
	return 0;
}
