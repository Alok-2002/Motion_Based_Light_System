#define e_s1 A0 // Echo pin
#define t_s1 A1 // Trigger pin

#define e_s2 A2 // Echo pin
#define t_s2 A3 // Trigger pin

int relay = 8; // Using built-in LED (Pin 13) instead of a relay

long dis_a = 0, dis_b = 0;
int flag1 = 0, flag2 = 0;
int person = 0;

//********************** Ultra_Read with Range Limit (10 cm) ****************************
void ultra_read(int pin_t, int pin_e, long &ultra_time) {
    long time;
    pinMode(pin_t, OUTPUT);
    pinMode(pin_e, INPUT);
    digitalWrite(pin_t, LOW);
    delayMicroseconds(2);
    digitalWrite(pin_t, HIGH);
    delayMicroseconds(10);
    time = pulseIn(pin_e, HIGH, 30000); // Timeout added for faster response
    ultra_time = time / 29 / 2; 

    // Limit detection range to 10 cm
    if (ultra_time > 10 || ultra_time == 0) {  
        ultra_time = 1000; // Assign a high value to indicate "no object detected"
    }
}

void setup() {
    Serial.begin(9600); // Initialize Serial Monitor

    pinMode(relay, OUTPUT); // Set built-in LED as output

    Serial.println("Welcome to the system!");
    delay(500);
}

void loop() { 
    // Read distance from both sensors
    ultra_read(t_s1, e_s1, dis_a);
    delay(10);
    ultra_read(t_s2, e_s2, dis_b);
    delay(10);

    Serial.print("da: ");
    Serial.println(dis_a);
    Serial.print("db: ");
    Serial.println(dis_b);   

    if (dis_a < 10 && flag1 == 0) { // Limit detection range
        flag1 = 1;
        if (flag2 == 0) {
            person = person + 1;
        }
    }

    if (dis_b < 10 && flag2 == 0) { // Limit detection range
        flag2 = 1;
        if (flag1 == 0) {
            person = person - 1;
        }
    }

    if (dis_a > 10 && dis_b > 10 && flag1 == 1 && flag2 == 1) { // Reset only when both sensors detect "no object"
        flag1 = 0;
        flag2 = 0;
    }

    // Display output on Serial Monitor
    Serial.print("People Count: ");
    Serial.println(person);

    Serial.print("Light is ");
    if (person > 0) {
        digitalWrite(relay, HIGH); // Turn ON built-in LED
        Serial.println("ON");
    } else {
        digitalWrite(relay, LOW); // Turn OFF built-in LED
        Serial.println("OFF");
    }

    Serial.println("--------------------"); // Separator for readability
    delay(300); // Reduced delay for faster detection
}
