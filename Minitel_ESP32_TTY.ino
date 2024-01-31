

#define RXD1 4
#define TXD1 2
#define RXD2 16
#define TXD2 17

//defines
#define BUFF_SIZE       5000

//variables
uint8_t grBuffer[BUFF_SIZE];
uint16_t tailIndex,headIndex;
  

void setup() {

  Serial.begin(9600);
  Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1);
  Serial2.begin(4800, SERIAL_7E1, RXD2, TXD2);
  Serial.print("__START__");
}

void loop() { //Choose Serial1 or Serial2 as required
        ReceiveData();
        if( tailIndex != headIndex )
        {
            Serial.print(tailIndex);Serial.print('/');Serial.println(headIndex);
            for (int i = 0; i <= 10; i++) 
            {
               
               if (tailIndex != headIndex )  {            
               Serial2.write( grBuffer[tailIndex]);
               tailIndex++;
               if( tailIndex == BUFF_SIZE && tailIndex > headIndex )   tailIndex = 0;
               }
               
            } 
        }

}



void ReceiveData( void )
{
    if( Serial1.available() > 0 )
    {
        do
        {
            //read the character
            uint8_t ch = Serial1.read();
            if(ch=='é') ch='e';
            if(ch==0xC3) ch='e';
            if(ch==0x0A) grBuffer[headIndex] = ch;
            if(ch==0x0D) grBuffer[headIndex] = ch;
            if(ch >= 0x20 && ch <= 0x7A) // is this an ascii digit between 0 and 9?
            {
              grBuffer[headIndex] = ch;
            }

            headIndex++;
            if( headIndex == BUFF_SIZE )
                headIndex = 0;
            
        }while( Serial1.available() > 0 );
        
    }//if
}//ReceiveData