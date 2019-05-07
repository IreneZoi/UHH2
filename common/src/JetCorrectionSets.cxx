#include "UHH2/common/include/JetCorrectionSets.h"
#include <string>

//see https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookJetEnergyCorrections#GetTxtFiles how to get the txt files with jet energy corrections from the database

// The idea of the following methods is to simplify the creation of new JEC input files.
const std::string JERFiles::JECPathStringMC(const std::string & tag, const std::string & ver, const std::string & jetCollection, const std::string & Correction) {
  std::string result = "JECDatabase/textFiles/";
  result += tag;
  std::string verPrefix = (tag.find("Summer16_23Sep2016") != std::string::npos) ? "V" : "_V"; // because someone decided to remove the underscore in Summer16_23Sep2016
  result += verPrefix;
  result += ver;
  result += "_MC/";
  result += tag;
  result += verPrefix;
  result += ver;
  result += "_MC_";
  result += Correction;
  result += "_";
  result += jetCollection;
  result += ".txt";
  return result;
}

const std::vector<std::string> JERFiles::JECFiles_MC(const std::string & tag, const std::string & ver, const std::string & jetCollection, const std::vector<std::string> levels) {
  std::vector<std::string> result;
  for (const auto & level : levels){
    result.push_back(JERFiles::JECPathStringMC(tag, ver, jetCollection, level));
  }
  return result;
}

const std::string JERFiles::JECPathStringData(const std::string & tag, const std::string & ver, const std::string & jetCollection, const std::string & runName, const std::string & Correction) {
  std::string newRunName = runName;
  // in 2018 they use "_RunA" instead of just "A"
  if (tag.find("18") != std::string::npos) {
    newRunName = "_Run" + runName;
  }
  std::string result = "JECDatabase/textFiles/";
  result += tag;
  result += newRunName;
  std::string verPrefix = (tag.find("Summer16_23Sep2016") != std::string::npos) ? "V" : "_V"; // because someone decided to remove the underscore in Summer16_23Sep2016
  result += verPrefix;
  result += ver;
  result += "_DATA/";
  result += tag;
  result += newRunName;
  result += verPrefix;
  result += "_DATA_";
  result += Correction;
  result += "_";
  result += jetCollection;
  result += ".txt";
  return result;
}

const std::vector<std::string> JERFiles::JECFiles_DATA(const std::string & tag, const std::string & ver, const std::string & runName, const std::string & jetCollection, const std::vector<std::string> levels) {
  std::vector<std::string> result;
  for (const auto & level : levels){
    result.push_back(JERFiles::JECPathStringData(tag, ver, jetCollection, runName, level));
  }
  return result;
}

const std::vector<std::string> JERFiles::L1L2L3 = {"L1FastJet", "L2Relative", "L3Absolute"};
const std::vector<std::string> JERFiles::L1L2L3Residual = {"L1FastJet", "L2Relative", "L3Absolute", "L2L3Residual"};


// have to use these, cannot use #tag, etc as it is inside another directive and will fail to compile
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define SET_JECFILES_MC(tag,ver,jetCollection)					                                          \
const std::vector<std::string> JERFiles::tag##_V##ver##_L123_##jetCollection##_MC =               \
  JERFiles::JECFiles_MC(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), JERFiles::L1L2L3);                   \
const std::vector<std::string> JERFiles::tag##_V##ver##_L1RC_##jetCollection##_MC =               \
  JERFiles::JECFiles_MC(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), {"L1RC"});                   \
const std::vector<std::string> JERFiles::tag##_V##ver##_L1FastJet_##jetCollection##_MC =          \
  JERFiles::JECFiles_MC(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), {"L1FastJet"});                   \

#define SET_CORRECTION_DATA(tag,ver,jetCollection,runName,runCorrection)                                  \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L123_##jetCollection##_DATA =         \
  JERFiles::JECFiles_DATA(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), TOSTRING(runCorrection), JERFiles::L1L2L3Residual); \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L123_noRes_##jetCollection##_DATA =   \
  JERFiles::JECFiles_DATA(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), TOSTRING(runCorrection), JERFiles::L1L2L3); \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L1RC_##jetCollection##_DATA =         \
  JERFiles::JECFiles_DATA(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), TOSTRING(runCorrection), {"L1RC"}); \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L1FastJet_##jetCollection##_DATA =    \
  JERFiles::JECFiles_DATA(TOSTRING(tag), TOSTRING(ver), TOSTRING(jetCollection), TOSTRING(runCorrection), {"L1FastJet"}); \


#define SET_JECFILES_DATA_2016(tag,ver,jetCollection) \
SET_CORRECTION_DATA(tag,ver,jetCollection,B,BCD)      \
SET_CORRECTION_DATA(tag,ver,jetCollection,C,BCD)      \
SET_CORRECTION_DATA(tag,ver,jetCollection,D,BCD)      \
SET_CORRECTION_DATA(tag,ver,jetCollection,E,EF)       \
SET_CORRECTION_DATA(tag,ver,jetCollection,F,EF)       \
SET_CORRECTION_DATA(tag,ver,jetCollection,G,GH)       \
SET_CORRECTION_DATA(tag,ver,jetCollection,H,GH)       \


