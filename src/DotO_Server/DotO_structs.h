// STATUS RECORD STRUCT //
typedef struct {
  byte previous_task = TASK_UNKNOWN ;
  byte task = TASK_UNKNOWN;
  unsigned int cycle_count = 0;
  unsigned int data_index = 0;
  //add last tx time
  //add txt success
} doto_status_type;

void dump_status(doto_status_type  st) {
  Serial.println("**** STATUS ****");
  Serial.print("Previous:");
  Serial.println(st.previous_task);
  Serial.print("Task:");
  Serial.println(st.task);
  Serial.print("Cycle count:");
  Serial.println(st.cycle_count);
  Serial.print("Data index:");
  Serial.println(st.data_index);
  Serial.println(TASK_UNKNOWN);
}


// SENSOR DATA STRUCT //
typedef struct {
  unsigned int index = 0;
  DateTime date_time;
  boolean tx_ok = false;
  boolean tx_lora = false;
  boolean tx_lorawan = false;
  boolean tx_spot = false;
  float in_temp = 1e-20;
  float out_temp = 1e-20;
  float in_batt = 1e-20;
} sensor_data_type;


void dump_date_time(DateTime now){

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}    

void dump_sensor_data(sensor_data_type sd) {
  Serial.println("-----");
  Serial.print("Index:");
  Serial.println(sd.index);
  Serial.print("DateTime:");
  dump_date_time(sd.date_time);
  Serial.print("TX all, lora, lorawan, spot:");
  Serial.print(sd.tx_ok); Serial.print(sd.tx_lora); Serial.print(sd.tx_lorawan);  Serial.println(sd.tx_spot);
  Serial.print("Internal Temp:");
  Serial.println(sd.in_temp);
  Serial.print("External Temp:");
  Serial.println(sd.out_temp);
  Serial.print("Internal Batt:");
  Serial.println(sd.in_batt);
  Serial.println("-----");
}

//hello

