#include <SFML/Graphics.hpp>
#include <time.h>

#define BLACK_PAWN -6
#define WHITE_PAWN 6
#define BLACK_BISHOP -3
#define WHITE_BISHOP 3
#define BLACK_ROOK -1
#define WHITE_ROOK 1
#define BLACK_KNIGHT -2
#define WHITE_KNIGHT 2
#define BLACK_QUEEN -4
#define WHITE_QUEEN 4
#define BLACK_KING -5
#define WHITE_KING 5

using namespace sf;

int gridSize = 56;
int initBK = 0;
int initWK = 0;
int initBQ = 0;
int initWQ = 0;
int initBN = 0;
int initWN = 0;
int initBB = 0;
int initWB = 0;
int initBP = 0;
int initWP = 0;
int initBR = 0;
int initWR = 0;
Sprite pieces[32]; //chess pieces for both sides

int chessBoard[8][8] = { -1, -2, -3, -4, -5, -3, -2, -1,
						-6, -6, -6, -6, -6, -6, -6, -6,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						6, 6, 6, 6, 6, 6, 6, 6,
						1, 2, 3, 4, 5, 3, 2, 1 };



int main() {
	RenderWindow window(VideoMode(600, 600), "Chess!");

	Texture board, dP, lP, dN, lN, dQ, lQ, dR, lR, dK, lK, dB, lB;
	board.loadFromFile("chessboard.png");
	dP.loadFromFile("Chess_pdt60.png");
	lP.loadFromFile("Chess_plt60.png");
	dN.loadFromFile("Chess_ndt60.png");
	lN.loadFromFile("Chess_nlt60.png");
	dQ.loadFromFile("Chess_qdt60.png");
	lQ.loadFromFile("Chess_qlt60.png");
	dR.loadFromFile("Chess_rdt60.png");
	lR.loadFromFile("Chess_rlt60.png");
	dK.loadFromFile("Chess_kdt60.png");
	lK .loadFromFile("Chess_klt60.png");
	dB.loadFromFile("Chess_bdt60.png");
	lB.loadFromFile("Chess_blt60.png");
	
	Sprite sBoard(board);
	Sprite darkPawn(dP);
	Sprite whitePawn(lP);
	Sprite darkKnight(dN);
	Sprite whiteKnight(lN);
	Sprite darkQueen(dQ);
	Sprite whiteQueen(lQ);
	Sprite darkRook(dR);
	Sprite whiteRook(lR);
	Sprite darkKing(dK);
	Sprite whiteKing(lK);
	Sprite darkBishop(dB);
	Sprite whiteBishop(lB);


	bool isMove = false;
	float dx = 0, dy = 0;


	while (window.isOpen()) {
		Vector2i pos = Mouse::getPosition(window);
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
			
			//Drag and drop chess pieces
			if (e.type == Event::MouseButtonPressed) {
				if (e.key.code == Mouse::Left) {
					if (whiteKing.getGlobalBounds().contains(pos.x, pos.y)) {
						isMove = true;
						dx = pos.x - whiteKing.getPosition().x;
						dy = pos.y - whiteKing.getPosition().y;
					}
				}
			}
			
			if (e.type == Event::MouseButtonReleased) {
				if (e.key.code == Mouse::Left) {
					isMove = false;
				}
			}
		}
		
		if (isMove) {
			whiteKing.setPosition(pos.x - dx, pos.y - dy);
		}
		

		//Render images
		window.clear();
		window.draw(sBoard);
		//window.draw(whiteKing);
	
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (chessBoard[i][j] != 0) {
					if (chessBoard[i][j] == BLACK_PAWN) {
						darkPawn.setPosition(j * 67 + 35, 100);
						window.draw(darkPawn);
					}
					if (chessBoard[i][j] == WHITE_PAWN) {
						whitePawn.setPosition(j * 67 + 35, 435);
						window.draw(whitePawn);
					}
					if (chessBoard[i][j] == BLACK_ROOK) {
						darkRook.setPosition(j * 67 + 35, 35);
						window.draw(darkRook);
					}
					if (chessBoard[i][j] == WHITE_ROOK) {
						whiteRook.setPosition(j * 67 + 35, 505);
						window.draw(whiteRook);
					}
					if (chessBoard[i][j] == BLACK_KNIGHT) {
						darkKnight.setPosition(j * 67 + 35, 35);
						window.draw(darkKnight);
					}
					if (chessBoard[i][j] == WHITE_KNIGHT) {
						whiteKnight.setPosition(j * 67 + 35, 505);
						window.draw(whiteKnight);
					}
					if (chessBoard[i][j] == BLACK_BISHOP) {
						darkBishop.setPosition(j * 67 + 35, 35);
						window.draw(darkBishop);
					}
					if (chessBoard[i][j] == WHITE_BISHOP) {
						//if (initWB < 2) {
							whiteBishop.setPosition(j * 67 + 35, 505);
							initWB++;
						//}
						window.draw(whiteBishop);
					}
					if (chessBoard[i][j] == BLACK_QUEEN) {
						if (initBQ < 1) {
							darkQueen.setPosition(j * 67 + 35, 35);
						}
						initBQ = 1;
						window.draw(darkQueen);
					}
					if (chessBoard[i][j] == WHITE_QUEEN) {
						if (initWQ < 1) {
							whiteQueen.setPosition(j * 67 + 35, 505);
						}
						initWQ = 1;
						window.draw(whiteQueen);
					}
					if (chessBoard[i][j] == BLACK_KING) {
						if (initBK < 1) {
							darkKing.setPosition(j * 67 + 35, 35);
						}
						initBK = 1;
						window.draw(darkKing);
					}
					if (chessBoard[i][j] == WHITE_KING) {
						if (initWK < 1) {
							whiteKing.setPosition(j * 67 + 35, 505);
						}
						initWK = 1;
						window.draw(whiteKing);
					}
				}
			}
		}

		window.display();

	}
	return 0;
}




