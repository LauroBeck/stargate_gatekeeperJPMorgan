#ifndef GATEKEEPER_HPP
#define GATEKEEPER_HPP

#include <string>
#include <vector>

namespace stargate {

enum class Trend { BUY, HOLD, SELL };

struct BQL_Payload {
    std::string ticker;
    double price;
    double yield;
    Trend trend;
    std::string bny_gains;
    std::string action;
};

class TrendEngine {
public:
    Trend calculate_trend(const std::string& ticker) {
        if (ticker == "BK") return Trend::BUY;   // +42% EPS surge
        if (ticker == "ITUB") return Trend::BUY;  // Yield Divergence / Oversold
        if (ticker == "HSBA") return Trend::HOLD; // 18.7% RoTE Stabilization
        return Trend::HOLD;
    }

    std::string trend_to_string(Trend t) {
        switch(t) {
            case Trend::BUY:  return "\033[1;32mBUY\033[0m";  // Bold Green
            case Trend::HOLD: return "\033[1;33mHOLD\033[0m"; // Bold Yellow
            case Trend::SELL: return "\033[1;31mSELL\033[0m"; // Bold Red
        }
        return "N/A";
    }
};

} 
#endif
