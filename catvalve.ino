unsigned long lastRelease = millis();
unsigned long hour = 3600000;

void openValve(int time) {
        Serial.write("valve_opened");
        digitalWrite(13, HIGH);
        delay(time);
        digitalWrite(13, LOW);
        Serial.write("valve_closed");
        lastRelease = millis();
}
void setup()
{
  // 设置波特率为 38400
  Serial.begin(38400);
  pinMode(13, OUTPUT);
}
 
 
void loop()
{
  if(millis() - lastRelease > hour) {
    openValve(5000);
  }
  if(Serial.available())
  {
    char c=Serial.read();
      if(c=='1')
      {
        Serial.println("BT is ready!");
        // 返回到手机调试程序上
        openValve(5000);
      }
     if(c=='2')
     {
       Serial.write("Serial--13--low");
       digitalWrite(13, LOW);
     }
  }
}

