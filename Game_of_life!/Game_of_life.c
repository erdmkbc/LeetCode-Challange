#include <stdio.h>

/*
An algorithm excerpted from the article by British mathematician John Horton Conway
-Game Of Life-
Any living cell with less than two living neighbors dies because of underpopulation.
Any living cell with two or three living neighbors continues to the next generation.
Any living cell with more than three living neighbors dies due to overpopulation.
Any dead cell with exactly three living neighbors becomes a living cell through reproduction.
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
/*

*/

/* Algorithm description

1-) First, we created a memory array. The reason we didn't create this is after the previous changes we will make on the array.
In order not to affect the controls we will make, we made our controls over the original array and the changes over the memory array.
2-) To check the neighboring elements of an array element, for(i = -1 ; i <= 1 ; i ++ ){for(j = -1 ; j <= 1 ; j ++ )},
By using the code line, we have controlled the number of living cells according to the neighboring elements of our array.
3-) If our cell is a living cell, we reduced the value of alive_cell by one, since we control itself while controlling its neighbors.
4-) Finally, we checked the number of alice_cell of our series and made our changes.

*/

void game_of_life(int array[ 20 ][ 20 ] , int row , int col )
{
int i , j ; 
int m , n ;
int temp_array[ 20 ][ 20 ] ;
int alive_cell = 0 ;
 
for (i = 1; i < row ; i ++ ) 
{
    for(j = 1 ; j < col ; j ++ )
    {
       temp_array[ i ][ j ] = array[ i ][ j ] ; 
    }
printf("\n") ;
}

for(i = 0 ; i < row ; i ++ )
{
    for(j = 0 ; j < col ; j ++ )
    {
        alive_cell = 0 ;
        for(m = - 1 ; m <= 1 ; m ++ )
        {
           for(n = - 1 ; n <= 1 ;n ++ )
           {
               if(array[i + m ][j + n ] == 1 )
               {
                   alive_cell ++ ;
               }
           }
        }
    if(array[ i ][ j ] == 1 )
    {
        alive_cell -- ;
        if(alive_cell == 3 || alive_cell == 2 )
        {
            temp_array[ i ][ j ] = 1 ;
        }
        else 
        {
            temp_array[ i ][ j ] = 0 ;
        }
        
    }
    else
    {
        if(alive_cell == 3 )
        {
            temp_array[ i ][ j ] = 1 ;
        }
        else
        {
            temp_array[ i ][ j ] = 0 ;
        }
        
    }
    
    }
}

for(i = 0 ; i < row ; i ++ )
{
    for(j = 0 ; j < col ; j ++ )
    {
        printf(" %d " , temp_array[ i ][ j ] ) ;
    } 
printf("\n") ;
}

}

int main()
{

int array[ 20 ][ 20 ] ;
int i , j ;
int row , col ;

printf("Enter row number : " ) ;
scanf("%d" , &row) ;

printf("Enter col number : " ) ;
scanf("%d" , &col ) ;

for(i = 0 ; i < row ; i ++ )
{
    for(j = 0 ; j < col ; j ++ ) 
    {
        printf("%d - row , %d - col : " , i , j ) ;
        scanf("%d" , &array[ i ][ j ] ) ;
    }
printf("\n") ;
}

printf("\n*Original array*\n") ;

for(i = 0 ; i < row ; i ++ )
{
    for(j = 0 ; j < col ; j ++ ) 
    {
        printf(" %d " , array[ i ][ j ] ) ;
    }
printf("\n") ;
}

printf("\n *Game of life array* \n") ;

game_of_life(array , row , col ) ;


    return 0 ;
}

