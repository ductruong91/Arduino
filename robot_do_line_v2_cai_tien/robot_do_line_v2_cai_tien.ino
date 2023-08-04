int stop_distance = 12;// Khoảng cách phát hiện vật cản
//Kết nối SRF 05 OR 04

// const int trigPin = 11; // kết nối chân trig với chân 11 arduino
// const int echoPin = 12; // kết nối chân echo với chân 12 arduino

//L298 kết nối arduino
const int motorA1      = 4;  // kết nối chân IN1 với chân 4 arduino
const int motorA2      = 5;  // kết nối chân IN2 với chân 5 arduino
const int motorAspeed  = 9;  // kết nối chân ENA với chân 9 arduino
const int motorB1      = 6; // kết nối chân IN3 với chân 6 arduino
const int motorB2      = 7; // kết nối chân IN4 với chân 7 arduino
const int motorBspeed  = 10;  // kết nối chân ENB với chân 10 arduino

//kết nối của 3 cảm biến hồng ngoại (dò line )
const int L_S = A0; // cb dò line phải
const int S_S = A2; // cb dò line giữa
const int R_S = A3; //cb dò line trái

int left_sensor_state;// biến lưu cảm biến hồng ngoại line trái
int s_sensor_state;   // biến lưu cảm biến hồng ngoại line giữa
int right_sensor_state;// biến lưu cảm biến hồng ngoại line phải

// long duration; //
// int distance;  // biến khoảng cách

// char doc_gia_tri; //biens này ghi kiểu char, dọc dữ liệu từ bluetopth


void setup() {

//  Serial.begin(9600);
//  mybluetooth.begin(9600);


  pinMode(L_S, INPUT); // chân cảm biến khai báo là đầu vào
  pinMode(R_S, INPUT);
  pinMode(S_S, INPUT);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorAspeed, OUTPUT);
  pinMode(motorBspeed, OUTPUT);

  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);

  Serial.begin(9600);

  analogWrite(motorAspeed, 80); // tốc độ động cơ a ban đầu 120 ( 0 - 255)
  analogWrite(motorBspeed, 80);// tốc độ động cơ b ban đầu 120 ( 0 - 255)
  delay(2000);

}

void loop() {
  // digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  // digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // duration = pulseIn(echoPin, HIGH);
  // distance = duration * 0.034 / 2;
  // Serial.print("Distance: ");
  // Serial.println(distance);

  left_sensor_state = digitalRead(L_S);
  s_sensor_state = digitalRead(S_S);
  right_sensor_state = digitalRead(R_S);

  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
    forword(); // đi tiến
  }

  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 0)) {
    turnLeft(); // rẻ trái
  }
  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 0)) {
    turnLeft(); // rẻ trái
  }

  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
    turnRight(); // rẻ phải
  }
  if ((digitalRead(L_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(R_S) == 1)) {
    turnRight(); // rẻ phải
  }

  if ((digitalRead(L_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(R_S) == 1)) {
    Stop(); // stop
  }



 

}

void forword() { // chương trình con xe robot đi tiến

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}


void turnRight() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnLeft() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void Stop() {

  digitalWrite (motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite (motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
