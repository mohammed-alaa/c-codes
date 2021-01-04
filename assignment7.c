#include <stdio.h>
#include <stdlib.h>

void Search_LinkedList(int target, Stack *ps)
{
	Stack *node = ps;
	while (node)
	{
		if (node->target == target)
		{
			printf("Found %d at address %p.\n", target, node);
			break;
		}
		node = node->next;
	}
}

void Delete_Node(int position, Stack *ps)
{
	Stack *prev_node = NULL, *node = ps;
	while (node)
	{
		if (node->target == target)
		{
			if (prev_node)
				prev_node->next = node->next;
			else
				ps = node->next;

			free(node);
			break;
		}
		prev_node = node;
		node = node->next;
	}
}