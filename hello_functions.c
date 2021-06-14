#include <stdio.h>
#include <stdbool.h>

const float TEMP_C_MIN = -55.0;
const float TEMP_C_MAX = 125.0;
const int TEMP_SENSE_MIN = 0;
const int TEMP_SENSE_MAX = 1023;
const float TEMP_C_IF_INVALID = -100.0;
const float TEMP_F_IF_INVALID = -200.0;

int add(int a, int b) {
  
  int sum = a + b;
  
  return sum;
}

float temp_sensor_converter(int temp_sensor_value, bool success) {
  
  float temp_celcius = 0;
  
  if(temp_sensor_value < TEMP_SENSE_MIN || temp_sensor_value > TEMP_SENSE_MAX) {
    
    printf("Temp sensor value %d is not in the range of %d to %d, changing success to false.\n", temp_sensor_value, TEMP_SENSE_MIN, TEMP_SENSE_MAX);
    
    success = false;
    
    return -100;
  }
  
  printf("Temp sensor value %d is in the range of %d to %d, attempting conversion now...\n", temp_sensor_value, TEMP_SENSE_MIN, TEMP_SENSE_MAX);
  
  float TEMP_SLOPE = (TEMP_C_MAX - TEMP_C_MIN)/(1.0 * (TEMP_SENSE_MAX - TEMP_SENSE_MIN));
  
  temp_celcius = TEMP_SLOPE * temp_sensor_value * TEMP_C_MIN;
  
  if(temp_celcius < TEMP_C_MIN || temp_celcius > TEMP_C_MAX) {
    
    printf("Temp celcius value %f is in the range of %f to %f, changing success to false.\n", temp_celcius, TEMP_C_MIN, TEMP_C_MAX);
    
    success = false;
    
    return -200;
  }
  
  printf("Temp sensor value %d was converted successfully to temperature %f C in the range of %f C to %f C.\n", temp_sensor_value, temp_celcius, TEMP_C_MIN, TEMP_C_MAX);
  
  success = true;
  
  return temp_celcius;
}

float temp_c_to_f(float temp_c) {
  
  float temp_f = (9.0/5.0) * temp_c + 32.0;
  
  printf("Temp %f C = %f F\n", temp_c, temp_f);
}
