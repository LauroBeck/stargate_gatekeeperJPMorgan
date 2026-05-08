#include <iostream>
#include <iomanip>
#include "gatekeeper.hpp"

int main() {
    stargate::RiskEngine engine;
    
    // Simulate the JEPQ "Big Aport" from your Nasdaq screenshot
    stargate::AportRequest jpm_inflow = {
        "JEPQ", 
        1200000000.0, // $1.2 Billion Big Aport
        59.545,       // Price from your screenshot
        0.18          // Estimated Volatility
    };

    auto result = engine.evaluate_big_aport(jpm_inflow);

    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << " JPMORGAN ASSET MANAGEMENT - STARGATE INFLOW GATEWAY\n";
    std::cout << std::string(60, '-') << "\n";
    std::cout << " TARGET TICKER      : " << jpm_inflow.ticker << "\n";
    std::cout << " APORT AMOUNT       : $" << std::fixed << std::setprecision(2) << jpm_inflow.amount_usd / 1e6 << " Million\n";
    std::cout << " CURRENT NAV        : $" << jpm_inflow.current_nav << "\n";
    std::cout << std::string(60, '-') << "\n";
    std::cout << " EXECUTION STATUS   : " << result.status << "\n";
    std::cout << " ESTIMATED SLIPPAGE : " << result.slippage_est * 100 << " bps\n";
    std::cout << " RISK SCORE         : " << result.risk_score << "\n";
    std::cout << " ROUTING PROTOCOL   : " << result.routing << "\n";
    std::cout << std::string(60, '=') << "\n\n";

    return 0;
}
