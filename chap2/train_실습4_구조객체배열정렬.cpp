#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student ����ü ����
struct Student {
    char* name;
    int age;
    char* city;
};

// �� Student ��ü�� ��ȯ�ϴ� �Լ�
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void interchangeSort(struct Student** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i]->age > arr[j]->age) {
                // ��ȯ
                swap(arr[i], arr[j]); // ���⼭ �����ݷ��� �߰��ؾ� �մϴ�.
            }
        }
    }
}

void showStudents(char* message, struct Student** arr, int n) {
    printf("%s:\n", message);
    for (int i = 0; i < n; i++) {
        printf("�̸�: %s, ����: %d, ����: %s\n", arr[i]->name, arr[i]->age, arr[i]->city);
    }
}

int main() {
    struct Student student1 = { "ȫ�浿", 20, "����" };
    struct Student student2 = { "��ö��", 22, "�λ�" };
    struct Student student3 = { "��浿", 19, "����" };
    struct Student student4 = { "�浿", 39, "����" };
    struct Student student5 = { "ȫ���", 49, "����" };
    struct Student student6 = { "�̱浿", 59, "�뱸" };
    struct Student student7 = { "��浿", 9, "��õ" };

    struct Student* students[7] = { &student1, &student2, &student3, &student4, &student5, &student6, &student7 };

    // �迭�� ũ�� ���
    int numStudents = sizeof(students) / sizeof(students[0]);

    showStudents("������ �迭", students, numStudents);
    // ���� �� ���

    // interchangeSort �Լ��� ����Ͽ� ����ü ��ü �迭 ����
    interchangeSort(students, numStudents);

    // ���� �� ���
    showStudents("\n������ �迭", students, numStudents);

    system("pause");

    return 0;
}
