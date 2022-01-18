#include <VirtualWire.h>
int i;
 
void setup() 
{
    Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_set_rx_pin(11);
    vw_rx_start();
}
 
void loop() 
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) 
    {
      Serial.print("Got: ");
      if(buf[1]=='2'){
        
      
      for ( i = 0; i < buflen; i++)
      {
        char ch = buf[i];
        Serial.print(ch);
        //Serial.print(' ');
      }
      Serial.println();
    }
        
      }
      
  }
