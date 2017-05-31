#include <SoftwareSerial.h>
#include <Bee.h>

// XBee's DOUT (TX) is connected to pin 0 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 1 (Arduino's Software TX)
SoftwareSerial Serial3(0, 1); // RX, TX

Bee XBee(&Serial3, 9600);

void setup() {
  Serial3.begin(9600);
  XBee.setCallback(beeCallback);
  XBee.begin();
  XBee.sendData("Hello world!");
}

void beeCallback(BeePointerFrame *frame) {
  Serial3.write(frame->data, frame->dataLength);
}

void loop() {
  XBee.tick();
  XBee.sendData("Hello world!");
  delay(1000); 
}
