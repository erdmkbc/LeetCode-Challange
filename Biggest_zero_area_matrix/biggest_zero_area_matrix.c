#include <stdio.h>

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example:
Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
/* Algorithm description
1-) We defined 4 loop variables, two of them so that we can navigate each element on the array and the other two are the ones created by each array element
To give us control over 2x2 matrices.
2-) With ones_counter, we can count 1s in 2x2 small matrices.
3-) largest_place gives us a back up.
for example
Let ones_counter be 1 in the first loop
We set largest_place as our starting value of 0.
Since ones_counter returns a value greater than 0, the new ones_counter will arrive thanks to the assignment of largest_place = ones_counter in the if
largest_place will return 1 until its value is greater than the incoming old value, and thus when the largest value starts returning the largest value
we will find.
*/
void biggest_zero_area_matrix(int array[ 20 ][ 20 ] , int row , int col )
{
int i , j , m , n ;
int ones_counter ;
int largest_place = 0 ;

for(i = 0 ; i < row ; i ++ )
{
   for(j = 0 ; j < col ; j ++ ) 
   {
       ones_counter = 0 ; 
       for(m = 0 ; m < 2 ; m ++ )
       {
           for(n = 0 ; n < 2 ; n ++ )
           {
               if(array[i + m ][j + n ] == 1) 
               {
               ones_counter ++ ;
               }
               if(ones_counter > largest_place )
               {
                   largest_place = ones_counter ;
               } 
               
            }
       } 
   }
}
printf("\n") ;
printf("Maximum square : %d " , largest_place ) ;
}

int main()
{

int array[ 20 ][ 20 ] ;
int i , j ;
int row , col ;

printf("Enter the row number : " ) ;
scanf("%d" , &row ) ;

printf("Enter the col number : " ) ;
scanf("%d" , &col ) ;

for(i = 0 ; i < row ; i ++ ) 
{
    for(j = 0 ; j < col ; j ++ )
    {
        printf("%d - row , %d - col : " , i , j ) ;
        scanf("%d" , &array[ i ][ j ] ) ;
    } 
printf("\n ") ;
}

printf("\n*Original array*\n") ;
printf("\n") ;

for(i = 0 ; i < row ; i ++ ) 
{
    for(j = 0 ; j < col ; j ++ )
    {
        printf(" %d " , array[ i ][ j ] ) ;
    } 
printf("\n ") ;
}

printf("\n") ;
biggest_zero_area_matrix(array , row , col ) ;

return 0 ;

}