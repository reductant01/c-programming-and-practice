//N Queen problem, The N Queen is the problem of placing N chess queens on an N×N chessboard
//so that no two queens attack each other
//Knight’s tour and Rat in a Maze problems 
/*
- 상속의 이점 : 중복 코딩을 줄이는 효과를 보여주는 코딩, 재사용
*/
class Matrix {
	int rows, cols;
	int *element;
public:
	int Show() {

	}
};
class ChessBoard : public Matrix {
	int* mark; //체스판에 객체가 놓였는지를 표시
};