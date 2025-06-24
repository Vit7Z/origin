#ifdef Button_h
#define Button_h

//----------------------------------------------
class Button {
  public:
    bool currentState_;
    bool lastState_;
    Button (uint8_t pin); 
    void scanState();

  private:
    uint8_t pin_;
};

#endif