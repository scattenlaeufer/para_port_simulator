#define led_red 4
#define led_green 5
#define out_pin 6
#define button1 3
#define button2 2

#define pulse_dur 10
#define pulse_freq 7000
#define led_dur 100

unsigned long pulse_start;
unsigned long pulse_freq_start;
unsigned long led_start;

bool pulse_running;
bool led_on;
bool pulse_freq_running;

/*
 * 2 -> 3
 * masse -> 21-25
 */

void setup(){
	pinMode(led_red, OUTPUT);
	pinMode(led_green, OUTPUT);
	pinMode(out_pin, OUTPUT);
	pinMode(button2, INPUT);
	pinMode(button1, INPUT);
	digitalWrite(led_red, LOW);
	digitalWrite(led_green, LOW);
	digitalWrite(out_pin, LOW);
	pulse_running = false;
	pulse_freq_running = false;
	led_on = false;
	Serial.begin(9600);
	digitalWrite(led_red, HIGH);
	digitalWrite(led_green, HIGH);
	delay(250);
	digitalWrite(led_red, LOW);
	digitalWrite(led_green, LOW);
}

void loop(){
	if ( digitalRead(button1) == HIGH and not pulse_freq_running ) {
		pulse_freq_running = true;
		pulse_freq_start = millis();
		pulse_running = true;
		pulse_start = millis();
		digitalWrite(out_pin, HIGH);
		digitalWrite(led_red, HIGH);
		led_on = true;
		led_start = millis();
		digitalWrite(led_green, HIGH);
	}
	if ( not pulse_freq_running ){
		if ( not pulse_running ) {
			if ( digitalRead(button2) == HIGH ) {
				digitalWrite(led_green, HIGH);
				led_on = true;
				led_start = millis();
				digitalWrite(out_pin, HIGH);
				pulse_running = true;
				pulse_start = millis();
			}
		} else if ( millis() > pulse_start + pulse_dur ) {
			pulse_running = false;
			digitalWrite(out_pin, LOW);
		} else {
			Serial.print("PUSH\n");
		}
		if ( led_on and millis() > led_start + led_dur ) {
			led_on = false;
			digitalWrite(led_green, LOW);
		}
	} else {
		if ( pulse_running and millis() > pulse_start + pulse_dur ) {
			digitalWrite(out_pin, LOW);
			pulse_running = false;
		}
		if ( led_on and millis() > led_start + led_dur ) {
			digitalWrite(led_green, LOW);
			led_on = false;
		}
	}
	if ( pulse_freq_running and ( not pulse_running ) and millis() > pulse_freq_start + pulse_freq ) {
		pulse_freq_start = millis();
		led_on = true;
		led_start = millis();
		digitalWrite(led_green, HIGH);
		pulse_running = true;
		pulse_start = millis();
		digitalWrite(out_pin, HIGH);
	}
}
