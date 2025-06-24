#ifndef LedRGB_h
#define LedRGB_h

class LedRgb {
public:
    uint8_t brightR_;
    uint8_t brightG_;
    uint8_t brightB_;

    LedRgb(uint8_t pinR, uint8_t pinG, uint8_t pinB);
	
    uint8_t checkBright(uint8_t& bright, int8_t diff);
    void setColorR(int8_t diff);
    void setColorG(int8_t diff);
    void setColorB(int8_t diff); 
private:
    uint8_t pinR_, pinG_, pinB_;
};



#endif // !LedRGB_h