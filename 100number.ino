int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111};

int digit1, digit2;
void setup()
{
for (int i = 2; i < 9; i++)
{
pinMode(i, OUTPUT);
}
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}
void loop() {
for (int j = 0; j <= 99; j++)
{
digit2 = j / 10;
digit1 = j % 10;
for ( int k = 0; k < 20; k++)
{
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
dis(digit2);
delay(10);
digitalWrite(13, HIGH);
digitalWrite(12, LOW);
dis(digit1);
delay(10);
}
}
}
void dis(int num)
{
for (int i = 2; i < 9; i++)
{
digitalWrite(i, bitRead(digit[num], i - 2));
}
}
