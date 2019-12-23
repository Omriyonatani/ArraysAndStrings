
//this function moves i numbers to the right stars with where 
shift_element(int* arr, int* i) {              
int j;
	for(j = *i; i > arr && *(i-1) > j; i--) {
		*i = *(i-1);
	}
	*i = j;
}

//this function does insertion sort to the array
  insertion_sort(int* arr, int len) {
  int *i, *last = arr + len;
	for(i = arr + 1; i < last; i++)
		if(*i < *(i-1))
			shift_element(arr, i);
  }



        














    