void setup() {
 Serial.begin(9600);


}

void loop() {
 int a;
 a = analogRead(A1);
 Serial.println(a);

}
