//pin configuration in esp32s3

int greeen_led = 19;             
int yellow_led = 20;
int red_led = 21;
int buzzer_pin = 47;
int mq2 = 7;

//gas threshold value 

int gas_limit0 = 630;
int gas_limit1 = 1600;

unsigned long initial_delay = 120000;
unsigned long current_time = 0;
//function for led on and off 

void led(int green, int yellow, int red){
  digitalWrite(greeen_led, green);
  digitalWrite(yellow_led, yellow);
  digitalWrite(red_led, red);
  }


void setup() {

  pinMode(greeen_led, OUTPUT);
  pinMode(yellow_led,OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);

Serial.begin(115200);
}

void loop() {

  current_time = millis();
int gas_value = analogRead(mq2);  //read gas sensor value

if(current_time > initial_delay)    //heater warmup time milliseconds (2 minutes)
{

  if(gas_value < gas_limit0)  //safe condition 
  {
    led(HIGH, LOW, LOW);
    Serial.println("No gas leak");
  }

  else if (gas_value > gas_limit0 && gas_value < gas_limit1)    //warning condition 
  {
    Serial.println("gas detected");
    Serial.println(gas_value);
    led(LOW, HIGH, LOW);
    tone(buzzer_pin, 5000, 1000);
    noTone(buzzer_pin);
    delay(2500);

  }

  else if (gas_value >= gas_limit1)     //alert condition
  {
    Serial.println(" !!  ALERT !!   gas leak");
    Serial.println(gas_value);
    led(LOW, LOW, HIGH);
    tone(buzzer_pin, 15000,2500);
    noTone(buzzer_pin);
    delay(1000);

  }
  }

  else{
  led(HIGH, HIGH, HIGH);
  Serial.print("countdown   : ");
  Serial.println(initial_delay - current_time);

  }
}

