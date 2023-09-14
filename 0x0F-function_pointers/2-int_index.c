/**
 * int_index - searches for an integer
 * @array: an array of integers
 * @size: the number of elements in the array
 * @cmp: a pointer to the function to compare values
 *
 * Return: the index of the first element for which cmp returns non-zero,
 * or -1 if no element matches or if size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (array && size && cmp)
		while (i < size)
		{
			if (cmp(array[i]))
				return (i);
			i++;
		}
	return (-1);
}
