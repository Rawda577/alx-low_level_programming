#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2D array of integers.
 * @width: Width of the grid.
 * @height: Height of the grid.
 *
 * Return: Pointer to the allocated 2D array, or NULL on failure.
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	/* Check if width or height is 0 or negative */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for rows */
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	/* Allocate memory for columns and initialize them to 0 */
	for (i = 0; i < height; i++)
	{
	grid[i] = malloc(sizeof(int) * width);
	if (grid[i] == NULL)
	{
	/* Free previously allocated memory before returning */
		while (--i >= 0)
			free(grid[i]);
		free(grid);
		return (NULL);
	}
	for (j = 0; j < width; j++)
		grid[i][j] = 0;
	}

	return (grid);
}

