#include <iostream>
using namespace std;

//��������, ���������� arr[j] > pivot

//�������� ��Ƽ��
int partitionAsending(int* arr, int low, int high) {
    int pivot = arr[high]; // �ǹ����� ������ ��Ҹ� ����
    int i = low - 1;       // �ǹ����� ���� ��ҵ��� �� ��ġ�� ��Ÿ��

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) { // ���� ��Ұ� �ǹ����� ������ 
            ++i; // i�� ������Ű��
            swap(arr[i], arr[j]); // i�� j�� ��ȯ
        }
    }
    swap(arr[i + 1], arr[high]); // �ǹ��� �ùٸ� ��ġ�� �̵�, i������ pivot���� ���� ���: i+1�� arr[high](Pivot)�� �Űܾ� �� ��ġ.
    return i + 1; // �ǹ��� ���� ��ġ ��ȯ
}

// �������� ������ 
void quickSortAsending(int* arr, int low, int high) {
    if (low < high) {
        int pi = partitionAsending(arr, low, high); // �迭�� �����ϰ� �ǹ��� ��ġ ��ȯ
        // ���ҵ� �迭�� ��������� ����
        quickSortAsending(arr, low, pi - 1); // �ǹ��� ���� �κ�
        quickSortAsending(arr, pi + 1, high); // �ǹ��� ������ �κ�
    }
}
//�������� ��Ƽ��
int partitionDescending(int* arr, int low, int high) {
    int pivot = arr[high]; // �ǹ����� ������ ��Ҹ� ����
    int i = low - 1;       // �ǹ����� ���� ��ҵ��� �� ��ġ�� ��Ÿ��

    for (int j = low; j < high; ++j) {
        if (arr[j] > pivot) { // ���� ��Ұ� �ǹ����� ũ�� 
            ++i; // i�� ������Ű��
            swap(arr[i], arr[j]); // i�� j�� ��ȯ
        }
    }
    swap(arr[i + 1], arr[high]); // �ǹ��� �ùٸ� ��ġ�� �̵�
    return i + 1; // �ǹ��� ���� ��ġ ��ȯ
}

// �������� ������  
void quickSortDescending(int* arr, int low, int high) {
    if (low < high) {
        int pi = partitionDescending(arr, low, high); // �迭�� �����ϰ� �ǹ��� ��ġ ��ȯ
        // ���ҵ� �迭�� ��������� ����
        quickSortDescending(arr, low, pi - 1); // �ǹ��� ���� �κ�
        quickSortDescending(arr, pi + 1, high); // �ǹ��� ������ �κ�
    }
}
// ���� ��� ����
void SelectMethod(int* arr, int low, int high) {
    int select = 0;
    cout << "���� ��� ����, ��������(1), ��������(2): " << endl;
    cin >> select;
    if (select == 1) {
        quickSortAsending(arr, low, high);
    }
    else if (select == 2) {
        quickSortDescending(arr, low, high);
    }
    else { // ����ó��
        cout << "����ε� ���� ������ �ּ���" << endl; 
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
    cout << "�迭�� ũ�⸦ �Է��� �ּ���: ";
    cin >> n;
    if (n < 1) { // ����ó��
        cout << "��ȿ�� ũ�⸦ �Է��� �ּ���(0 < �Է� ��):";
        cin >> n;

    }
    int* arr = new int[n];// ũ�⸸ŭ �����Ҵ�.

    cout << "�迭�� ��Ҹ� �Է��ϼ���: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "���� �� �迭: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    SelectMethod(arr,0,n-1);



    cout << "���� �� �迭: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "������ ��: " << Sum(arr, n) << "\n" << "��� ����: " << Avrg(arr, n);
    delete[] arr;
    return 0;
}
