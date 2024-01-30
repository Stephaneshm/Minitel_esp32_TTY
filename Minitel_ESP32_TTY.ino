/*
 * There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.
 * 
 * U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
 * U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
 * U2UXD is unused and can be used for your projects.
 * 

*/

#define RXD1 4
#define TXD1 2
#define RXD2 16
#define TXD2 17


/*const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];
int inIndex;
int c;*/
void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(9600);
  Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1);
  Serial2.begin(1200, SERIAL_7E1, RXD2, TXD2);
  // Serial.println("Serial Txd is on pin: "+String(TX));
  // Serial.println("Serial Rxd is on pin: "+String(RX));
  //Serial1.print("__START__");
  Serial.print("__START__");
}

void loop() { //Choose Serial1 or Serial2 as required

   if ( Serial1.available()) // Check to see if at least one character is available
  {
    char ch = Serial1.read();
    //Serial.print(ch,HEX);
    if(ch=='é') ch='e';
    if(ch==0xC3) ch='E';
    if(ch >= 0x0A && ch <= 0x7A) // is this an ascii digit between 0 and 9?
    {
          Serial2.print(ch);
          Serial.print(ch);
    }
  }

     if ( Serial.available()) // Check to see if at least one character is available
  {
    char ch = Serial.read();
    Serial.print(ch,HEX);
    if(ch=='é') ch='e';
    if(ch==0xC3) ch='E';
    if(ch >= 0x0A && ch <= 0x7A) // is this an ascii digit between 0 and 9?
    {
          Serial2.print(ch);
    }
  }
  /*
if (Serial.available() > 0) {
    // read the incoming bytes:
    int rlen = Serial.readBytesUntil('\r', buf, BUFFER_SIZE);

    // prints the received data
    Serial2.print(buf);
    buf[]="";
  }
  /*
 if (Serial.available ()) {
    char c = Serial.read();
    if (c != ';') {
      buf[n++] = c;
    } else {

      }
      Serial2.println(buf);
  }



  /*
  if (Serial2.available()) {
    Serial.print(char(Serial2.read()));
  }

  if (Serial.available()) {
    Serial2.print(char(Serial.read()));
  }
*/


}