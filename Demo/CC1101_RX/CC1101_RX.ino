 #include <ELECHOUSE_CC1101.h>
 
 void setup()
{
  Serial.begin(9600);
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.SetReceive();
}

byte RX_buffer[61]={0};
byte size,i,flag;
byte rssi1, rssi2;

void loop()
{
  if(ELECHOUSE_cc1101.CheckReceiveFlag())
  {
    size=ELECHOUSE_cc1101.ReceiveData(RX_buffer);
    rssi1 = ELECHOUSE_cc1101.SpiReadReg(0x34);
    rssi2 = ELECHOUSE_cc1101.SpiReadReg(0xF4);
    for(i=0;i<size;i++)
    {
      Serial.print(RX_buffer[i],DEC);      
      Serial.print(' ');
    }
    Serial.println("");
    Serial.print(rssi1, DEC);
    Serial.println("");
    Serial.print(rssi2, DEC);
    Serial.println("");
    ELECHOUSE_cc1101.SetReceive();
  }
}

