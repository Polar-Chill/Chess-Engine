#include <iostream>
#include <cstdio>
#include <ostream>
#include <string>
#include <cctype>

#include "ChessBoard.h"
#include "PieceMovement.h"

int main() {
    std::cout << "Engine started successfully..." << std::endl << std::endl << std::endl;

    // Initialyze the main
    ChessBoard chessBoard;

    // Initialyze the PieceMovement class that handles everything related to a piece's movement
    PieceMovement pieceMovement(chessBoard);

    // Display the staring board in the terminal
    chessBoard.renderBoard();

    std::string input;

    while(true) {
        std::cout << std::endl << "Enter a move or enter 'exit' to quit: ";
        std::getline(std::cin, input);
        std::cout << std::endl;

        if (input == "exit") {
            std::cout << "Exiting the engine.." << std::endl << "[✓]Exited Successfully" << std::endl;
            break;
        }

        if (input.size() < 2 || isalpha(input[0] && isdigit(input[1]))) {
            std::cout << "Error: Invalid input format. Please use the format 'e2 e4'." << std::endl;
            continue;
        }

        const std::string fromSquare = input.substr(0, 2);
        const std::string toSquare = input.substr(3, 2);

        bool hasPiece = chessBoard.checkSquare(toSquare);
        if(hasPiece == true) {
            pieceMovement.capturePiece(fromSquare, toSquare);
            printf("Captured the piece %s to %s\n", toSquare.c_str(), fromSquare.c_str());
        } else {
            pieceMovement.movePiece(fromSquare, toSquare);
            printf("Moved the piece from %s to %s\n", fromSquare.c_str(), toSquare.c_str());
        }
    }

    return 0;
}
