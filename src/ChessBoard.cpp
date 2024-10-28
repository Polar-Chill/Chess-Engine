#include <iostream>
#include "ChessBoard.h"

// Use the initializer list to properly initialize the Bitboard structs
ChessBoard::ChessBoard()
     :  whitePawns   {0x000000000000FF00, "WP", 'P', true},
        whiteKnights {0x0000000000000042, "WN", 'N', true},
        whiteBishops {0x0000000000000024, "WB", 'B', true},
        whiteRooks   {0x0000000000000081, "WR", 'R', true},
        whiteQueen   {0x0000000000000008, "WQ", 'Q', true},
        whiteKing    {0x0000000000000010, "WK", 'K', true},

        blackPawns   {0x00FF000000000000, "BP", 'P', false},
        blackKnights {0x4200000000000000, "BN", 'N', false},
        blackBishops {0x2400000000000000, "BB", 'B', false},
        blackRooks   {0x8100000000000000, "BR", 'R', false},
        blackQueen   {0x0800000000000000, "BQ", 'Q', false},
        blackKing    {0x1000000000000000, "BK", 'K', false}
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

// Combines all the bitboard into one main board that will be displayed.
unsigned long long ChessBoard::combineBitBoards() {
    unsigned long long board = 0Ull;

    board |= whitePawns.bitboard;
    board |= whiteKnights.bitboard;
    board |= whiteBishops.bitboard;
    board |= whiteRooks.bitboard;
    board |= whiteQueen.bitboard;
    board |= whiteKing.bitboard;
    
    board |= blackPawns.bitboard;
    board |= blackKnights.bitboard;
    board |= blackBishops.bitboard;
    board |= blackRooks.bitboard;
    board |= blackQueen.bitboard;
    board |= blackKing.bitboard;

    return board;
}

// Prints the whole board to the terminal
void ChessBoard::renderBoard() {
    unsigned long long chessBoard = combineBitBoards();

    for (int rank = 7; rank >=0; --rank) {
        std::cout << "                                      ";
        for (int file = 0; file < 8; file++) {
            int index = rank * 8 + file;
            unsigned long long bit = 1ULL << index;

            // Check for white pieces
            // for(int i = 0; i < 6; i++) {
            //     if((whitePieces[i]->bitboard & bit) != 0) { 
            //         std::cout << whitePieces[i]->symbol << " ";
            //         break;
            //     }
            //     else std::cout << "00 "; // Empty square
            //     break;
            // }
            //
            // Check for black pieces
            // for(int i = 0; i < 6; i++) {
            //     if((blackPieces[i]->bitboard & bit) != 0) {
            //         std::cout << blackPieces[i]->symbol << " ";
            //         break;
            //     }
            //     else std::cout << "00 "; // Empty square
            //     break;
            // }

            // Check for white pieces
            if ((whitePawns.bitboard & bit) != 0) std::cout << "WP "; 
            else if ((whiteKnights.bitboard & bit) != 0) std::cout << "WN "; 
            else if ((whiteBishops.bitboard & bit) != 0) std::cout << "WB "; 
            else if ((whiteRooks.bitboard & bit) != 0) std::cout << "WR "; 
            else if ((whiteQueen.bitboard & bit) != 0) std::cout << "WQ "; 
            else if ((whiteKing.bitboard & bit) != 0) std::cout << "WK "; 

            // Check for black pieces
            else if ((blackPawns.bitboard & bit) != 0) std::cout << "BP ";
            else if ((blackKnights.bitboard & bit) != 0) std::cout << "BN "; 
            else if ((blackBishops.bitboard & bit) != 0) std::cout << "BB "; 
            else if ((blackRooks.bitboard & bit) != 0) std::cout << "BR "; 
            else if ((blackQueen.bitboard & bit) != 0) std::cout << "BQ "; 
            else if ((blackKing.bitboard & bit) != 0) std::cout << "BK "; 
            else std::cout << "00 "; // Empty toSquare
        }
        std::cout << std::endl;
    }
}

