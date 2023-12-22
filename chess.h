#pragma once

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

class Square {

    Piece piece;
    Color color;
    int x{}, y{};
public:
    void setSpace(const Square*);
    void setEmpty();
    void setPieceAndColor(Piece, Color);
    [[nodiscard]] Piece getPiece() const;
    [[nodiscard]] Color getColor() const;
    void setX(const int ex) { x = ex; }
    void setY(const int why) { y = why; }
    [[nodiscard]] int getX() const { return x; }
    [[nodiscard]] int getY() const { return y; }
    Square();
};

class Board {
    Square square[8][8];
    Color turn=WHITE;

    static bool moveKing(Square* thisKing, Square* thatSpace);
    bool moveQueen(Square* thisQueen, Square* thatSpace) const;
    bool moveBishop(Square* thisBishop, Square* thatSpace) const;

    static bool moveKnight(Square* thisKnight, Square* thatSpace);
    bool moveRook(Square* thisRook, Square* thatSpace) const;

    static bool movePawn(Square* thisPawn, Square* thatSpace);
    bool makeMove(int x1, int y1, int x2, int y2);
    void printBoard() const;
public:
    Square* getSquare(const int x, const int y) {
        return &square[x][y];
    }
    void setSquare(const Square * s, const int x, const int y){
        square[x][y]=*s;
    }
    bool doMove();

    void setBoard();
    bool playGame();
};
