/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	int i = 0,temp,j,k,check;

	if (Arr== NULL||len<0)
		return -1;

	for (; i <len; i++)
	{
		temp = *(Arr + i);
		check = 0;
		for (j = i + 1; j <len;)
		{
			if (Arr[j] == temp)
			{
				check++;
				if (check <= 1)
				{
					for (k = j; k < len; k++)
						Arr[k] = Arr[k + 1];
					len = len - 1;
				}
				else
					return -1;
			}
			else
				j++;
		}
	}
	
	
	 return len;
}