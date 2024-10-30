#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>

struct ChessPiece {
    unsigned long long bitboard;
    std::string symbol;
    char pieceType;
    bool isWhite;
};

class PieceMovement;

class ChessBoard {
public:
    ChessBoard();
    void renderBoard();
    void promotePawn(int rank, int file, char promoteToPiece);

    friend class PieceMovement;

private:
    ChessPiece whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueen, whiteKing;
    ChessPiece blackPawns, blackKnights, blackBishops, blackRooks, blackQueen, blackKing;

    // Arrays for holding the pieces in a collective manner
    ChessPiece* whitePieces[6];
    ChessPiece* blackPieces[6];

};

#endif // CHESSBOARD_H
