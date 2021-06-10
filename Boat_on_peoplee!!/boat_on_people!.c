#include <stdio.h>

/*
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1,3], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

*/

void leetcode(int* array , int sizeOfArray , int limit ) 
{

int* boatsArray , boatsCounter = 0 , indexBoats = 0 ;
int i , j ;

for(i = 0 ; i < sizeOfArray ; i ++ )
{
    for(j = i + 1 ; j < sizeOfArray ; j ++ )
    {
        if(*(array + i ) == limit )
        {
           *(boatsArray + indexBoats ) = *(array + i ) ;
           boatsCounter ++ ;
        }
        else
        {
            if(*(array + i ) + *(array + j ) <= limit )
            {
                *(boatsArray + indexBoats) = *(array + i ) ;
                indexBoats ++ ;
                *(boatsArray + indexBoats ) = *(array + j ) ;
                indexBoats ++ ;
                boatsCounter ++ ;
            }
        }
    }
}


}

int main()
{

int array[ 20 ] , sizeOfArray , limit ;
int i ;

printf("Enter the number of people : ") ;
scanf("%d" , &sizeOfArray) ;

printf("Enter the limits of the boats : " ) ;
scanf("%d" , &limit ) ;

for(i = 0 ; i < sizeOfArray ; i ++ )
{
    printf("%d - weight : " , i ) ;
    scanf("%d" , &array[ i ] ) ;
}

printf("\n*People weight's*\n") ;

for(i = 0 ; i < sizeOfArray ; i ++ )
{
    printf(" %d " , array[ i ] ) ;
}

printf("\n") ;

printf("Save for boats number!") ;

leetcode(array , sizeOfArray , limit ) ;

return 0 ;
}