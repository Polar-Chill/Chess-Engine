#pragma once
#include "ChessBoard.h"

#include <string>

class PieceMovement {

private:
    ChessBoard& Board;

public:
    PieceMovement(ChessBoard& b) : Board(b) {}
    bool movePiece(const std::string& fromSquare, const std::string& toSquare);
    int convertNotationToIndex(std::string& input_string);
    void isMoveValid();
    void capturePiece(int fromRank, int fromFile, int toRank, int toFile);

};
