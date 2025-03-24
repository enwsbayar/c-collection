// Given an array X of positive integers, its elements are to be transformed by running the following operation on them as many times as required:

// if X[i] > X[j] then X[i] = X[i] - X[j]

// When no more transformations are possible, return its sum ("smallest possible sum").

// For instance, the successive transformation of the elements of input X = [6, 9, 21] is detailed below:

// X_1 = [6, 9, 12] # -> X_1[2] = X[2] - X[1] = 21 - 9
// X_2 = [6, 9, 6]  # -> X_2[2] = X_1[2] - X_1[0] = 12 - 6
// X_3 = [6, 3, 6]  # -> X_3[1] = X_2[1] - X_2[0] = 9 - 6
// X_4 = [6, 3, 3]  # -> X_4[2] = X_3[2] - X_3[1] = 6 - 3
// X_5 = [3, 3, 3]  # -> X_5[1] = X_4[0] - X_4[1] = 6 - 3
// The returning output is the sum of the final transformation (here 9).

// Example
// solution([6, 9, 21]) #-> 9
// Solution steps:
// [6, 9, 12] #-> X[2] = 21 - 9
// [6, 9, 6] #-> X[2] = 12 - 6
// [6, 3, 6] #-> X[1] = 9 - 6
// [6, 3, 3] #-> X[2] = 6 - 3
// [3, 3, 3] #-> X[1] = 6 - 3
// Additional notes:
// There are performance tests consisted of very big numbers and arrays of size at least 30000. Please write an efficient algorithm to prevent timeout.

#include <stdio.h>

int smallestPossibleSum(size_t n, int array[n]);

int main()
{
  int array[3] = {6,9,21};

  printf("%d\n",smallestPossibleSum(3,array));
  
  return 0;
}

int smallestPossibleSum(size_t n, int array[n])
{
  int i = 0, j = 1, k = -1;
  int l = 0;
  int check = 0;

  while(check + 1)
  {
    int total = 0;
    while(j != n)
    {
      if(array[i] > array[j])
      {
        array[i] = array[i] - array[j];
      }
      i += 1;
      j += 1;
      k += 1;   
    }
    while(k >= 0)
    {
      if(array[i] > array[k])
      {
        array[i] = array[i] - array[k];
      }
      i -= 1;
      j -= 1;
      k -= 1;
    }
    int i = 0, j = 1, k = -1;

    for(l = 1; l < n; l++)
    {
      if(array[l] != array[l-1])
      {
        break;
      }
      else
      {
        total +=1;
        if(total == n-1)
        {
          return array[0]*n;
        }
      }
    }
  }
}
