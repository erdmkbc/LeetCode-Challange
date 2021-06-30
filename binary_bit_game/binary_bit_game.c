#include <stdio.h>

/*
input : 1024
output : 5

The question is decimal numbers's binary forms Returns the maximum number of 0 between two ones

*/

int binary_bit_game(int number){

     int binaryValue ; 
     int binaryArray[20] ;
     int i = 0 ; 
     int counter = 0 ; 
     int j ;   
     int zeroCounter = 0 ; 
     int biggestZeroArea = 0 ; 
    
    while(number != 0) 
     {

         binaryValue = number % 2 ;
         binaryArray[ i ] = binaryValue ;
         i ++ ;
         counter ++ ;
         number = number / 2 ;

         // decimal converted to binary.
     }

    for (i = counter - 1 ; i >= 0 ; i -- ){
         
      if(binaryArray[i] == 1) {
        
        j = i - 1 ;
        
        while(binaryArray[j] == 0){
              
              if(binaryArray[j] == 0 ){
                
                zeroCounter ++ ;
                j-- ;
            
            }
        }
        // Those among the 1s were counted.
    }

    if(biggestZeroArea < zeroCounter ){

        biggestZeroArea = zeroCounter ;
        // Zeros between 1s are counted
    }
    
    zeroCounter = 0 ;
    // The zero counter is reset for the next zero field between the 1s.

}

return  biggestZeroArea ;

}

int main(){

    int number ; 
    printf("Enter the number : " ) ;
    scanf("%d" , &number ) ;
    
    printf("biggest zero value : %d" , binary_bit_game(number) ) ;

return 0 ;

}
