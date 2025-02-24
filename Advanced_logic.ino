#define e_s1 A0 // Echo pin for sensor 1 (outside)
#define t_s1 A1 // Trigger pin for sensor 1
#define e_s2 A2 // Echo pin for sensor 2 (inside)
#define t_s2 A3 // Trigger pin for sensor 2

int relay = 8; // Relay pin for light control

long dis_a = 0, dis_b = 0;
bool flag1 = false, flag2 = false;
int person = 0;
unsigned long previousMillis = 0;
const long interval = 100; // Interval for sensor readings (100ms)

void ultra_read(int pin_t, int pin_e, long &ultra_time) {
    long time;
    pinMode(pin_t, OUTPUT);
    pinMode(pin_e, INPUT);
    digitalWrite(pin_t, LOW);
    delayMicroseconds(2);
    digitalWrite(pin_t, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin_t, LOW);

    time = pulseIn(pin_e, HIGH, 30000); // 30ms timeout for stable reading
    ultra_time = time / 29 / 2;

    // Ensure valid readings
    if (ultra_time <= 0) ultra_time = 1000;
}

void setup() {
    Serial.begin(9600);
    pinMode(relay, OUTPUT);
    Serial.println("People Counter System Initialized!");
    delay(500);
}

void loop() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        // Read distance from both sensors
        ultra_read(t_s1, e_s1, dis_a);
        ultra_read(t_s2, e_s2, dis_b);

        // Print sensor readings
        Serial.print("da: ");
        Serial.println(dis_a);
        Serial.print("db: ");
        Serial.println(dis_b);

        // **Person entering (Sensor 1 -> Sensor 2)**
        if (dis_a < 20 && !flag1 && !flag2) {
            flag1 = true;
        }
        if (dis_b < 20 && flag1 && !flag2) {
            flag2 = true;
            person++;
            Serial.println("Person entered!");
        }

        // **Person exiting (Sensor 2 -> Sensor 1)**
        if (dis_b < 20 && !flag1 && !flag2) {
            flag2 = true;
        }
        if (dis_a < 20 && flag2 && !flag1) {
            flag1 = true;
            if (person > 0) {
                person--;
                Serial.println("Person exited!");
            }
        }

        // **Reset flags only when both sensors are clear**
        if (dis_a > 20 && dis_b > 20) {
            flag1 = false;
            flag2 = false;
        }

        // **Display people count**
        Serial.print("People Count: ");
        Serial.println(person);

        // **Control light based on people count**
        Serial.print("Light is ");
        if (person > 0) {
            digitalWrite(relay, HIGH);
            Serial.println("ON");
        } else {
            digitalWrite(relay, LOW);
            Serial.println("OFF");
        }

        Serial.println("--------------------"); // Separator for readability

        // **Delay added to slow down loop output**
        delay(800);
    }
}
