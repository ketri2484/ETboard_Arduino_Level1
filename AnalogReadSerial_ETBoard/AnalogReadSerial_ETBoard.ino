
void setup() {
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(A0);
// A0에 연결된 가변저항의 값을 저장합니다. 

Serial.println(sensorValue);
// 시리얼 모니터에 가변저항값을 보여줍니다.
delay(1);
}



//┌────────────────────────────────┐
//│                                                      │
//│     (주)한국공학기술연구원 http://et.ketri.re.kr         │
//│                                                      │ 
//└────────────────────────────────┘