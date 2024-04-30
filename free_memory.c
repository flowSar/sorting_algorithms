#include "sort.h"
/**
 * free_memory - this for free alocated memory for bins_array
 *
 * @array: bins array.
 */
void free_memory(bins_t **array)
{
	bins_t *current, *prev;
	int i = 0;

	while (i < 10)
	{
		if (array[i] != NULL)
		{
			current = array[i];
			while (current->next)
			{
				prev = current->next;
				free(current);
				current = prev;
			}
			if (current)
				free(current);
		}
		i++;
	}
	free(array);
}
