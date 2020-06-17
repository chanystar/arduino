// 스위치 버튼 클릭시 1초마다 0부터 9까지 반복 표시하는 세그먼트 LED


int leds[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 세그먼트 핀번호 설정{2=a, 3=b, 4=c, 5=d, 6=e, 7=f, 8=g, 9=dp(도트 발광부 : 데시멀 포인트)}
int led_num = 8; // 7세그먼트 led
int button = 13;        // 스위치 핀번호
int num = 0;            // 세그먼트 숫자표시를 위한 변수 설정

int set_number[10][8] = {  // LED 설정 값을 정의(.
  {0, 0, 0, 0, 0, 0, 1, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0, 1}, // 2
  {0, 0, 0, 0, 1, 1, 0, 1}, // 3
  {1, 0, 0, 1, 1, 0, 0, 1}, // 4
  {0, 1, 0, 0, 1, 0, 0, 1}, // 5
  {0, 1, 0, 0, 0, 0, 0, 1}, // 6
  {0, 0, 0, 1, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0, 1}, // 8
  {0, 0, 0, 0, 1, 0, 0, 1}  // 9
};

void setup() {
  for (int i = 0 ; i < led_num ; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);  // 스위치 풀업
}

void loop() {

  if (digitalRead(button) == LOW) {
    for (int j = 1; j > 0; j++) {
      for (int i = 0; i < 10; i++) {
        segNum();
        delay(1000);
        num++;
      }
      num = 0;
    }
  }
}

void segNum() {
  for (int i = 0 ; i < led_num ; i++) {     
    digitalWrite(leds[i], set_number[num][i]);
  }
}






