#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
    char* name;
};


int compareRectangles(const Rectangle* a, const Rectangle* b) {
    return (a->leftBottomX - b->leftBottomX);
}
void showRectangle(struct Rectangle r) {
    printf("[%d, %d, %d, %d, %s]\n", r.leftBottomX, r.leftBottomY, r.width, r.height, r.name);
}

void changeRectangle(Rectangle* r, char* newName) {
    cout << "r1 name is changed" << endl;
    // r.name = newName;
    // strcpy(r.name, newName);
    r->name = strdup(newName);
}

void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
    //void showRectangle(struct Rectangle r) 사용

}
void swap(Rectangle* rect[], int i, int j) {

}
void selectionSortRectangles(Rectangle* rectangles[], int numRectangles) {
    // int compareRectangles(const Student* b);를 사용한 정렬
    // void swap(Rectangle * rect[], int i, int j) 사용

}
int main(void) {
    const int numRectangles = 5;
    struct Rectangle r1 = { 3, 5, 10, 15,"r1" };
    struct Rectangle r2 = { 1, 2, 8, 12 ,"r2" };
    struct Rectangle r3 = { 7, 9, 6, 10,"r3" };
    struct Rectangle r4 = { 4, 6, 7, 8 ,"r4" };
    struct Rectangle r5 = { 2, 3, 9, 14,"r5" };
    Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };

    showRectangles("Before:", rectangles, numRectangles);
    changeRectangle(&r1, "square");
    printf("address of r1= %p, %p", &r1, rectangles[0]);
    showRectangle(r1);
    showRectangles("After changing:", rectangles, numRectangles);
    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("After sorting:", rectangles, numRectangles);


    system("pause");
    return 0;
}