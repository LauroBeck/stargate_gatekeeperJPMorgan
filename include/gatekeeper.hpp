#ifndef GATEKEEPER_HPP
#define GATEKEEPER_HPP

#include <string>
#include <vector>

namespace stargate {

struct DigitalAsset {
    std::string ticker;
    double quantity;
    double spot_price;
    double cold_storage_pct; // Target > 98% for institutional
};

struct DigitalAudit {
    std::string ticker;
    double vault_value_bn;
    std::string security_status;
    std::string compliance_note;
};

class DigitalBNYEngine {
public:
    DigitalAudit audit_digital_vault(const DigitalAsset& asset) {
        DigitalAudit audit;
        audit.ticker = asset.ticker;
        audit.vault_value_bn = (asset.quantity * asset.spot_price) / 1e9;
        
        if (asset.cold_storage_pct < 98.0) {
            audit.security_status = "CRITICAL_RISK_HOT_WALLET_EXPOSURE";
            audit.compliance_note = "REBALANCE TO COLD STORAGE IMMEDIATELY";
        } else {
            audit.security_status = "INSTITUTIONAL_GRADE_SECURE";
            audit.compliance_note = "SEC_RULE_15c3_3_COMPLIANT";
        }
        
        return audit;
    }
};

} 
#endif
