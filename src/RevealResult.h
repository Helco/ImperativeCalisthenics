#pragma once
#include <string>
#include <pair>
#include <optional>

using ErrorMessage = std::string;
using RevealResult = std::pair<Board, std::optional<ErrorMessage>>;
