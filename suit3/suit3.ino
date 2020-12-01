void setup() 
{
  pinMode(13, OUTPUT);         
}


void loop() {
  delay(8500);
  digitalWrite(13, HIGH);    //загорается в 0:13:5
  delay(11780);                 
  digitalWrite(13, LOW);     //25 секунда  
  delay(3200); 
  digitalWrite(13, HIGH);  //28 секунда
  delay(16500); 
  digitalWrite(13, LOW); //45???
  delay(1000);
  digitalWrite(13, HIGH);  //47???
  delay(7500);  
  digitalWrite(13, LOW);  //гаснет на 54,5
  delay(7500);  //не светиться до 1: минуты
  digitalWrite(13, HIGH); //загорается на 1 минуте
  delay (8500); //горит до 1:09:50
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
  digitalWrite(13, LOW); //гаснет до 1:21:50++++++
  delay (19000);
  digitalWrite(13, HIGH); //включается в 1:38
  delay (3500);
  digitalWrite(13, LOW); //выключается в 1:41:50 
  delay (4500);
  digitalWrite(13, HIGH); //включается в 1:46
  delay (30000); 
  digitalWrite(13, LOW); // горит до 2:16
  delay (6500);
  digitalWrite(13, HIGH); //включается в 2:22:50
  delay (1000);
  digitalWrite(13, LOW);//выключается в 2:23:50
  delay (1000);
  digitalWrite(13, HIGH); //включается в 2:24:50
  delay (9500); 
  digitalWrite(13, LOW); // выключается в 2:34
  delay (2000); 
  digitalWrite(13, HIGH); // включается в 2:36
  delay (10000); 
  digitalWrite(13, LOW); // выключается в 2:46 совсем
  delay (30000); 
}
