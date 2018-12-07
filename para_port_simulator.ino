#define led_red 4
#define led_green 5
#define button1 3
#define button2 2

#define pulse_dur 5
#define pulse_freq 5000
#define led_dur 100

unsigned long pulse_start;
unsigned long led_start;

bool pulse_running;
bool led_on;
bool pulse_freq_running;

void setup(){
	pinMode(led_red, OUTPUT);
	pinMode(led_green, OUTPUT);
	pinMode(button2, INPUT);
	digitalWrite(led_red, LOW);
	digitalWrite(led_green, LOW);
	pulse_running = false;
	pulse_freq_running = false;
	led_on = false;
	Serial.begin(9600);
}

void loop(){
	if ( pulse_running == false ) {
		if ( digitalRead(button2) == HIGH ) {
			digitalWrite(led_green, HIGH);
			led_on = true;
			led_start = millis();
			pulse_running = true;
			pulse_start = millis();
		}
	} else if ( millis() > pulse_start + pulse_dur ) {
		pulse_running = false;
	} else {
		Serial.print("PUSH\n");
	}
	if ( led_on = true) {
		if ( millis() > led_start + led_dur ) {
			led_on = false;
			digitalWrite(led_green, LOW);
		}
	}
}
