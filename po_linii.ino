#include <Wire.h>
#define UCHAR unsigned char
#define POROG 100
#define POROG_0_SENSOR 180
#define POROG_10_SENSOR 20
#define DELAY_TIME 5
#define ROTATE_TIME 550
#define VOZVRAT_TIME 999
#define PODIEZD_TIME 400
UCHAR t;


#define sensorOut A3
#define WHITE 0
#define BLACK 1
#define first_color WHITE //BLACK


// connect motor controller pins to Arduino digital pins
// motor one
int EnA_PP = 9;   //blue
int in1_PP = 46;
int in2_PP = 48;
int EnB_PL = 8;
int in3_PL = 18;
int in4_PL = 44;


int EnA_SL = 12;   //yelow
int in1_SL = 36;
int in2_SL = 4;
int EnB_SP = 7;
int in3_SP = 50;
int in4_SP = 6;

int EnA_ZP = 10 ;  //red
int in1_ZP = 16;
int in2_ZP = 17;
int EnB_ZL = 11;
int in3_ZL = 14;
int in4_ZL = 15;

//int rSpeed = GET_R_SPEED();

UCHAR data[16];



int R_SPEED[8] = {110,  115,  120,  130, 130, 0,    0,    0};
int L_SPEED[8] = {0,    0,    0,    130, 130, 120,  115,  110};

int current_color = first_color;

/*boolean isCorrectCube () {
  int redFrequency;
  int greenFrequency;
  int blueFrequency;*/

/* digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // считываем выходную частоту:
  redFrequency = pulseIn(sensorOut, LOW);

  //печатаем данные от фотодиодов с красным фильтром:
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);

  // настраиваем датчик таким образом, чтобы считывать данные
  // с фотодиодов с зеленым фильтром:
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // считываем выходную частоту:
  greenFrequency = pulseIn(sensorOut, LOW);

  //печатаем данные от фотодиодов с зеленым фильтром:
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);

  // настраиваем датчик таким образом, чтобы считывать данные
  // с фотодиодов с синим фильтром:
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // считываем выходную частоту:
  blueFrequency = pulseIn(sensorOut, LOW);

  // печатаем данные от фотодиодов с синим фильтром:
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  delay(100); */



boolean _0_LINE() {
  return (data[0] < POROG_0_SENSOR);
}
boolean _2_LINE() {
  return (data[2] < POROG);
}
boolean _4_LINE() {
  return (data[4] < POROG);
}
boolean _6_LINE() {
  return (data[6]  < POROG);
}
boolean _8_LINE() {
  return (data[8] < POROG);
}
boolean _10_LINE() {
  return (data[10] < POROG_10_SENSOR);
}
boolean _12_LINE() {
  return (data[12] < POROG);
}
boolean _14_LINE() {
  return (data[14] < POROG);
}

