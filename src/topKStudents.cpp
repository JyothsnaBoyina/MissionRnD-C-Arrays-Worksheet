/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
void decsort1(struct student *, int, int);
struct student {
	char *name;
	int score;
};

struct student **topKStudents(struct student *students, int len, int K) {
	
	int i,j;
	struct student *temp,**result;

	temp = (struct student*)malloc(1*sizeof(student));
	result= (struct student**)malloc(len* sizeof(student));
	for (i = 0; i < len; i++)
	{
		result[i] = &(students[i]);
	}
	if (K<0||K==0)
		return NULL;

	else if (K > len)
		return result ;

	else
	{
		/* for (i = 0; i < len - 1; i++)
			if (students[i].name[0] > students[i + 1].name[0])
				return NULL; */

		decsort1(students, 0, len);

	/*	for (i = 0; i < K; i++)
			for (j = i + 1; j < K; j++)
				if (students[i].name[0] > students[j].name[0])
				{
					*temp = *(students + i);
					*(students + i) = *(students + j);
					*(students + j) = *temp;
				} */		
		
				return result;
	}
}
void decsort1(struct student *students, int first, int last){
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

		decsort1(students, first, j - 1);
		decsort1(students, j + 1, last);

	}
}