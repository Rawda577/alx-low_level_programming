#include <stdlib.h>

/**
 * free_grid - Frees a 2D array of integers.
 * @grid: Pointer to the 2D array.
 * @height: Height of the grid.
 */
void free_grid(int **grid, int height)
{
	int i;

	/* Check if grid or height is NULL or 0 */
	if (grid == NULL || height <= 0)
		return;

	/* Free each row */
	for (i = 0; i < height; i++)
		free(grid[i]);

	/* Free the array of pointers */
	free(grid);
}
