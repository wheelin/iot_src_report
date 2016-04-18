#include <WaspBLE.h>

#define ONE_G           4096
#define NUM_OF_SAMPLES  20
#define ACC_VAL_OFFSET  15
#define WALK_THRES      10
#define RUN_THRES       15


uint8_t not_init = 0;
uint8_t ret = 0;

// MAC address of BLE device to find and connect.
char MAC[14] = "b0b448c9ba01";

uint8_t attributeData[2] = {0x00};

uint64_t tmp_mag;
int16_t xValues[NUM_OF_SAMPLES] = {0};
int16_t yValues[NUM_OF_SAMPLES] = {0};
int16_t zValues[NUM_OF_SAMPLES] = {0};
uint32_t mag[NUM_OF_SAMPLES] = {0}; 
uint32_t gesture_intensity;

void hangOnFault(const char * msg);
uint8_t sendAcceleroConfig();
uint8_t disableAccelero();
uint8_t sendSampleRateConfig();
uint8_t enableNotifs();
uint8_t disableNotifs();
uint8_t findAndConnect();

uint32_t table_average(uint32_t * mg);
uint32_t rnd_sqrt(uint32_t a_nInput);
uint32_t abs(int32_t val);


void setup() 
{  
	BLE.ON(SOCKET0);
}

void loop() 
{
	int32_t tmp_x, tmp_y, tmp_z;
	uint8_t event_counter = 0;
	uint64_t previous;
	
	if(findAndConnect() != 0)
	{
		/* We cannot acceed to the device */
		delay(1000);
		return;
	}
	/* start of the app */
	if(enableNotifs() != 0)
	{
		USB.println("Cannot configure notifs");
		delay(1000);
		return;
	}

	if(sendAcceleroConfig() != 0)
	{
		USB.println("Cannot send accelero config");
		delay(1000);
		return;
	}

	if(sendSampleRateConfig() != 0)
	{
		USB.println("Cannot configure accelero sample rate");
		delay(1000);
		return;
	}

    /* wait some time for the accelero to start up */
    delay(500);

    previous = millis();
    while((event_counter < NUM_OF_SAMPLES) && ((millis() - previous) < 10000))
    {
        ret = BLE.waitEvent(5000);
        if(ret == BLE_EVENT_ATTCLIENT_ATTRIBUTE_VALUE)
        {

            tmp_x = (int16_t)(BLE.event[ACC_VAL_OFFSET + 1] << 8) + (int16_t)BLE.event[ACC_VAL_OFFSET + 0];
            tmp_y = (int16_t)(BLE.event[ACC_VAL_OFFSET + 3] << 8) + (int16_t)BLE.event[ACC_VAL_OFFSET + 2];
            tmp_z = (int16_t)(BLE.event[ACC_VAL_OFFSET + 5] << 8) + (int16_t)BLE.event[ACC_VAL_OFFSET + 4];
            USB.print("X axis acceleration : ");
            USB.println(tmp_x);
            USB.print("Y axis acceleration : ");
            USB.println(tmp_y);
            USB.print("Z axis acceleration : ");
            USB.println(tmp_z);
            

            tmp_mag = rnd_sqrt((tmp_x * tmp_x) + (tmp_y * tmp_y) + (tmp_z * tmp_z) - (ONE_G * ONE_G));

            USB.print("Temporary magnitude = "); USB.println(tmp_mag);
            USB.println();
            xValues[event_counter] = (int16_t)(BLE.event[ACC_VAL_OFFSET + 1] << 8) + BLE.event[ACC_VAL_OFFSET + 0];
	        yValues[event_counter] = (int16_t)(BLE.event[ACC_VAL_OFFSET + 3] << 8) + BLE.event[ACC_VAL_OFFSET + 2];
	        zValues[event_counter] = (int16_t)(BLE.event[ACC_VAL_OFFSET + 5] << 8) + BLE.event[ACC_VAL_OFFSET + 4];
            mag[event_counter] = tmp_mag;

            event_counter++;
        }
    }

    if(disableAccelero() != 0)
    {
        USB.println("Cannot disable accelero");
        //delay(1000);
        //return;
    }

    if(disableNotifs() != 0)
    {
        USB.println("Cannot disable notifs");
        //delay(1000);
        //return;
    }

    BLE.disconnect(BLE.connection_handle);
    if (BLE.errorCode != 0) USB.println(F("Disconnect fail"));
    else USB.println(F("Disconnected."));

    gesture_intensity = table_average(mag);
    USB.print("Gesture intensity : "); USB.println(gesture_intensity);
    if(gesture_intensity < WALK_THRES)
    {
        /* STILL */
    }
    else if(gesture_intensity >= WALK_THRES && gesture_intensity < RUN_THRES)
    {
        /* WALK */
    }
    else if(gesture_intensity >= RUN_THRES)
    {
        /* RUN */
    }
    else
    {
        /* PROBLEM */
    }
	USB.println("######Raw datas######");
    for(int8_t i = 0; i < NUM_OF_SAMPLES;i++)
    {
        USB.print("x:\t");
		USB.print(xValues[i]);
		USB.print("\ty:\t");
		USB.print(yValues[i]);
		USB.print("\tz:\t");
		USB.println(zValues[i]);
    }
    USB.println();
    delay(5000);
}

