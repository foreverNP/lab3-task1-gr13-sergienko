#include <stdio.h>
#include <stdlib.h>

// 
int countOnes(int num) {
  int count = 0;
  while (num > 0) {
    count += num % 2;
    num /= 2;
  }
  return count;
}

// 
int compareByOnes(const void *a, const void *b) {
  int onesA = countOnes(*(int *)a);
  int onesB = countOnes(*(int *)b);
  return onesA - onesB;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Использование: %s <размер_массива>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n <= 0) {
    printf("Размер массива должен быть положительным числом.\n");
    return 1;
  }

  int *arr = (int *)malloc(n * sizeof(int));

  // 
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 31; // 
  }

  printf("Исходные данные:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // 
  qsort(arr, n, sizeof(int), compareByOnes);

  printf("Результат:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}