int GET_L_SPEED() {

  if ((_0_LINE()) && (_2_LINE()) && (_4_LINE()) && (_6_LINE()))
    return L_SPEED[0];
  if ((_0_LINE()) && (_2_LINE()) && (_4_LINE()))
    return L_SPEED[0];
  if ((_0_LINE()) && (_2_LINE()) && (_4_LINE()) && (_6_LINE()) && (_8_LINE()))
    return L_SPEED[0];
  if ((_12_LINE()) && (_14_LINE()))
    return L_SPEED[7];
  if ((_10_LINE()) && (_12_LINE()) && (_14_LINE()))
    return L_SPEED[7];
  if ((_10_LINE()) && (_12_LINE()) && (_14_LINE()) && (_8_LINE()))
    return L_SPEED[7];
  if ((_10_LINE()) && (_12_LINE()) && (_14_LINE()) && (_8_LINE()) && (_6_LINE()))
    return L_SPEED[7];
  if (_6_LINE())
    return L_SPEED[3];
  if (_8_LINE())
    return L_SPEED[4];
  if (_10_LINE())
    return L_SPEED[5];
  if (_4_LINE())
    return L_SPEED[2];
  if (_12_LINE())
    return L_SPEED[6];
  if (_2_LINE())
    return L_SPEED[1];
  if (_14_LINE())
    return L_SPEED[7];
  if (_0_LINE())
    return L_SPEED[0];
}
int GET_R_SPEED() {

  if ((_0_LINE()) && (_2_LINE()) && (_4_LINE()) && (_6_LINE()))
    return R_SPEED[0];
  if ((_0_LINE()) && (_2_LINE()) && (_4_LINE()))
    return R_SPEED[0];
  if ((_0_LINE()) && (_2_LINE()) && (_4_LINE()) && (_6_LINE()) && (_8_LINE()))
    return R_SPEED[0];
  if ((_12_LINE()) && (_14_LINE()))
    return R_SPEED[7];
  if ((_10_LINE()) && (_12_LINE()) && (_14_LINE()))
    return R_SPEED[7];
  if ((_10_LINE()) && (_12_LINE()) && (_14_LINE()) && (_8_LINE()) && (_6_LINE()))
    return R_SPEED[0];
  if (_6_LINE())
    return R_SPEED[3];
  if (_8_LINE())
    return R_SPEED[4];
  if (_10_LINE())
    return R_SPEED[5];
  if (_4_LINE())
    return R_SPEED[2];
  if (_12_LINE())
    return R_SPEED[6];
  if (_2_LINE())
    return R_SPEED[1];
  if (_14_LINE())
    return R_SPEED[7];
  if (_0_LINE())
    return R_SPEED[0];
}
void setup() {
/*  analogWrite(EnA_PP, 150);
  analogWrite(EnB_PL, 150);
  analogWrite(EnA_SL, 150);
  analogWrite(EnB_SP, 150);
  analogWrite(EnA_ZP, 150);
  analogWrite(EnB_ZL, 150);*/
  // myservo.attach(9);
  //  myservo.write(10);

  // pinMode(S0, OUTPUT);
  // pinMode(S1, OUTPUT);
  // pinMode(S2, OUTPUT);
  // pinMode(S3, OUTPUT);

  // pinMode(sensorOut, INPUT);

  // задаем масштабирование частоты на 20%:
  //digitalWrite(S0, HIGH);
  //digitalWrite(S1, LOW);

  // запускаем последовательную коммуникацию:
  //Serial.begin(9600);

  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  t = 0;

  // set all the motor control pins to outputs

  pinMode(EnA_PP, OUTPUT);
  pinMode(EnB_PL, OUTPUT);
  pinMode(EnA_SL, OUTPUT);
  pinMode(EnB_SP, OUTPUT);
  pinMode(EnA_ZP, OUTPUT);
  pinMode(EnB_ZL, OUTPUT);

  pinMode(in3_PL, OUTPUT);
  pinMode(in4_PL, OUTPUT);
  pinMode(in1_SL, OUTPUT);
  pinMode(in2_SL, OUTPUT);
  pinMode(in3_ZL, OUTPUT);
  pinMode(in4_ZL, OUTPUT);

  pinMode(in1_PP, OUTPUT);
  pinMode(in2_PP, OUTPUT);
  pinMode(in3_SP, OUTPUT);
  pinMode(in4_SP, OUTPUT);
  pinMode(in1_ZP, OUTPUT);
  pinMode(in2_ZP, OUTPUT);

  // выез за линию старта
  /*digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite (enA, 120);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (enB, 120);
    delay(800);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    // myservo.write(60);
    //delay (3000); */

  // следование линии

  Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
  while (Wire.available())   // slave may send less than requested
  {
    data[t] = Wire.read(); // receive a byte as character
    if (t < 15)
      t++;
    else
      t = 0;
  }

  while (!((_4_LINE()) && (_10_LINE()))) {
    //  myservo.write(90);
    Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
    while (Wire.available())   // slave may send less than requested
    {
      data[t] = Wire.read(); // receive a byte as character
      if (t < 15)
        t++;
      else
        t = 0;
    }





    digitalWrite(in1_SL, HIGH);
    digitalWrite(in2_SL, LOW);
    digitalWrite(in1_PP, HIGH);
    digitalWrite(in2_PP, LOW);
    digitalWrite(in1_ZP, LOW);
    digitalWrite(in2_ZP, HIGH);

    analogWrite(EnA_SL, GET_R_SPEED());
    analogWrite(EnA_PP, GET_R_SPEED());
    analogWrite(EnA_ZP, GET_R_SPEED());

    digitalWrite(in3_PL, HIGH);
    digitalWrite(in4_PL, LOW);
    digitalWrite(in3_ZL, LOW);
    digitalWrite(in4_ZL, HIGH);
    digitalWrite(in3_SP, HIGH);
    digitalWrite(in4_SP, LOW);

    analogWrite(EnB_PL, GET_L_SPEED());
    analogWrite(EnB_ZL, GET_L_SPEED());
    analogWrite(EnB_SP, GET_L_SPEED());
    //  analogWrite(enB, GET_L_SPEED());
    // analogWrite(enB, 200);

    delay(DELAY_TIME);

    digitalWrite(in1_SL, LOW);
    digitalWrite(in2_SL, LOW);
    digitalWrite(in1_PP, LOW);
    digitalWrite(in2_PP, LOW);
    digitalWrite(in1_ZP, LOW);
    digitalWrite(in2_ZP, LOW);

    digitalWrite(in3_PL, LOW);
    digitalWrite(in4_PL, LOW);
    digitalWrite(in3_ZL, LOW);
    digitalWrite(in4_ZL, LOW);
    digitalWrite(in3_SP, LOW);
    digitalWrite(in4_SP, LOW);

  }

}


