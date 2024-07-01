//�й�
//�̸�
//Github ID:
//2019�� 1�б� �ǽ��ڵ�-coding exam - �ʹ� ����� �л��� ��� ����
/*
testing items:
1) virtual function, dynamic binding
2) operator overloading
3) code reuse for private data access
*/
#include <iostream>
using namespace std;
enum ObjectPiece {EMPTY, WALL, BISHOP, XBISHOP, ROOK, XROOK, QUEEN, XQUEEN};
//XROOK, XBISHOP, XQUEEN�� ROOK, BISHOP, QUEEN�� ���� �ٸ� piece�� put�� �� ������ ǥ��
ObjectPiece board[10][10];//[0], [9]: boundary
class Piece;
class ChessBoard {
public:
	ChessBoard();
	int AddPiece(Piece *);//board[i][j]�� piece�� �߰�
	int MoreAddPiece();//board[][]�� piece�� �� �̻� �߰��� �� �������� check
	friend ostream& operator<<(ostream& stream, ChessBoard& cb);//need to implement <<()
};
class Piece {
protected:
	int x;
	int y;
	ObjectPiece PieceType;
public:
	virtual int CheckBoard(int, int);
	virtual ObjectPiece MarkPiece(int row, int col) { x = row; y = col; }
	friend ostream & operator<<(ostream & stream, Piece& p);//�Լ� ����
};
class Bishop : public Piece {
	//move any number of squares in a diagonal direction
public:
	Bishop() { PieceType = BISHOP; }
	~Bishop() {}
	int CheckBoard(int row, int col) {
		//current location(x,y)�� �밢���� �ٸ� ��ü ���θ� ����, XBISHOP, XROOK, XQUEEN�� ������
		return 0;//no checked piece
	}
	ObjectPiece MarkPiece(int row, int col);
	friend ostream & operator<<(ostream & stream, Bishop& p);
};
class Rook : public Piece {
public:
	Rook() { PieceType = ROOK; }
	~Rook() {}
	//move any number of squares in a straight line along any row or column
	int CheckBoard(int row, int col) {
		//current location(x,y)�� ����, ���򼱿� �ٸ� ��ü ���θ� ����, XBISHOP, XROOK, XQUEEN�� ������
		return 0;//no checked piece
	}
	ObjectPiece MarkPiece(int, int);
	friend ostream & operator<<(ostream & stream, Rook& p);
};
class Queen : public Piece {
public:
	Queen() { PieceType = QUEEN; }
	~Queen() {}
	/*
	chessboard queen can attack horizontally and vertically and diagonally.
	The N queen is the problem of placing N chess queens on an 8 x 8 chessboard so that
	no two queens attack each other
	*/
	int CheckBoard(int row, int col) {
		//current location(x,y)�� ����, ����, �밢���� �ٸ� ��ü ���θ� ���� - return 1;//checked piece
		//XBISHOP, XROOK, XQUEEN�� ������
		return 0;//no checked piece
	}
	ObjectPiece MarkPiece(int, int);
	friend ostream & operator<<(ostream & stream, Queen& p);
};

int ChessBoard::AddPiece(Piece *p) {
	do {
		int row = 0, col = 0;
		//random number �����Ͽ� 1<=row<=8, 1<=col<=8
		if (board[row][col] == EMPTY) {
			if (!p->CheckBoard(row, col)) {//board[row][col]�� piece�� �߰��� �� �ִ����� check
				ObjectPiece op = p->MarkPiece(row, col);//piece�� eat �� �� �ִ� room�� marking
				board[row][col] = op;//add piece to board[row][col]
				break;
			}
		}
	} while (MoreAddPiece());//add�Ǵ� piece�� �߰��� �� �ִ� ������ ������ �ݺ�
	return 1;
}
ChessBoard::ChessBoard() {//�ʱ�ȭ ����
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			if (i == 0 || i == 10 || j == 0 || j == 10)
				board[i][j] = WALL;
			else board[i][j] = EMPTY;
}
int ChessBoard::MoreAddPiece() {
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			if (board[i][j] == EMPTY)
				return 1;
			else return 0;
}
ObjectPiece Bishop::MarkPiece(int row, int col) {
	Piece::MarkPiece(row, col);
	//check diagonal - board[i][j] = XBISHOP;
		//if conflicted with Rook, Bishop, priority order: Queen > Rook > Bishop
	return BISHOP;
}
ObjectPiece Rook::MarkPiece(int row, int col) {
	Piece::MarkPiece(row, col);
	//check vertical and horizontal line - board[][] = XROOK;
		//if conflicted with Rook, Bishop, priority order: Queen > Rook > Bishop
	return ROOK;
}
ObjectPiece Queen::MarkPiece(int row, int col) {
	Piece::MarkPiece(row, col);
	//check diagonal, vertical, horizontal line: board[][] = XQUEEN;
	//if conflicted with Rook, Bishop, priority order: Queen > Rook > Bishop
	return QUEEN;
}
ostream & operator<<(ostream & stream, Piece& p) {
	//
}
ostream & operator<<(ostream & stream, Queen& p) {
	cout << (Piece)p;
	//
}
ostream & operator<<(ostream & stream, Rook& p) {
	cout << (Piece)p;
	//
}
ostream & operator<<(ostream & stream, Bishop& p) {
	cout << (Piece)p;
	//
}
int main() {
	ChessBoard cb;
	Piece* p[20];
	int random;
	for (int i = 0; i < 20; i++)
		//rand() ȣ���Ͽ� 0<=random<=2 ����
		if (random == 0)
			p[i] = new Bishop;
		else if (random == 1)
			p[i] = new Rook;
		else p[i] = new Queen;
	int index = 0;
	do
	{
		//rand() ȣ���Ͽ� 0<= index<= 20 ����
		cb.AddPiece(p[index++]);
	} while (cb.MoreAddPiece());
	for (int i = 0; i < 20; i++)
		cout << " Piece object Type = " << *p[i] << endl;//piece �� queen, rook, bishop���� ǥ��
	cout << "ChessBoard[][] = " << cb << endl;//piece �� queen, rook, bishop, xqueen, xrook, xbishop���� ǥ��
	system("pause");
	return 1;
}