/**
 * This proof of concept implementation demonstrates how one would go about publishing and subscribing to AWS IoT topics in general. 
 * 
 * It is supposed to demonstrate the ability to subscribe to the 'qwic/assignment' topic using the credentials supplied by QWIC. 
 * For some reason these do not work.  
 *
 * Two version of the application is rolled into one, but not at the same time: The QWIC #define controls which one is generated.
*/
  
/** 
 * QWIC controls the variant of the application to be generated: Uncomment for QWIC assignment, comment for own assignment.
 */
// #define QWIC

#include <ArduinoJson.h>
#include <MQTTClient.h>
#include <WiFiClientSecure.h>
#include "secrets.h"

// The MQTT topic that this device should publish to.
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"

// The MQTT topic that this device should subscribe to.
#ifdef QWIC
#define AWS_IOT_SUBSCRIBE_TOPIC "qwic/assignment"
#else // QWIC
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"
#endif // QWIC

/**
 * net represents the WiFi network.
 */
WiFiClientSecure net = WiFiClientSecure();

/**
 * client represents the MQTT Client.
 */
MQTTClient client = MQTTClient(256);

/**
 * connectWiFi connects the application to the WiFi network defined by SSID WIFI_SSID and password WIFI_PASSWORD.
 */
 void connectWiFi(void)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }  

  Serial.println("");
  Serial.print("Connected to SSID='");
  Serial.print(WIFI_SSID);
  Serial.println("'");
}

/**
 * connectWiFi connects the application to our Thing using the credentials defined by 
 * THINGNAME (The name of our Thing),
 * AWS_IOT_ENDPOINT (The AWS IoT Endpoint),
 * AWS_CERT_CA (Amazon Root Key 1), 
 * AWS_CERT_CRT (the device's certificate), and 
 * AWS_CERT_PRIVATE (the device's private key).
 */
void connectAWS(void)
{
  // Configure WiFiClientSecure to use the AWS IoT device credentials
  Serial.print("Using AWS_CERT_CA ");
  Serial.println(AWS_CERT_CA);
  net.setCACert(AWS_CERT_CA);
  
  Serial.println("");
  Serial.print("Using AWS_CERT_CRT ");
  Serial.println(AWS_CERT_CRT);
  net.setCertificate(AWS_CERT_CRT);
  
  Serial.println("");
  Serial.print("Using AWS_CERT_PRIVATE ");
  Serial.println(AWS_CERT_PRIVATE);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  Serial.print("Connecting to thing '");
  Serial.print(THINGNAME);
  Serial.print("' using AWS IOT Endpoint '");
  Serial.print(AWS_IOT_ENDPOINT);
  Serial.println("'");

  // Connect to the MQTT broker on the AWS endpoint.
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  // Create a message handler
  client.onMessage(handleMessage);

  while (!client.connect(THINGNAME)) {
    Serial.print(".");
    delay(100);
  }

  if(!client.connected()){
    Serial.println("AWS IoT Timeout!");
    return;
  }

  Serial.println("AWS IoT Connected!");

  // Subscribe to our topic.
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

  Serial.print("Subscribed to '");
  Serial.print(AWS_IOT_SUBSCRIBE_TOPIC);
  Serial.println("'");
}

/**
 * publishMessage publishes a message to our topic as defines by AWS_IOT_PUBLISH_TOPIC. 
 */
void publishMessage(void)
{
  StaticJsonDocument<200> doc;
  doc["time"] = millis();
  doc["sensor_a0"] = analogRead(0);
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client
  Serial.print(":");
  //Serial.print("publishMessage: ");
  //Serial.println(jsonBuffer);

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

/**
 * handleMessage handles a message from a topic to which we have subscribed. 
 * @param topic The name of the topic from which the message originates.
 * @param jsonPayload The message payload (in JSON format).
 */
void handleMessage(String &topic, String &jsonPayload) 
{
  Serial.println("");
  Serial.println("handleMessage: " + topic + " - " + jsonPayload);

  StaticJsonDocument<200> doc;
  deserializeJson(doc, jsonPayload);

  //Serial.print("handleMessage: doc=");
  //Serial.println(doc);
  
  const char* message = doc["message"];

  Serial.print("handleMessage: message='");
  Serial.print(message);
  Serial.println("'");
}

/**
 * setup initialises the application. 
 */
void setup(void) 
{
  // Initialise the serial channel.
  Serial.begin(9600);

  // Connect to the WiFi network.
  connectWiFi();
  
  // Connect to AWS.
  connectAWS();
}

/**
 * setup initialises the application. 
 */
void loop(void) 
{
  #ifndef QWIC
  publishMessage();
  #endif // QWIC
  
  // Service the AWS Client.
  client.loop();
  
  // Take a deep breath...
  delay(1000);
}
