#include <iostream>
#include <vector>
#include <string>
#include "ChessBoard.h"

// Use the initializer list to properly initialize the Bitboard structs
ChessBoard::ChessBoard()
     :  whitePawns   {0x000000000000FF00, {"W", "P"}, 'P', 1, true},
        whiteKnights {0x0000000000000042, {"W", "K"}, 'N', 3, true},
        whiteBishops {0x0000000000000024, {"W", "B"}, 'B', 3, true},
        whiteRooks   {0x0000000000000081, {"W", "R"}, 'R', 4, true},
        whiteQueen   {0x0000000000000008, {"W", "Q"}, 'Q', 5, true},
        whiteKing    {0x0000000000000010, {"W", "K"}, 'K', 6, true},

        blackPawns   {0x00FF000000000000, {"B", "P"}, 'P', -1, false},
        blackKnights {0x4200000000000000, {"B", "K"}, 'N', -2, false},
        blackBishops {0x2400000000000000, {"B", "B"}, 'B', -3, false},
        blackRooks   {0x8100000000000000, {"B", "R"}, 'R', -4, false},
        blackQueen   {0x0800000000000000, {"B", "Q"}, 'Q', -5, false},
        blackKing    {0x1000000000000000, {"B", "K"}, 'K', -6, false}
{
// Populate the arrays with pointers to the individual pieces
    whitePieces[0] = &whitePawns;
    whitePieces[1] = &whiteKnights;
    whitePieces[2] = &whiteBishops;
    whitePieces[3] = &whiteRooks;
    whitePieces[4] = &whiteQueen;
    whitePieces[5] = &whiteKing;

    blackPieces[0] = &blackPawns;
    blackPieces[1] = &blackKnights;
    blackPieces[2] = &blackBishops;
    blackPieces[3] = &blackRooks;
    blackPieces[4] = &blackQueen;
    blackPieces[5] = &blackKing;
}

// Prints the whole board to the terminal
void ChessBoard::renderBoard() {
    std::cout << "Rendering the Chess Board..\n";

    std::vector<std::vector<std::vector<std::string>>> chessBoard;

    for (int rank = 7; rank >= 0; --rank) {
        std::vector<std::vector<std::string>> currentRank;
        for (int file = 0; file < 8; file++) {
            int index = rank * 8 + file;
            unsigned long long bit = 1ULL << index;
            bool pieceFound = false;

            // Check for white pieces
            for (int i = 0; i < 6; i++) {
                if ((whitePieces[i]->bitboard & bit) != 0) {
                    currentRank.insert(currentRank.end(), whitePieces[i]->symbol);
                    pieceFound = true;
                    break;
                }
            }

            // Check for black pieces
            if (!pieceFound) {
                for (int i = 0; i < 6; i++) {
                    if ((blackPieces[i]->bitboard & bit) != 0) {
                        currentRank.insert(currentRank.end(), blackPieces[i]->symbol);
                        pieceFound = true;
                        break;
                    }
                }
            }

            // Print empty square
            if (!pieceFound) {
                currentRank.insert(currentRank.end(),
                    { " _ _ _ _ _ _ _ _ _ _ _ ",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      "|                     |",
                      " ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ "});
            }
        }
        chessBoard.insert(chessBoard.end(), currentRank);
        // std::cout << std::endl;
    }

    for(int b = 0; b < chessBoard.size(); b++) {
        std::vector<std::string> rankAscii(11, "");
        for(int i = 0; i < chessBoard[b].size(); i++) {
            for(int q = 0; q < chessBoard[b][i].size(); q++) {
                rankAscii[q] += chessBoard[b][i][q];
            }
        }
        for(int i = 0; i < rankAscii.size(); i++) {
            std::cout << rankAscii[i];
            if(i < 10) std::cout << std::endl;
        }
    }

    std::cout << "[✓] Board rendered Successfully\n";
}

bool ChessBoard::checkSquare(std::string square)
{
    int squareFile = square[0] - 'a';
    int squareRank = square[1] - '1';

    int squareIndex = squareRank * 8 + squareFile;

    unsigned long long squarePosition = 1ULL << squareIndex;

    // Check for white pieces
    for(int i = 0; i < 6; i++) {
        if((whitePieces[i]->bitboard & squarePosition) != 0) {
            // std::cout << "There is a piece on square" << square << std::endl;
            return true;
        }
    }

    // Check for black pieces
    for(int i = 0; i < 6; i++) {
        if((blackPieces[i]->bitboard & squarePosition) != 0) {
            // std::cout << "There is a piece on square: " << square << std::endl;
            return true;
        }
    }

    return false;
}

