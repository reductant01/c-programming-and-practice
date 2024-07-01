#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student 구조체 정의
struct Student {
    char* name;
    int age;
    char* city;
};

// 두 Student 객체를 교환하는 함수
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void interchangeSort(struct Student** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i]->age > arr[j]->age) {
                // 교환
                swap(arr[i], arr[j]); // 여기서 세미콜론을 추가해야 합니다.
            }
        }
    }
}

void showStudents(char* message, struct Student** arr, int n) {
    printf("%s:\n", message);
    for (int i = 0; i < n; i++) {
        printf("이름: %s, 나이: %d, 도시: %s\n", arr[i]->name, arr[i]->age, arr[i]->city);
    }
}

int main() {
    struct Student student1 = { "홍길동", 20, "서울" };
    struct Student student2 = { "김철수", 22, "부산" };
    struct Student student3 = { "김길동", 19, "대전" };
    struct Student student4 = { "길동", 39, "전주" };
    struct Student student5 = { "홍길순", 49, "광주" };
    struct Student student6 = { "이길동", 59, "대구" };
    struct Student student7 = { "빅길동", 9, "춘천" };

    struct Student* students[7] = { &student1, &student2, &student3, &student4, &student5, &student6, &student7 };

    // 배열의 크기 계산
    int numStudents = sizeof(students) / sizeof(students[0]);

    showStudents("정렬전 배열", students, numStudents);
    // 정렬 전 출력

    // interchangeSort 함수를 사용하여 구조체 객체 배열 정렬
    interchangeSort(students, numStudents);

    // 정렬 후 출력
    showStudents("\n정렬후 배열", students, numStudents);

    system("pause");

    return 0;
}
