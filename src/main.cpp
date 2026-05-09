#include <iostream>
#include <vector>
#include <iomanip>
#include "gatekeeper.hpp"

int main() {
    stargate::BNYEngine engine;
    
    std::vector<stargate::CustodyAsset> custody_vault = {
        {"HSBC GLOBAL CORP", 120.0, 1.25},  // $120BN AUM, 125% Collateral
        {"WELLS FARGO APORT", 52.3, 1.18},  // $52.3BN AUM, 118% Collateral
        {"JPM ALPHA FUND", 15.0, 1.05},     // $15BN AUM, 105% Collateral (Risky)
        {"STARGATE BRAZIL", 8.5, 1.40}      // $8.5BN AUM, 140% Collateral
    };

    std::cout << "\n" << std::string(85, '=') << "\n";
    std::cout << " BNY MELLON CUSTODY & ASSET SERVICING: GLOBAL AUDIT (MAY 2026)\n";
    std::cout << std::string(85, '-') << "\n";
    std::cout << std::left << std::setw(20) << "CLIENT ENTITY" 
              << std::setw(15) << "AUM ($BN)" 
              << std::setw(15) << "ANNUAL FEE($M)" 
              << "CUSTODY STATUS\n";
    std::cout << std::string(85, '-') << "\n";

    for (const auto& asset : custody_vault) {
        auto report = engine.audit_custody(asset);
        
        std::cout << std::left << std::setw(20) << report.client 
                  << "$" << std::setw(14) << std::fixed << std::setprecision(2) << asset.aum_bn
                  << "$" << std::setw(14) << report.annual_fee_m
                  << report.status << "\n";
    }
    
    std::cout << std::string(85, '=') << "\n";
    std::cout << "BNY MELLON SYSTEM STATUS: 100% ASSET RECONCILIATION COMPLETE\n";
    std::cout << "LOCATION: RIO/NYC SECURE LINK OPERATIONAL\n";
    std::cout << std::string(85, '=') << "\n\n";

    return 0;
}
