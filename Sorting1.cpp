#include <iostream>

int main() {
    int N, i, j, k;
    std::cin >> N;
    int *arr = (int*)malloc(N * sizeof(int));
    for(i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    // вводим размер массива и его элементы
    int min, num;
    k = 0;
    for(i = 0; i < N; i++){
        num = N-1;
        min = arr[num];
        for(j = k; j < N; j++){
            if(min >= arr[j]){
                num = j;
                min = arr[num];
            }
        }
        for(j = num - 1; j >= k; j--){
            arr[j + 1] = arr[j];
        }
        arr[k] = min;
        k++;
    }
    for(i = 0; i < N; i++){
        std::cout << arr[i] << ' ';
    }
    return 0;
}
