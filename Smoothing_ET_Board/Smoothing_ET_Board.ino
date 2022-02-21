
const int numReadings = 10;

int readings[numReadings];      // 아날로그 값 읽은 것을 저장하는 배열
int readIndex = 0;              // 읽는 순번
int total = 0;                  // 10개 값의 총합
int average = 0;                // 10개 값의 평균

int inputPin = A0; // 가변저항(아날로그) : A0

void setup() {
  Serial.begin(9600);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {  // 읽는 배열 값들을 0으로 초기화
    readings[thisReading] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];         // 가장 오래된 값을 빼줌
  readings[readIndex] = analogRead(inputPin);  // 센서 값을 읽어옴
  total = total + readings[readIndex];         // 읽어온 값을 총합에 더해줌
  readIndex = readIndex + 1;                   // 배열에서 다음 순번으로 처리하기 위해 차례를 넘김

  if (readIndex >= numReadings) {  // 배열 값이 지정된 값보다 커지면
    readIndex = 0;                 // 처음 배열 값으로 돌아감
  }

  average = total / numReadings; // 평균값 계산
  Serial.println(average);
  delay(1);                      // 1ms 기다리기
}



//┌────────────────────────────────┐
//│                                                      │
//│     (주)한국공학기술연구원 http://et.ketri.re.kr         │
//│                                                      │ 
//└────────────────────────────────┘