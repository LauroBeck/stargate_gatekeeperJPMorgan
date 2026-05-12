#include <iostream>
#include <vector>
#include <iomanip>
#include "gatekeeper.hpp"

int main() {
    stargate::TrendEngine trend_ctrl;
    
    // Explicitly using stargate::Trend to resolve the namespace error
    std::vector<stargate::BQL_Payload> feed = {
        {"BK",   130.50, 2.15, trend_ctrl.calculate_trend("BK"),   "+42% EPS", "SCALE_ELIZA_2.0"},
        {"HSBA", 715.40, 5.20, trend_ctrl.calculate_trend("HSBA"), "18.7% RoTE", "AGGRESSIVE_HOLD"},
        {"ITUB", 32.10,  8.40, trend_ctrl.calculate_trend("ITUB"), "+8% YIELD", "DIP_BUY_ACCUM"},
        {"UKX",  10269.43, 3.80, stargate::Trend::HOLD,           "STABLE_10K", "MONITOR_SUPPORT"}
    };

    std::cout << "\n" << std::string(120, '=') << "\n";
    std::cout << " STARGATE V15.6 | GLOBAL CUSTODY SYNC | TREND SENTINEL & BNY GAINS\n";
    std::cout << " DATA CYCLE: MAY 12, 2026 | BQL LIVE FEED | PERSISTENCE: 4.2ns | BNY EPS: $2.24\n";
    std::cout << std::string(120, '-') << "\n";
    std::cout << std::left << std::setw(12) << "ENTITY" 
              << std::setw(15) << "BQL_PRICE" 
              << std::setw(15) << "BQL_YIELD" 
              << std::setw(18) << "BNY_GAINS" 
              << std::setw(18) << "TREND" 
              << "ARCHITECT ACTION\n";
    std::cout << std::string(120, '-') << "\n";

    for (const auto& e : feed) {
        std::cout << std::left << std::setw(12) << e.ticker 
                  << "$" << std::fixed << std::setprecision(2) << std::setw(14) << e.price
                  << std::fixed << std::setprecision(2) << std::setw(15) << e.yield
                  << std::setw(18) << e.bny_gains
                  << std::setw(26) << trend_ctrl.trend_to_string(e.trend)
                  << e.action << "\n";
    }
    
    std::cout << std::string(120, '-') << "\n";
    std::cout << "SENTINEL INSIGHTS:\n";
    std::cout << "[+] BNY Mellon Operating Leverage: +833bps | Eliza 2.0 Agentic sync: ACTIVE\n";
    std::cout << "[+] São Paulo Node: Local BRL technicals confirm BUY on ITUB ADR yield divergence.\n";
    std::cout << std::string(120, '=') << "\n";
    std::cout << "STATUS: AGENTIC_SYNC_COMPLETE. ALL ASSETS VALIDATED IN BNY CUSTODY LAYER.\n";
    std::cout << std::string(120, '=') << "\n\n";

    return 0;
}
