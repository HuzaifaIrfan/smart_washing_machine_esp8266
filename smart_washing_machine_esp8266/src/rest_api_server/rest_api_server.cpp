
#include "rest_api_server.hpp"

const char *ssid = "AL-12";
const char *password = "f295e0c1";

StaticJsonDocument<2048> jsonBuffer;

ESP8266WebServer server(80);


// Serving next_machine_routine_request
void next_machine_routine_request()
{

  Serial.println("next_machine_routine");

  if (server.hasArg("plain") == false)
  { // Check if body received
    server.send(400, "text/json", "{\"error\": \"Empty Body Received\"}");
    return;
  }

  String machine_routine_json = server.arg("plain");

  Serial.println(machine_routine_json);
  deserializeJson(jsonBuffer, machine_routine_json);
  short got_routine_size =jsonBuffer.size();
  Serial.println("jsonBuffer size:"+String(got_routine_size));

  if(not (got_routine_size==4)){
    server.send(400, "text/json", "{\"error\": \"Invalid Routine Size\", \"value\": " + String(got_routine_size) + "}");
    return;
  }

  int tmp_machine_routine[4] = {0};


        for (int j = 0; j < 4; ++j)
        {
            tmp_machine_routine[j] = jsonBuffer[j];
        }

  washing_machine_controller.pause();

  washing_machine_controller.manual_setup_next_state(tmp_machine_routine);

  machine_routine_json = "";
  serializeJson(jsonBuffer, machine_routine_json);

  int current_routine_state_pointer = int(washing_machine_controller.get_current_routine_state_pointer());
  server.send(200, "text/json", "{\"machine_routine\": " + String(machine_routine_json) + ", \"current_routine_state_pointer\": " + String(current_routine_state_pointer) + "}");
}


// Serving change_machine_routines_request
void change_machine_routines_request()
{

  Serial.println("change_machine_routines");

  if (server.hasArg("plain") == false)
  { // Check if body received
    server.send(400, "text/json", "{\"error\": \"Empty Body Received\"}");
    return;
  }

  String machine_routine_json = server.arg("plain");

  Serial.println(machine_routine_json);
  deserializeJson(jsonBuffer, machine_routine_json);
  short got_routines_size =jsonBuffer.size();
  Serial.println("jsonBuffer size:"+String(got_routines_size));

  if(not (got_routines_size==16)){
    server.send(400, "text/json", "{\"error\": \"Invalid Routine Size\", \"value\": " + String(got_routines_size) + "}");
    return;
  }

  int tmp_machine_routines[16][4] = {0};

    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tmp_machine_routines[i][j] = jsonBuffer[i][j];
        }
    }
  




  washing_machine_controller.pause();
  washing_machine_controller.reset();

  change_machine_routines(tmp_machine_routines);

  get_machine_routines(tmp_machine_routines);
  copyArray(tmp_machine_routines, jsonBuffer);

  machine_routine_json = "";
  serializeJson(jsonBuffer, machine_routine_json);

  int current_routine_state_pointer = int(washing_machine_controller.get_current_routine_state_pointer());
  server.send(200, "text/json", "{\"machine_routines\": " + String(machine_routine_json) + ", \"current_routine_state_pointer\": " + String(current_routine_state_pointer) + "}");
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

  server.on("/is_paused", HTTP_GET, []()
            { 
               Serial.println("is_paused");
              int value = int(washing_machine_controller.is_paused());
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

  server.on("/current_routine", HTTP_GET, []()
            { 
              Serial.println("current_routine");

              int tmp_machine_routines[16][4] = {0};
              get_machine_routines(tmp_machine_routines);
              copyArray(tmp_machine_routines, jsonBuffer);
              String machine_routine_json;  
              serializeJson(jsonBuffer, machine_routine_json);


              int current_routine_state_pointer = int(washing_machine_controller.get_current_routine_state_pointer());
              server.send(200, "text/json", "{\"machine_routine\": "+String(machine_routine_json)+", \"current_routine_state_pointer\": "+String(current_routine_state_pointer)+"}"); });

  server.on("/current_state", HTTP_GET, []()
            { 
               Serial.println("current_state");
              int current_state_index = int(washing_machine_controller.get_current_state_index());
              int count_down = int(washing_machine_controller.get_count_down());
              server.send(200, "text/json", "{\"current_state_index\": "+String(current_state_index)+", \"count_down\": "+String(count_down)+"}"); });

  server.on("/change_machine_routines", HTTP_POST, change_machine_routines_request);
    server.on("/next_machine_routine", HTTP_POST, next_machine_routine_request);
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