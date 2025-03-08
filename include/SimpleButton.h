#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

#include <Arduino.h>

extern "C" {
typedef void (*simpleButtonCallbackFunction)(void);
}


class SimpleButton
{
  public:
    SimpleButton(int pin);
    SimpleButton(int pin, bool usePullDownLogic);

    void Update();

    void SetBeginPressCallback(simpleButtonCallbackFunction function);
    void SetEndPressCallback(simpleButtonCallbackFunction function);
    
    void SetBeginHoldCallback(simpleButtonCallbackFunction function);
    void SetEndHoldCallback(simpleButtonCallbackFunction function);

    void SetLongPressDuration(unsigned long duration);

    bool IsButtonDown();
    bool IsButtonUp() { return !IsButtonDown(); }

  private:
    int _pin;

    int _buttonState;
    int _lastPinReading;

    unsigned long _debounceTime;
    unsigned long _pressedTime;   

    unsigned long _longPressDuration;

    bool _didHoldAction = false;

    bool _usePullDownLogic = false;

    simpleButtonCallbackFunction _beginPressFunction = NULL;
    simpleButtonCallbackFunction _endPressFunction = NULL;
    simpleButtonCallbackFunction _beginHoldFunction = NULL;
    simpleButtonCallbackFunction _endHoldFunction = NULL;
    
};

#endif // SIMPLE_BUTTON_H
