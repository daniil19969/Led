void setup() 
{
  pinMode(13, OUTPUT);         
}


void loop() {
  delay(12280);
  digitalWrite(13, HIGH);    //загорается в 0:17:28
  delay(8000);                 
  digitalWrite(13, LOW);     //25 секунда  
  delay(3200); //20300
  digitalWrite(13, HIGH);  //28 секунда
  delay(27000);   
  digitalWrite(13, LOW);  //гаснет на 55,5
  delay(6500);  //не светиться до 1 минуты
  digitalWrite(13, HIGH); //загорается на 1:02 минуте
  delay (7500); //горит до 1:09:50
  digitalWrite(13, LOW);
  delay (100);
  digitalWrite(13, HIGH);
  delay (100);
  digitalWrite(13, LOW);
  delay (100);
  digitalWrite(13, HIGH);
  delay (100);
  digitalWrite(13, LOW);
  delay (100);
  digitalWrite(13, HIGH);
  delay (100);
  digitalWrite(13, LOW);
  delay (100);
  digitalWrite(13, HIGH);
  delay (100);
  digitalWrite(13, LOW);
  delay (100);
  digitalWrite(13, HIGH); //горит с 1:10:40 до 1:19
  delay (8600); 
  digitalWrite(13, LOW); //гаснет до 1:21:50
  delay (2500);
  digitalWrite(13, HIGH); //горит до 1:38
  delay (16500);
  digitalWrite(13, LOW); //выключается в 1:38 
  delay (15500);
  digitalWrite(13, HIGH); //включается в 1:53:50
  delay (22500); 
  digitalWrite(13, LOW); // горит до 2:16
  delay (3000);
  digitalWrite(13, HIGH); //включается в 2:19
  delay (15000); 
  digitalWrite(13, LOW); // выключается в 2:34
  delay (2000); 
  digitalWrite(13, HIGH); // включается в 2:36
  delay (6500); 
  digitalWrite(13, LOW); // выключается в 2:42:50 совсем
  delay (30000); 
}
