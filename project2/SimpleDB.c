#include <stdlib.h>
#include "defines.h"

List *entry_node = NULL;

uint8 SDB_GetUsedSize(void)
{
    List *nextNode = entry_node;
	int length = 0;
    while (nextNode)
    {
    	nextNode = nextNode->next;
        length++;
    }

    return length;
}

bool SDB_IsFull(void)
{
    return (SDB_GetUsedSize() == MAX_ENTRIES);
}

bool SDB_AddEntry(uint8 id, uint8 year, uint8 *subjects, uint8 *grades)
{
	if (SDB_IsFull())
		return false;

	List *node = (List *) malloc(sizeof(List));
	if (node == NULL)
		return false;

	Student student;
	student.id = id;
	student.year = year;

	int x;
	for (x = 0; x < COURSES_NUM; x++)
	{
		student.courses[x].id = subjects[x];
		student.courses[x].grade = clamp(grades[x], MIN_GRADE, MAX_GRADE);
	}

	node->student = student;
	node->next = entry_node;
	entry_node = node;
	return true;
}

void SDB_DeleteEntry(uint8 id)
{
	int length;
	if ((length = SDB_GetUsedSize()))
	{
		List *prev_node = NULL, *node = entry_node;
		int x;
		for (x = 0; x < length; x++)
		{
			if (node->student.id == id)
			{
				if (prev_node)
					prev_node->next = node->next;
				else
					entry_node = node->next;
				free(node);
				return;
			}
			prev_node = node;
			node = node->next;
		}
	}
}

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *subjects, uint8 *grades)
{
	int length;
	if ((length = SDB_GetUsedSize()))
	{
		List *node = entry_node;
		uint8 x, y;
		for (x = 0; x < length; x++)
		{
			if (node->student.id == id)
			{
				*year = node->student.year;
				for (y = 0; y < COURSES_NUM; y++)
				{
					subjects[y] = node->student.courses[y].id;
					grades[y] = node->student.courses[y].grade;
				}
				return true;
			}

			node = node->next;
		}
	}

	return false;
}

void SDB_GetIdList(uint8 *count, uint8 *list)
{
	*count = SDB_GetUsedSize();
	List *node = entry_node;
	int x;
	for (x = 0; x < SDB_GetUsedSize(); x++)
	{
		list[x] = node->student.id;
		node = node->next;
	}
}

bool SDB_IsIdExist(uint8 id)
{
	int length;
	if ((length = SDB_GetUsedSize()))
	{
		List *node = entry_node;
		int x;
		for (x = 0; x < SDB_GetUsedSize(); x++)
		{
			if (node->student.id == id)
				return true;
			node = node->next;
		}
	}

	return false;
}