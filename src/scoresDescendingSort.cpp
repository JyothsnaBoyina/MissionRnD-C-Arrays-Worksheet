/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void decsort(struct student *, int, int);
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	int i;
	if (students == NULL||len<0)
		return NULL;
	
	for (i = 0; i < len - 1; i++)
		if (students[i].name[0]>students[i + 1].name[0])
			return NULL;
	
	decsort(students, 0, len);
	return students;

	
}

void decsort(struct student *students, int first, int last){
	int pivot, j, i;
	struct student temp;
	if (first < last){
		pivot = first;
		i = first;
		j = last;

		while (i < j){
			while (students[i].score >= students[pivot].score && i < last)
				i++;
			while (students[j].score < students[pivot].score)
				j--;
			if (i < j){
				temp = *(students + i);
				*(students + i) = *(students + j);
				*(students + j) = temp;
			}
		}

		temp = students[pivot];
		students[pivot] = students[j];
		students[j] = temp;

		decsort(students, first, j - 1);
		decsort(students, j + 1, last);

	}
}