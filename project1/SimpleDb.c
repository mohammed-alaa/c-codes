#include <stdio.h>
#include "defines.h"

Student db_entries[MAX_ENTRIES];
static uint8 length = 0;

uint8 SDB_GetUsedSize(void)
{
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

	Student entry;
	entry.id = id;
	entry.year = year;

	int x;
	for (x = 0; x < COURSES_NUM; x++)
	{
		entry.courses[x].id = subjects[x];
		entry.courses[x].grade = clamp(grades[x], MIN_GRADE, MAX_GRADE);
	}
	db_entries[length++] = entry;
	return true;
}

void SDB_DeleteEntry(uint8 id)
{
	if (SDB_GetUsedSize())
	{
		uint8 x, y;
		for (x = 0; x < SDB_GetUsedSize(); x++)
		{
			if (db_entries[x].id == id)
			{
				db_entries[x].id = 0;
				db_entries[x].year = 0;
				for (y = 0; y < COURSES_NUM; y++)
				{
					db_entries[x].courses[y].id = 0;
					db_entries[x].courses[y].grade = 0;
				}
			}
		}
	}
}

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *subjects, uint8 *grades)
{
	if (SDB_GetUsedSize())
	{
		uint8 x, y;
		for (x = 0; x <= SDB_GetUsedSize(); x++)
		{
			if (db_entries[x].id == id)
			{
				*year = db_entries[x].year;
				for (y = 0; y < COURSES_NUM; y++)
				{
					subjects[y] = db_entries[x].courses[y].id;
					grades[y] = db_entries[x].courses[y].grade;
				}
				return true;
			}
		}
	}

	return false;
}

void SDB_GetIdList(uint8 *count, uint8 *list)
{
	*count = SDB_GetUsedSize();
	int x;
	for (x = 0; x < SDB_GetUsedSize(); x++)
		list[x] = db_entries[x].id;
}

bool SDB_IsIdExist(uint8 id)
{
	if (SDB_GetUsedSize())
	{
		int x;
		for (x = 0; x < SDB_GetUsedSize(); x++)
		{
			if (db_entries[x].id == id)
				return true;
		}
	}

	return false;
}