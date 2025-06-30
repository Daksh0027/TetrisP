#include "colors.h"

const Color teal        = {0, 128, 128, 255};    // Calm teal
const Color lime        = {140, 255, 0, 255};    // Bright lime green
const Color magenta     = {255, 0, 255, 255};    // Vivid magenta
const Color gold        = {255, 215, 0, 255};    // Shiny gold
const Color salmon      = {250, 128, 114, 255};  // Warm salmon pink
const Color indigo      = {75, 0, 130, 255};     // Deep indigo
const Color olive       = {128, 128, 0, 255};    // Earthy olive
const Color mint        = {170, 255, 195, 255};  // Soft mint green
const Color pink        = {255, 105, 180, 255};  // Hot pink
const Color silver      = {192, 192, 192, 255};  // Light silver grey

std::vector<Color> GetCellColors()
{
    return {teal, lime, magenta, gold, salmon, indigo, olive, mint, pink, silver};
}