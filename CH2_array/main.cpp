#include <iostream>
using namespace std;

//오름차순, 내림차순은 arr[j] > pivot

//오름차순 파티션
int partitionAsending(int* arr, int low, int high) {
    int pivot = arr[high]; // 피벗으로 마지막 요소를 선택
    int i = low - 1;       // 피벗보다 작은 요소들의 끝 위치를 나타냄

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) { // 현재 요소가 피벗보다 작으면 
            ++i; // i를 증가시키고
            swap(arr[i], arr[j]); // i와 j를 교환
        }
    }
    swap(arr[i + 1], arr[high]); // 피벗을 올바른 위치로 이동, i까지가 pivot보다 작은 요소: i+1과 arr[high](Pivot)을 옮겨야 제 위치.
    return i + 1; // 피벗의 최종 위치 반환
}

// 오름차순 퀵정렬 
void quickSortAsending(int* arr, int low, int high) {
    if (low < high) {
        int pi = partitionAsending(arr, low, high); // 배열을 분할하고 피벗의 위치 반환
        // 분할된 배열을 재귀적으로 정렬
        quickSortAsending(arr, low, pi - 1); // 피벗의 왼쪽 부분
        quickSortAsending(arr, pi + 1, high); // 피벗의 오른쪽 부분
    }
}
//내림차순 파티션
int partitionDescending(int* arr, int low, int high) {
    int pivot = arr[high]; // 피벗으로 마지막 요소를 선택
    int i = low - 1;       // 피벗보다 작은 요소들의 끝 위치를 나타냄

    for (int j = low; j < high; ++j) {
        if (arr[j] > pivot) { // 현재 요소가 피벗보다 크면 
            ++i; // i를 증가시키고
            swap(arr[i], arr[j]); // i와 j를 교환
        }
    }
    swap(arr[i + 1], arr[high]); // 피벗을 올바른 위치로 이동
    return i + 1; // 피벗의 최종 위치 반환
}

// 내림차순 퀵정렬  
void quickSortDescending(int* arr, int low, int high) {
    if (low < high) {
        int pi = partitionDescending(arr, low, high); // 배열을 분할하고 피벗의 위치 반환
        // 분할된 배열을 재귀적으로 정렬
        quickSortDescending(arr, low, pi - 1); // 피벗의 왼쪽 부분
        quickSortDescending(arr, pi + 1, high); // 피벗의 오른쪽 부분
    }
}
// 정렬 방법 선택
void SelectMethod(int* arr, int low, int high) {
    int select = 0;
    cout << "정렬 방법 선택, 오름차순(1), 내림차순(2): " << endl;
    cin >> select;
    if (select == 1) {
        quickSortAsending(arr, low, high);
    }
    else if (select == 2) {
        quickSortDescending(arr, low, high);
    }
    else { // 예외처리
        cout << "제대로된 값을 선택해 주세요" << endl; 
        SelectMethod(arr, low, high);
    }

}

int Sum(int* arr, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}

double Avrg(int* arr, int n) {
    return (double)Sum(arr, n) / n;
}


int main() {
    int n = 0;
    cout << "배열의 크기를 입력해 주세요: ";
    cin >> n;
    if (n < 1) { // 예외처리
        cout << "유효한 크기를 입력해 주세요(0 < 입력 값):";
        cin >> n;

    }
    int* arr = new int[n];// 크기만큼 동적할당.

    cout << "배열의 요소를 입력하세요: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "정렬 전 배열: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    SelectMethod(arr,0,n-1);



    cout << "정렬 후 배열: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "점수의 합: " << Sum(arr, n) << "\n" << "평균 점수: " << Avrg(arr, n);
    delete[] arr;
    return 0;
}
