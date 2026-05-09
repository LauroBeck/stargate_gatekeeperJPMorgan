#include <iostream>
#include <vector>
#include <iomanip>
#include "gatekeeper.hpp"

int main() {
    stargate::DigitalBNYEngine engine;
    
    // Simulating BNY Mellon's Digital Asset ETF Administration
    std::vector<stargate::DigitalAsset> crypto_vault = {
        {"BTC", 550000.0, 98500.00, 99.8},  // 550k BTC in Spot ETFs
        {"ETH", 2100000.0, 4200.00, 98.5},  // 2.1M ETH in Staking/Admin
        {"SOL", 15000000.0, 245.00, 92.0}   // 15M SOL - Failed Security Check
    };

    std::cout << "\n" << std::string(90, '=') << "\n";
    std::cout << " BNY MELLON DIGITAL ASSET CUSTODY: ETF ADMINISTRATION PORTAL (MAY 2026)\n";
    std::cout << std::string(90, '-') << "\n";
    std::cout << std::left << std::setw(10) << "TICKER" 
              << std::setw(18) << "VAULT VALUE($BN)" 
              << std::setw(30) << "SECURITY STATUS" 
              << "COMPLIANCE NOTE\n";
    std::cout << std::string(90, '-') << "\n";

    for (const auto& crypto : crypto_vault) {
        auto audit = engine.audit_digital_vault(crypto);
        
        std::cout << std::left << std::setw(10) << audit.ticker 
                  << "$" << std::fixed << std::setprecision(2) << std::setw(17) << audit.vault_value_bn
                  << std::setw(30) << audit.security_status
                  << audit.compliance_note << "\n";
    }
    
    std::cout << std::string(90, '=') << "\n";
    std::cout << "VAULT LOCATION: MULTI-SIG SHARDED HSM (NYC/LDN/RIO)\n";
    std::cout << "SYSTEM STATUS: 24/7 ON-CHAIN RECONCILIATION ACTIVE\n";
    std::cout << std::string(90, '=') << "\n\n";

    return 0;
}
