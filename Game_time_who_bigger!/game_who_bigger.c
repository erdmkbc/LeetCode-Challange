#include <stdio.h>

/*
Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0 and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.

Example 1:

Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.

-Algorithm Description- 

1-) After the losing number has passed, a shifting process takes place, so we followed the following ways while making the assignments.
2-) If the losing number is 1. If the element is the first element, we have memorized and 2. 
3-) We assign the element, then replace the 3rd element by assigning the 4th element. 
4-) We performed the shifting operation until the end, that is, from the last to one element of our pointer.
5-) Finally, we assigned the first element that is, the losing element, which we kept in the memory, instead of the last element.
6-) If our pointer is 0 . If the element wins, this time 0 . We assigned the element to the memory 1. 
7-) We assigned the element and in the same way
8-) We performed this shifting operation until the last element of the pointer.
So how do we know that our number has won twice?
9-) We keep this with a win_counter variable, but it's a while that continues as long as a number continues to win by the entered value k.
10-) We created the loop. We kept our round count with the roundCounter variable.
Finally, the winning number for us in the final version of the pointer is 0 . Since it is an element, we printed the zeroth element of the pointer to the screen.

*/

void game_time_bigger(int* array , int sizeOfArray , int k)
{

int win_count = 0 , roundCounter = 0 , winner ;
int temp , temp_2 ;
int i , j ;

while(win_count <= k )
{
    if(*(array + 0 ) > *(array + 1 ) ) 
    {
        temp = *(array + 1 ) ;
        *(array + 1 ) = *(array + 2 ) ;
        for(i = 2 ; i < sizeOfArray - 1 ; i ++ )
        {
            *(array + i ) = *(array + i + 1 ) ;
        }
    *(array + sizeOfArray - 1 ) = temp ;
    roundCounter ++ ;
    for(i = 0 ; i < sizeOfArray ; i ++ )
    {
        printf(" %d " , *(array + i )) ;
    }
    printf("\n") ;
    }
    else 
    {
        temp_2 = *(array + 0 ) ;
        *(array + 0 ) = *(array + 1) ;
        for(i = 1 ; i < sizeOfArray - 1 ; i ++ )
        {
            *(array + i ) = *(array + i + 1 ) ;
        }
    *(array + sizeOfArray - 1 ) = temp_2 ;
    roundCounter ++ ;
    for(i = 0 ; i < sizeOfArray ; i ++ )
    {
        printf(" %d " , *(array + i ) ) ;
    }
    printf("\n") ;
    }
win_count ++ ;
}

winner = *(array + 0 ) ;

printf("\n") ;

if(win_count == k + 1 )
{
    printf("Winner index = %d " , winner ) ;
}

}

int main()
{

int Array[ 20 ] , sizeOfArray , k ;
int i ; 

printf("Enter the size of array : " ) ;
scanf("%d" , &sizeOfArray ) ;

for(i = 0 ; i < sizeOfArray ; i ++ ) 
{
    printf("%d - element : " , i ) ;
    scanf("%d" , &Array[ i ] ) ;
}

printf("Enter round number : " ) ;
scanf("%d" , &k ) ;

printf("\n*Array*\n") ;

for(i = 0 ; i < sizeOfArray ; i ++ ) 
{
    printf(" %d " , Array[ i ] ) ;
}

printf("\n") ;

printf("\n*Resul for winner*\n") ;

game_time_bigger(Array , sizeOfArray , k ) ;

return 0 ;
}