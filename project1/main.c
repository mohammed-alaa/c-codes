#include <stdio.h>
#include "SimpleDb.h"

int main()
{
	/* Add */
	uint8 subs1[] = { 1, 2, 3 },
		  subs2[] = { 4, 5, 6 },
		  subs3[] = { 7, 8, 9 };

	uint8 grades1[] = { 10, 50, 70 },
		  grades2[] = { 30, 40, 60 },
		  grades3[] = { 99, 100, 200 };

	SDB_AddEntry(5, 2000, subs1, grades1);
	SDB_AddEntry(15, 2005, subs2, grades2);
	SDB_AddEntry(25, 2010, subs3, grades3);


	/* Read */
	// uint8 year, subjects[COURSES_NUM], grades[COURSES_NUM];
	// if (SDB_ReadEntry(5, &year, subjects, grades))
	// {
	// 	printf("%d\n", year);
	// 	int x;
	// 	for (x = 0; x < COURSES_NUM; x++)
	// 	{
	// 		printf("%d ", grades[x]);
	// 		printf("%d\n", subjects[x]);
	// 	}
	// }

	/* Delete */
	// printf("Entry ID 5 exists: %d\n", SDB_ReadEntry(5, &year, subjects, grades));
	// SDB_DeleteEntry(5);
	// printf("Entry ID 5 exists: %d\n", SDB_ReadEntry(5, &year, subjects, grades));

	/* ID List */
	// uint8 entries_num, list[MAX_ENTRIES] = { 0 };
	// SDB_GetIdList(&entries_num, list);
	// printf("%d\n", entries_num);
	// int x;
	// for (x = 0; x < entries_num; x++)
	// 	printf("%d\n", list[x]);

	/* ID Exists */
	// printf("%d\n", SDB_IsIdExist(1));
	// printf("%d\n", SDB_IsIdExist(15));
	// printf("%d\n", SDB_IsIdExist(5));
}