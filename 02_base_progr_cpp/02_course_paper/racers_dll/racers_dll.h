#pragma once
  #ifdef RACERS_MEMBERS_EXPORTS
    #define RACERS_DLL_API __declspec(dllexport) 
  #else
    #define RACERS_DLL_API __declspec(dllimport) 
  #endif

#include <string>

namespace racers_dll {
  
  //------------------------------------------------------------------
  class RacerBase {
    protected:
      std::string m_name;
      float velocity { 1 };
      float travelTime{ 0.0 };

    public:
      RacerBase() : m_name{ "Гонщик базовый" } {}
      ~RacerBase() {}

      RACERS_DLL_API std::string getName ();
  };


  //------------------------------------------------------------------
  class RacerGroundBase : public RacerBase {
  protected:
    unsigned int timeRest_1{ 0 };
    unsigned int timeRest_2{ 0 };
    unsigned int drivingTime{ 0 };

  public:
    RacerGroundBase() {
      m_name = "Гонщик базовый, наземный";
    }
    ~RacerGroundBase() {}

    RACERS_DLL_API virtual float getTime(unsigned int& m_distance);
  };

  ////------------------------------------------------------------------
  class RacerCamel: public RacerGroundBase {
   public:
     RacerCamel() {
       m_name = "Верблюд";
       velocity = 10.;
       timeRest_1 = 5;
       timeRest_2 = 8;
       drivingTime = 30;
     }
     ~RacerCamel() {}
     RACERS_DLL_API virtual float getTime(unsigned int& m_distance) override;
  };

  ////------------------------------------------------------------------
  class RacerBoots : public RacerCamel {
  public:
    RacerBoots() {
      m_name = "Ботинки-вездеходы";
      velocity = 6.;
      timeRest_1 = 10;
      timeRest_2 = 5;
      drivingTime = 60;
    }
    ~RacerBoots() {}
  };

  ////------------------------------------------------------------------
  class RacerCamelFast : public RacerGroundBase {
  protected:
    unsigned int timeRest_3{ 8 };
  public:
    RacerCamelFast() {
      m_name = "Верблюд-быстроход";
      velocity = 40.;
      timeRest_1 = 5;
      timeRest_2 = 6.5;
      drivingTime = 8;
    }
    ~RacerCamelFast() {}
    RACERS_DLL_API virtual float getTime(unsigned int& m_distance) override;
  };


  //------------------------------------------------------------------
  class RacerAirBase : public RacerBase {
  protected:
    float reductionRatio_1{ 1. };

  public:
    RacerAirBase() {
      m_name = "Гонщик базовый, воздушный";
    }
    ~RacerAirBase() {}
    RACERS_DLL_API virtual float getTime(unsigned int& m_distance, unsigned int& m_Ratio_1);
  };

  //------------------------------------------------------------------
  class RacerMagicCarpet : public RacerAirBase {
  protected:
    float reductionRatio_1{ 0.97 };
    float reductionRatio_2{ 0.9 };
    float reductionRatio_3{ 0.95 };

  public:
    RacerMagicCarpet() {
      m_name = "Ковер-самолет";
    }
    ~RacerMagicCarpet() {}
    RACERS_DLL_API virtual float getTime(unsigned int& m_distance);
  };












}