void loop() {


  Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
  while (Wire.available())   // slave may send less than requested
  {
    data[t] = Wire.read(); // receive a byte as character
    if (t < 15)
      t++;
    else
      t = 0;
  }

  Serial.print("data[0]:");
  Serial.println(data[0]);
  Serial.print("data[2]:");
  Serial.println(data[2]);
  Serial.print("data[4]:");
  Serial.println(data[4]);
  Serial.print("data[6]:");
  Serial.println(data[6]);
  Serial.print("data[8]:");
  Serial.println(data[8]);
  Serial.print("data[10]:");
  Serial.println(data[10]);
  Serial.print("data[12]:");
  Serial.println(data[12]);
  Serial.print("data[14]:");
  Serial.println(data[14]);
  delay(10);


  digitalWrite(in1_SL, HIGH);
  digitalWrite(in2_SL, LOW);
  digitalWrite(in1_PP, HIGH);
  digitalWrite(in2_PP, LOW);
  digitalWrite(in1_ZP, LOW);
  digitalWrite(in2_ZP, HIGH);

  analogWrite(EnA_SL, GET_R_SPEED());
  analogWrite(EnA_PP, GET_R_SPEED());
  analogWrite(EnA_ZP, GET_R_SPEED());


  digitalWrite(in3_PL, HIGH);
  digitalWrite(in4_PL, LOW);
  digitalWrite(in3_ZL, LOW);
  digitalWrite(in4_ZL, HIGH);
  digitalWrite(in3_SP, HIGH);
  digitalWrite(in4_SP, LOW);

  analogWrite(EnB_PL, GET_L_SPEED());
  analogWrite(EnB_ZL, GET_L_SPEED());
  analogWrite(EnB_SP, GET_L_SPEED());
  // analogWrite(enB, 200);

  delay(DELAY_TIME);



  // следование линии
  while (!((_4_LINE()) && (_10_LINE()))) {

    Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
    while (Wire.available())   // slave may send less than requested
    {
      data[t] = Wire.read(); // receive a byte as character
      if (t < 15)
        t++;
      else
        t = 0;
    }

    digitalWrite(in1_SL, HIGH);
    digitalWrite(in2_SL, LOW);
    digitalWrite(in1_PP, HIGH);
    digitalWrite(in2_PP, LOW);
    digitalWrite(in1_ZP, LOW);
    digitalWrite(in2_ZP, HIGH);

    analogWrite(EnA_SL, GET_R_SPEED());
    analogWrite(EnA_PP, GET_R_SPEED());
    analogWrite(EnA_ZP, GET_R_SPEED());


    digitalWrite(in3_PL, HIGH);
    digitalWrite(in4_PL, LOW);
    digitalWrite(in3_ZL, LOW);
    digitalWrite(in4_ZL, HIGH);
    digitalWrite(in3_SP, HIGH);
    digitalWrite(in4_SP, LOW);

    analogWrite(EnB_PL, GET_L_SPEED());
    analogWrite(EnB_ZL, GET_L_SPEED());
    analogWrite(EnB_SP, GET_L_SPEED());
    delay(DELAY_TIME);
  }
}
