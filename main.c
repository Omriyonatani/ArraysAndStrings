#include "isort.h"
#include <stdio.h>
#define LENGTH 50

int main()
{
    int arr[LENGTH];
    for (int i = 0; i<LENGTH ; i++){
        printf("Enter a number:\n");
        scanf("%d",(arr+i));
    }

    insertion_sort(arr,LENGTH);

    for (int j = 0; j<LENGTH ; j++){
      printf("%d",arr[j]);
      if (j < LENGTH-1) {
        printf(",");
      }
    }
    return 0;
}