void hangOnFault(const char * msg)
{
	while(1)
	{
		USB.println(msg);
		delay(1000);
	}
}

uint8_t sendAcceleroConfig()
{
	uint8_t attr[2] = {0};
	attr[1] = 0x02; 
	attr[0] = 0x38; /* 0b00111000 */
	if(BLE.attributeWrite(BLE.connection_handle, 0x3C, attr,2))
	{
		return 1;
	}
	return 0;
}

uint8_t disableAccelero()
{
    uint8_t attr[2] = {0};
    if(BLE.attributeWrite(BLE.connection_handle, 0x3C, attr,2))
    {
        return 1;
    }
    return 0;
}

uint8_t sendSampleRateConfig()
{
	uint8_t attr[2] = {0};
	attr[0] = 0x0A;
	attr[1] = 0x00;
	if(BLE.attributeWrite(BLE.connection_handle, 0x3E, attr,1))
	{
		return 1;
	}
	return 0;
}

uint8_t enableNotifs()
{
	/* Enable notification for all accelero values changes */
    uint8_t attr[2] = {0};
    attr[0] = 1;
    attr[1] = 0;
    if(BLE.attributeWrite(BLE.connection_handle, 0x3A, attr, 2))
    {
      return 1;
    }
    return 0;
}

uint8_t disableNotifs()
{
    /* Enable notification for all accelero values changes */
    uint8_t attr[2] = {0};
    attr[0] = 0;
    attr[1] = 0;
    if(BLE.attributeWrite(BLE.connection_handle, 0x3A, attr, 2))
    {
      return 1;
    }
    return 0;
}


uint8_t findAndConnect()
{
	if (BLE.scanDevice(MAC) != 1)
	{
		USB.println(F("Device not found: "));
		return 1;
	}
	if(BLE.connectDirect(MAC) != 1)
	{
		USB.println(F("NOT Connected"));
		return 1;
	}
	return 0;
}

uint32_t table_average(uint32_t * mg)
{
    uint32_t i, rnos, sum;
    rnos = 0; sum = 0;
    for(i = 0; i < NUM_OF_SAMPLES; i++)
    {
        if(mg[i] != 0)
        {
            sum += mg[i];
            rnos++;
        }
    }
    return sum / rnos;
}

uint32_t rnd_sqrt(uint32_t a_nInput)
{
    uint32_t op  = a_nInput;
    uint32_t res = 0;
    uint32_t one = 1uL << 30;
    while (one > op)
    {
        one >>= 2;
    }

    while (one != 0)
    {
        if (op >= res + one)
        {
            op = op - (res + one);
            res = res +  2 * one;
        }
        res >>= 1;
        one >>= 2;
    }
    if (op > res)
    {
        res++;
    }
    return res;
}

uint32_t abs(int32_t val)
{
    if(val < 0)
        return -val;
    else
        return val;
}






