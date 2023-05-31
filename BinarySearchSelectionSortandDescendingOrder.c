#include <stdio.h>

int binarySearchFirstIndex(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            if (mid == left || arr[mid - 1] > target) {
                return mid;
            } else {
                right = mid - 1;
            }
        } else if (arr[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        int temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, target;

    printf("Masukkan ukuran array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Masukkan elemen-elemen array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Masukkan target yang ingin dicari: ");
    scanf("%d", &target);

    // Urutkan array inputan user secara descending menggunakan selection sort
    selectionSortDescending(arr, n);

    printf("Array setelah diurutkan secara descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Cari target menggunakan binary search
    int result = binarySearchFirstIndex(arr, target, 0, n - 1);

    while (result == -1) {
        printf("Elemen tidak ditemukan dalam array. Masukkan target yang valid: ");
        scanf("%d", &target);
        result = binarySearchFirstIndex(arr, target, 0, n - 1);
    }

    printf("Elemen %d ditemukan pada indeks ke-%d.\n", target, result + 1);

    return 0;
}
