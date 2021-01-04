#ifndef SIMPLEDH
#define SIMPLEDH
#include "SimpleDb.c"

/*
*	@description	Check if the database is full
*	@params			input: void
*					output: void
*	@return			true if the the database is full, otherwise false
*/
bool SDB_IsFull(void);

/*
*	@description	Get the number of entries in the database
*	@params			input: void
*					output: void
*	@return			Number of entries
*/
uint8 SDB_GetUsedSize(void);

/*
*	@description	Add new entry to the database
*	@params			input:
*						- Student ID
*						- Student year
*						- Pointer to 3 subject IDs, with each subject is a uint8 value
*						- Pointer to 3 grades, with each grade is a uint8 value
*					output: void
*	@return			true if the new entry is successfully added, otherwise false
*/
bool SDB_AddEntry(uint8, uint8, uint8 *, uint8 *);


/*
*	@description	Delete the entry with the given ID
*	@params			input:
*						- ID of the entry to be deleted
*					output: void
*	@return			void
*/
void SDB_DeleteEntry(uint8);

/*
*	@description	Read an entry matching the provided ID
*	@params			input:
*						- Student ID
*					output: 
*						- Pointer to the student year
*						- Pointer to the subjects
*						- Pointer to the grades
*	@return			true if the entry exist, otherwise false
*/
bool SDB_ReadEntry(uint8, uint8 *, uint8 *, uint8 *);

/*
*	@description	Get the list of IDs of the students
*	@params			input: void
*					output: 
*						- Pointer to the number of entries currently exists in the database
*						- Pointer to the list of IDs
*	@return			void
*/
void SDB_GetIdList(uint8 *, uint8 *);

/*
*	@description	Checks if the the provided student ID exists
*	@params			input: 
*						- Student ID
*					output: void
*	@return			true if ID exists in the database, otherwise false
*/
bool SDB_IsIdExist(uint8);
#endif