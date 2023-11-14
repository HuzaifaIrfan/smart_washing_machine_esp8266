
#include "rest_api_server.hpp"

const char *ssid = "AL-12";
const char *password = "f295e0c1";

StaticJsonDocument<2048> jsonBuffer;

ESP8266WebServer server(80);

// Serving next_washing_machine_task_request
void next_washing_machine_task_request()
{

  Serial.println("next_washing_machine_task");

  if (server.hasArg("plain") == false)
  { // Check if body received
    server.send(400, "text/json", "{\"error\": \"Empty Body Received\"}");
    return;
  }

  String washing_machine_task_json = server.arg("plain");

  Serial.println(washing_machine_task_json);
  deserializeJson(jsonBuffer, washing_machine_task_json);
  short got_task_size = jsonBuffer.size();
  Serial.println("jsonBuffer size:" + String(got_task_size));

  if (not(got_task_size == 4))
  {
    server.send(400, "text/json", "{\"error\": \"Invalid Task Size\", \"value\": " + String(got_task_size) + "}");
    return;
  }

  int tmp_washing_machine_task[4] = {0};

  for (int j = 0; j < 4; ++j)
  {
    tmp_washing_machine_task[j] = jsonBuffer[j];
  }

  washing_machine_controller.pause();

  washing_machine_controller.manual_setup_next_task(tmp_washing_machine_task);

  washing_machine_task_json = "";
  serializeJson(jsonBuffer, washing_machine_task_json);

  int current_task_sequence_pointer = int(washing_machine_controller.get_current_task_sequence_pointer());
  server.send(200, "text/json", "{\"washing_machine_task\": " + String(washing_machine_task_json) + ", \"current_task_sequence_pointer\": " + String(current_task_sequence_pointer) + "}");
}

// Serving change_washing_machine_task_sequence_request
void change_washing_machine_task_sequence_request()
{

  Serial.println("change_washing_machine_task_sequence");

  if (server.hasArg("plain") == false)
  { // Check if body received
    server.send(400, "text/json", "{\"error\": \"Empty Body Received\"}");
    return;
  }

  String washing_machine_task_sequence_json = server.arg("plain");

  Serial.println(washing_machine_task_sequence_json);
  deserializeJson(jsonBuffer, washing_machine_task_sequence_json);
  short got_task_sequence_size = jsonBuffer.size();
  Serial.println("jsonBuffer size:" + String(got_task_sequence_size));

  if (not(got_task_sequence_size == 16))
  {
    server.send(400, "text/json", "{\"error\": \"Invalid Task Sequence Size\", \"value\": " + String(got_task_sequence_size) + "}");
    return;
  }

  int tmp_washing_machine_task_sequence[16][4] = {0};

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      tmp_washing_machine_task_sequence[i][j] = jsonBuffer[i][j];
    }
  }

  washing_machine_controller.pause();
  washing_machine_controller.reset();

  change_washing_machine_task_sequence(tmp_washing_machine_task_sequence);

  get_washing_machine_task_sequence(tmp_washing_machine_task_sequence);
  copyArray(tmp_washing_machine_task_sequence, jsonBuffer);

  washing_machine_task_sequence_json = "";
  serializeJson(jsonBuffer, washing_machine_task_sequence_json);

  int current_task_sequence_pointer = int(washing_machine_controller.get_current_task_sequence_pointer());
  server.send(200, "text/json", "{\"washing_machine_task_sequence\": " + String(washing_machine_task_sequence_json) + ", \"current_task_sequence_pointer\": " + String(current_task_sequence_pointer) + "}");
}

