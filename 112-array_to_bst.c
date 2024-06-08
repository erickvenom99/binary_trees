#include "binary_trees.h"
/**
* 
*
*/
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root ;
    root = NULL;
    size_t j = 0;
    if (size == 0)
        return (NULL);
    while(j < size)
    {
        if (j == 0)
        {
			bst_insert(&root, array[j]);
		}
		else
		{
			bst_insert(&root, array[j]);
		}
 
        j++;
    }

    return (root);
}