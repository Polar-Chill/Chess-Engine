#include <iostream>
#include <cstdio>
#include <ostream>
#include <string>
#include <cctype>

#include "ChessBoard.h"
#include "PieceMovement.h"

int main() {
    std::cout << "Engine started successfully..." << std::endl << std::endl << std::endl;

    // Initialyze the main ChessBoard class here 
    ChessBoard chessBoard;

    // Initialyze the PieceMovement class that handles everything related to the piece's movement
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

        bool pieceMoved = pieceMovement.movePiece(fromSquare, toSquare);

        if(pieceMoved == true) {
            printf("Moved the piece from %s to %s\n", fromSquare.c_str(), toSquare.c_str());
        } else {
            std::cout << "Error: Unable to find a piece on the provided square" << std::endl;
            continue;
        }

        chessBoard.renderBoard();
    }

    return 0;
}
