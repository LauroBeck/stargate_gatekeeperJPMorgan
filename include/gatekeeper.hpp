#ifndef GATEKEEPER_HPP
#define GATEKEEPER_HPP

#include <string>
#include <vector>

namespace stargate {

struct CustodyAsset {
    std::string client_name;
    double aum_bn;
    double collateral_ratio; // Target 1.2 (120%)
};

struct CustodyReport {
    std::string client;
    double annual_fee_m;
    std::string status;
    double risk_factor;
};

class BNYEngine {
public:
    const double CUSTODY_FEE_BPS = 2.5; // 2.5 basis points

    CustodyReport audit_custody(const CustodyAsset& asset) {
        CustodyReport report;
        report.client = asset.client_name;
        
        // Fee = AUM * 0.00025
        report.annual_fee_m = (asset.aum_bn * 1000.0) * (CUSTODY_FEE_BPS / 10000.0);
        
        report.risk_factor = 1.5 - asset.collateral_ratio;
        
        if (asset.collateral_ratio < 1.1) report.status = "MARGIN_CALL_REQUIRED";
        else if (asset.collateral_ratio < 1.2) report.status = "WATCHLIST";
        else report.status = "SECURE_ASSET_BACKED";
        
        return report;
    }
};

} 
#endif
