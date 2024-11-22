#include "racers_dll.h"

namespace racers_dll {

  std::string RacerBase::getName() {
    return m_name;
  }

  float RacerGroundBase::getTime (unsigned int& m_distance) {
    travelTime = m_distance / velocity;
    return travelTime;
  }

  float RacerCamel::getTime(unsigned int& m_distance) {
    unsigned int numberDrivingTime { 0 };
    travelTime = RacerGroundBase::getTime (m_distance);
    numberDrivingTime = travelTime / drivingTime;
    for (unsigned int i = 0; i < numberDrivingTime; i++) {
      if (i == 0) {
        travelTime += timeRest_1;
      }
      else {
        travelTime += timeRest_2;
      }
    }   
    return travelTime;
  }

  float RacerCamelFast::getTime(unsigned int& m_distance) {
    unsigned int numberDrivingTime{ 0 };
    travelTime = RacerGroundBase::getTime(m_distance);
    numberDrivingTime = travelTime / drivingTime;
    for (unsigned int i = 0; i < numberDrivingTime; i++) {
      if (i == 0) {
        travelTime += timeRest_1;
      }
      else if (i == 1) {
        travelTime += timeRest_2;
      }
      else {
        travelTime += timeRest_3;
      }
    }
    return travelTime;
  }

  float RacerAirBase::getTime(unsigned int& m_distance, unsigned int& m_Ratio_1) {
    travelTime = (m_distance * m_Ratio_1) / velocity;
    return travelTime;
  }

  float RacerMagicCarpet::getTime(unsigned int& m_distance) {
    if (m_distance < 1000) {
      travelTime = (m_distance * reductionRatio_1) / velocity;
    }


    
    return travelTime;
  }










}