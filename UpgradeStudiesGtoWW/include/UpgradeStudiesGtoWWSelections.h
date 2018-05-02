#pragma once

#include "UHH2/core/include/fwd.h"
#include "UHH2/core/include/Selection.h"

namespace uhh2examples {
    
/* Select events with at least two jets in which the leading two jets have deltaphi > 2.7 and the third jet pt is
 * below 20% of the average of the leading two jets, where the minimum deltaphi and
 * maximum third jet pt fraction can be changed in the constructor.
 * The jets are assumed to be sorted in pt.
 */
class DijetSelection: public uhh2::Selection {
public:
    DijetSelection(float dphi_min = 2.7f, float third_frac_max = 0.2f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float dphi_min, third_frac_max;
};


class SDMassSelection: public uhh2::Selection {
public:
    SDMassSelection(float Mass_sd_min = 65.0f, float Mass_sd_max = 105.0f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float Mass_sd_min, Mass_sd_max;
};

class PtSelection: public uhh2::Selection {
public:
    PtSelection(float pt_min = 700.0f, float pt_max = 1300.0f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float pt_min, pt_max;
};


class EtaBarrelSelection: public uhh2::Selection {
public:
    EtaBarrelSelection(float eta_max = 0.7f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float eta_max;
};

class EtaEndcapSelection: public uhh2::Selection {
public:
    EtaEndcapSelection(float eta_min = 1.9f, float eta_max = 2.4f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float eta_min, eta_max;
};


/* class DeltaRSelection: public uhh2::Selection { */
/* public: */
/*     DeltaRSelection(float deltaR_max = 0.4f); */
/*     virtual bool passes(const uhh2::Event & event) override; */
/* private: */
/*     float deltaR_max; */
/* }; */


}
