#pragma once

#include <vector>
#include <string>

class PieceDescription {
public:
    std::vector<std::string> getPawnMoves(const std::string& position);
    std::vector<std::string> getKnightMoves(const std::string& position);
    std::vector<std::string> getBishopMoves(const std::string& position);
    std::vector<std::string> getRookMoves(const std::string& position);
    std::vector<std::string> getQueenMoves(const std::string& position);
    std::vector<std::string> getKingMoves(const std::string& position);

};