#define SET_JECFILES_DATA_2017(tag,ver,jetCollection) \
SET_CORRECTION_DATA(tag,ver,jetCollection,B,B)        \
SET_CORRECTION_DATA(tag,ver,jetCollection,C,C)        \
SET_CORRECTION_DATA(tag,ver,jetCollection,D,DE)       \
SET_CORRECTION_DATA(tag,ver,jetCollection,E,DE)       \
SET_CORRECTION_DATA(tag,ver,jetCollection,F,F)        \


#define SET_JECFILES_DATA_2018(tag,ver,jetCollection) \
SET_CORRECTION_DATA(tag,ver,jetCollection,A,A)   \
SET_CORRECTION_DATA(tag,ver,jetCollection,B,B)   \
SET_CORRECTION_DATA(tag,ver,jetCollection,C,C)   \
SET_CORRECTION_DATA(tag,ver,jetCollection,D,D)   \


/* Here we create the new vectors. The usage is the following:
SET_JECFILES_*( a tag to identify which JEC use ,version, jet collection used)
*/
SET_JECFILES_MC(Summer16_07Aug2017,11,AK4PFchs)
SET_JECFILES_MC(Summer16_07Aug2017,11,AK4PFPuppi)
SET_JECFILES_MC(Summer16_07Aug2017,11,AK8PFchs)
SET_JECFILES_MC(Summer16_07Aug2017,11,AK8PFPuppi)
SET_JECFILES_MC(Summer16_07Aug2017,20,AK4PFchs)

SET_JECFILES_DATA_2016(Summer16_07Aug2017,11,AK4PFchs)
SET_JECFILES_DATA_2016(Summer16_07Aug2017,11,AK4PFPuppi)
SET_JECFILES_DATA_2016(Summer16_07Aug2017,11,AK8PFchs)
SET_JECFILES_DATA_2016(Summer16_07Aug2017,11,AK8PFPuppi)
SET_JECFILES_DATA_2016(Summer16_07Aug2017,20,AK4PFchs)

SET_JECFILES_MC(Fall17_17Nov2017,32,AK4PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK4PFPuppi)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK8PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK8PFPuppi)
SET_JECFILES_DATA_2017(Fall17_17Nov2017,32,AK4PFchs)
SET_JECFILES_DATA_2017(Fall17_17Nov2017,32,AK4PFPuppi)
SET_JECFILES_DATA_2017(Fall17_17Nov2017,32,AK8PFchs)
SET_JECFILES_DATA_2017(Fall17_17Nov2017,32,AK8PFPuppi)
//SET_JECFILES_DATA_2017(Fall17_09May2018,3,AK4PFchs)


SET_JECFILES_MC(Autumn18,8,AK4PFchs)
SET_JECFILES_MC(Autumn18,8,AK4PFPuppi)
SET_JECFILES_MC(Autumn18,8,AK8PFchs)
SET_JECFILES_MC(Autumn18,8,AK8PFPuppi)

SET_JECFILES_DATA_2018(Autumn18,8,AK4PFchs)
SET_JECFILES_DATA_2018(Autumn18,8,AK4PFPuppi)
SET_JECFILES_DATA_2018(Autumn18,8,AK8PFchs)
SET_JECFILES_DATA_2018(Autumn18,8,AK8PFPuppi)


SET_JECFILES_MC(Autumn18,4,AK4PFchs)
SET_JECFILES_MC(Autumn18,4,AK4PFPuppi)
SET_JECFILES_MC(Autumn18,4,AK8PFchs)
SET_JECFILES_MC(Autumn18,4,AK8PFPuppi)

SET_JECFILES_DATA_2018(Autumn18,4,AK4PFchs)
SET_JECFILES_DATA_2018(Autumn18,4,AK4PFPuppi)
SET_JECFILES_DATA_2018(Autumn18,4,AK8PFchs)
SET_JECFILES_DATA_2018(Autumn18,4,AK8PFPuppi)

SET_JECFILES_MC(Autumn18,7,AK4PFchs)
SET_JECFILES_MC(Autumn18,7,AK4PFPuppi)
SET_JECFILES_MC(Autumn18,7,AK8PFchs)
SET_JECFILES_MC(Autumn18,7,AK8PFPuppi)

SET_JECFILES_DATA_2018(Autumn18,7,AK4PFchs)
SET_JECFILES_DATA_2018(Autumn18,7,AK4PFPuppi)
SET_JECFILES_DATA_2018(Autumn18,7,AK8PFchs)
SET_JECFILES_DATA_2018(Autumn18,7,AK8PFPuppi)

