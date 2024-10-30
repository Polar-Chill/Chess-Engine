#include <iostream>
#include <string>
#include "PieceMovement.h"

// Moves the piece from the provided parameters "fromFile & fromRank" to "toFile & and toRank" 
bool PieceMovement::movePiece(const std::string& fromSquare, const std::string& toSquare) {
    int fF = fromSquare[0] - 'a';
    int fR = fromSquare[1] - '1';
    int tF = toSquare[0] - 'a';
    int tR = toSquare[1] - '1';

    int initialPosition = fR * 8 + fF;
    int newPosition = tR * 8 + tF;

    unsigned long long iPiecePosition = 1ULL << initialPosition;
    unsigned long long nPiecePosition = 1ULL << newPosition;
    
    // Check for white pieces
    for (int i = 0; i < 6; i++) {
        if ((Board.whitePieces[i]->bitboard & iPiecePosition) != 0) {
            Board.whitePieces[i]->bitboard = (Board.whitePieces[i]->bitboard ^ iPiecePosition) | nPiecePosition;
            return true;
        }
    }

    // Check for black pieces 
    for (int i = 0; i < 6; i++) {
        if ((Board.blackPieces[i]->bitboard & iPiecePosition) != 0) {
            Board.blackPieces[i]->bitboard = (Board.blackPieces[i]->bitboard ^ iPiecePosition) | nPiecePosition;
            return true; 
        }
    }

    return false;

}
