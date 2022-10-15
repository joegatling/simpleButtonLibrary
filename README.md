# Very Simple Button Library
A simple button for PlatformIO projects. Designed to be as basic as possible.

# Getting Started
Include in your PlatformIO project using the following line in your **platformio.ini** file:
```
lib_deps = 
	joegatling/VerySimpleButton
```

Here is a very basic use example

```
#include <SimpleButton.h>

// Button is attached to pin 10.
// By default, this activate the internal pullup resistor on the pin.
// Your button should connect this pin to ground.
SimpleButton myButton(10);

void setup() 
{
    myButton.SetBeginPressCallback(onBeginPress);
    myButton.SetEndPressCallback(onEndPress);
    myBbutton.SetHoldCallback(onHold);
}

void loop()
{}

void onBeginPress()
{
  // Button has been pressed down
}

void onEndPress()
{
  // Button has been released (Assuming you didn't hold it down)
}

void onHold()
{
  // Button has been held down
}

```
