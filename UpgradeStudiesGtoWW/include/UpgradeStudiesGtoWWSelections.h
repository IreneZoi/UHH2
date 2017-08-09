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

class LowPtSelection: public uhh2::Selection {
public:
    LowPtSelection(float pt_min = 500.0f, float pt_max = 1500.0f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float pt_min, pt_max;
};

class MediumPtSelection: public uhh2::Selection {
public:
    MediumPtSelection(float pt_min = 1500.0f, float pt_max = 2500.0f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float pt_min, pt_max;
};

class HighPtSelection: public uhh2::Selection {
public:
    HighPtSelection(float pt_min = 2500.0f);
    virtual bool passes(const uhh2::Event & event) override;
private:
    float pt_min;
};


/* class DeltaRSelection: public uhh2::Selection { */
/* public: */
/*     DeltaRSelection(float deltaR_max = 0.4f); */
/*     virtual bool passes(const uhh2::Event & event) override; */
/* private: */
/*     float deltaR_max; */
/* }; */


}
