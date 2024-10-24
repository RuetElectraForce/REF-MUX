//this is the channel addresses for the 14 sensors
byte channel_adress_table[14][4] = {
  { 0, 0, 0, 0 },  //0
  { 0, 0, 0, 1 },  //1
  { 0, 0, 1, 0 },  //2
  { 0, 0, 1, 1 },  //3
  { 0, 1, 0, 0 },  //4
  { 0, 1, 0, 1 },  //5
  { 0, 1, 1, 0 },  //6
  { 0, 1, 1, 1 },  //7
  { 1, 0, 0, 0 },  //8
  { 1, 0, 0, 1 },  //9
  { 1, 0, 1, 0 },  //10
  { 1, 0, 1, 1 },  //11
  { 1, 1, 0, 0 },  //12
  { 1, 1, 0, 1 },  //13
};

//mux variables
//make sure to connect these pins correctly. otherwise the sequece will be incorrect
#define A 5
#define B 4
#define C 3
#define D 2

#define sensor A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //in this loop we'll take all the 14 sensor's reading
  for (int i = 0; i < 14; i++) {
    Mux_Addr(i);  //set the channel address first
    Serial.print(analogRead(sensor)); //then take the reading
    Serial.print("\t");
  }
  Serial.println();
  delay(50);
}


void Mux_Addr(int ch_Addr) {
  if (channel_adress_table[ch_Addr][0]) {
    digitalWrite(D, 1);
  } else {
    digitalWrite(D, 0);
  }

  if (channel_adress_table[ch_Addr][1]) {
    digitalWrite(C, 1);
  } else {
    digitalWrite(C, 0);
  }

  if (channel_adress_table[ch_Addr][2]) {
    digitalWrite(B, 1);
  } else {
    digitalWrite(B, 0);
  }

  if (channel_adress_table[ch_Addr][3]) {
    digitalWrite(A, 1);
  } else {
    digitalWrite(A, 0);
  }
}
