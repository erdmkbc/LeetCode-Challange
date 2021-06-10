#include <stdio.h>

/*
Question : 

1 0 0 0 
1 0 0 1 
1 0 0 1
1 1 1 1

0 1 1 1
0 1 1 1
0 1 1 1
0 0 0 0

*/


void zeroes_to_the_corner (int array[ 20 ][ 20 ] , int row , int col ) 
{

int i , j ;
int temp ;
int m = 0 , n = 0 ;

for(i = 0 ; i < row - 1 ; i ++ )
{
    for(j = 1 ; j < col ; j ++ )
    {
        if(array[ i ][ j ] == 0 )
        {
           if(m == row - 1 )
           {
                temp = array[ row - 1  ][ n ] ;
                array[ row - 1 ][ n ] = array[ i ][ j ] ;
                array[ i ][ j ] = temp ;
                n ++ ;
           }
           else 
           {
                temp = array[ m  ][ 0 ] ;
                array[ m ][ 0 ] = array[ i ][ j ] ;
                array[ i ][ j ] = temp ;
                m ++ ;
           }
        }
    }
}
printf("\n") ;
for(i = 0 ; i < row ; i ++ )
{
    for(j = 0 ; j < col ; j ++ )
    {
        printf(" %d " , array[ i ][ j ] ) ;
    }
printf("\n") ;
}

}

int main()
{
    
int array[ 20 ][ 20 ] ;
int temp_row , temp_col ;
int i , j ;

printf("Enter the row number : " ) ;
scanf("%d", &temp_row ) ;

printf("Enter the coloumn number : " ) ;
scanf("%d", &temp_col ) ;

for(i = 0 ; i < temp_row ; i ++ )
{
   for(j = 0 ; j < temp_col ; j ++ )
   {
       printf("%d - row , %d - col : " , i , j ) ;
       scanf("%d" , &array[ i ][ j ] ) ;
   }
printf("\n") ;
}

printf("\n*Original array*\n") ;

for(i = 0 ; i < temp_row ; i ++ ) 
{
    for(j = 0 ; j < temp_col ; j ++ )
    {
        printf(" %d " , array[ i ][ j ] ) ;
    }
printf("\n") ;
}

printf("*\nLeetcode's array*\n") ;

zeroes_to_the_corner(array , temp_row , temp_col ) ;

return 0 ;
}