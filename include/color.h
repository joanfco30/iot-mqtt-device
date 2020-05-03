#include <input_device.h>
#include <Arduino.h>

class color: public InputDevice {
private:
    uint8_t pin;
public:
    color(uint16_t device_id, uint16_t threshold, long sample_time): InputDevice(device_id, threshold, sample_rate) {};
    bool init(uint8_t pin);
    uint16_t read();
};

bool color::init(uint8_t pin){
    this->pin = pin;
}

uint16_t color::read(){
    float Color_1;
    Color_1= analogRead(this->pin);
    
 
    return(Color_1);
}