// Define routing
void RESTAPIServer::restServerRouting()
{

  server.on("/", HTTP_GET, []()
            { server.send(200, F("text/html"),
                          F("Welcome to the Smart Washing Machine REST API Web Server")); });
  // server.on(F("/run"), HTTP_GET, getHelloWord);

  server.on("/run", HTTP_GET, []()
            { 
               Serial.println("Run");
              washing_machine_controller.run();
              server.send(200, "text/json", "{\"success\": true}"); });

  server.on("/pause", HTTP_GET, []()
            { 
               Serial.println("Pause");
              washing_machine_controller.pause();
              server.send(200, "text/json", "{\"success\": true}"); });

  server.on("/is_running", HTTP_GET, []()
            { 
               Serial.println("is_running");
              int value = int(washing_machine_controller.is_running());
              server.send(200, "text/json", "{\"value\": "+String(value)+"}"); });

  server.on("/reset", HTTP_GET, []()
            { 
               Serial.println("Reset");
              washing_machine_controller.reset();
              server.send(200, "text/json", "{\"success\": true}"); });

  server.on("/hold", HTTP_GET, []()
            { 
               Serial.println("Hold");
              washing_machine_controller.hold();
              server.send(200, "text/json", "{\"success\": true}"); });

  server.on("/is_hold", HTTP_GET, []()
            { 
               Serial.println("is_hold");
              int value = int(washing_machine_controller.is_hold());
              server.send(200, "text/json", "{\"value\": "+String(value)+"}"); });

  server.on("/skip", HTTP_GET, []()
            { 
               Serial.println("Skip");
              washing_machine_controller.skip();
              server.send(200, "text/json", "{\"success\": true}"); });

  server.on("/is_lid_closed", HTTP_GET, []()
            { 
               Serial.println("is_lid_closed");
              int value = int(washing_machine_controller.is_lid_closed());
              server.send(200, "text/json", "{\"value\": "+String(value)+"}"); });

  server.on("/current_task_sequence", HTTP_GET, []()
            { 
              Serial.println("current_task_sequence");

              int tmp_washing_machine_task_sequence[16][4] = {0};
              get_washing_machine_task_sequence(tmp_washing_machine_task_sequence);
              copyArray(tmp_washing_machine_task_sequence, jsonBuffer);
              String washing_machine_task_sequence_json;  
              serializeJson(jsonBuffer, washing_machine_task_sequence_json);
              int current_task_sequence_pointer = int(washing_machine_controller.get_current_task_sequence_pointer());

              server.send(200, "text/json", "{\"task_sequence\": "+String(washing_machine_task_sequence_json)+", \"task_sequence_pointer\": "+String(current_task_sequence_pointer)+"}"); });

  server.on("/current_task", HTTP_GET, []()
            { 
               Serial.println("current_task");
              int current_task_index = int(washing_machine_controller.get_current_task_index());
              int count_down = int(washing_machine_controller.get_count_down());
              server.send(200, "text/json", "{\"task\": "+String(current_task_index)+", \"count_down\": "+String(count_down)+"}"); });

  server.on("/current_status", HTTP_GET, []()
            {
              Serial.println("current_status");

              Serial.println("is_running");
              int is_running = int(washing_machine_controller.is_running());

              Serial.println("is_hold");
              int is_hold = int(washing_machine_controller.is_hold());

              Serial.println("is_lid_closed");
              int is_lid_closed = int(washing_machine_controller.is_lid_closed());

              // Serial.println("current_task_sequence");
              // int tmp_washing_machine_task_sequence[16][4] = {0};
              // get_washing_machine_task_sequence(tmp_washing_machine_task_sequence);
              // copyArray(tmp_washing_machine_task_sequence, jsonBuffer);
              // String washing_machine_task_sequence_json;
              // serializeJson(jsonBuffer, washing_machine_task_sequence_json);
              int current_task_sequence_pointer = int(washing_machine_controller.get_current_task_sequence_pointer());

              Serial.println("current_status");
              int current_task_index = int(washing_machine_controller.get_current_task_index());
              int count_down = int(washing_machine_controller.get_count_down());

              server.send(200, "text/json", "{\"is_running\": " + String(is_running) + ", \"is_hold\": " + String(is_hold) + ", \"is_lid_closed\": " + String(is_lid_closed) + ", \"task_sequence_pointer\": " + String(current_task_sequence_pointer) + ", \"task\": " + String(current_task_index) + ", \"count_down\": " + String(count_down) + "}");
            });

  server.on("/change_washing_machine_task_sequence", HTTP_POST, change_washing_machine_task_sequence_request);
  server.on("/next_washing_machine_task", HTTP_POST, next_washing_machine_task_request);
}

RESTAPIServer::RESTAPIServer()
{
}

void RESTAPIServer::setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.hostname("smart_washing_machine.local");
  if (!MDNS.begin("smart_washing_machine.local"))
  {
    Serial.println("Error setting up MDNS responder!");
  }
  WiFi.begin(ssid, password);

  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Activate mDNS this is used to be able to connect to the server
  // with local DNS hostmane esp8266.local

  // Set server routing
  restServerRouting();
  // Set not found response
  // server.onNotFound(handleNotFound);
  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void RESTAPIServer::loop()
{
  server.handleClient();
}

RESTAPIServer rest_api_server;