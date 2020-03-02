### Feedback for Lab 09

Run on March 02, 08:41:46 AM.


#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Pass: Check that directory "config" exists.

+ Pass: Check that directory "docs" exists.

+ Pass: Check that directory "drivers" exists.

+ Pass: Check that directory "src" exists.

+ Pass: Check that directory "tests" exists.

+ Pass: Check that directory "web_code/web" exists.

+ Pass: Check that directory "web_graphics" exists.


#### .gitignore configured properly

+ Pass: Check that file/directory "build" does not exist.

+ Pass: Check that file/directory "build/bin/vis_sim" does not exist.


#### Compile Tests

+ Pass: Change into directory "src".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>==== Auto-Generating Dependencies for passenger_factory.cc. ====
==== Compiling passenger_factory.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/passenger_factory.o. ====
==== Auto-Generating Dependencies for bus.cc. ====
==== Compiling bus.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/bus.o. ====
==== Auto-Generating Dependencies for random_passenger_generator.cc. ====
==== Compiling random_passenger_generator.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/random_passenger_generator.o. ====
==== Auto-Generating Dependencies for passenger_loader.cc. ====
==== Compiling passenger_loader.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/passenger_loader.o. ====
==== Auto-Generating Dependencies for passenger.cc. ====
==== Compiling passenger.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/passenger.o. ====
==== Auto-Generating Dependencies for passenger_generator.cc. ====
==== Compiling passenger_generator.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/passenger_generator.o. ====
==== Auto-Generating Dependencies for passenger_unloader.cc. ====
==== Compiling passenger_unloader.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/passenger_unloader.o. ====
==== Auto-Generating Dependencies for route.cc. ====
==== Compiling route.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/route.o. ====
==== Auto-Generating Dependencies for config_manager.cc. ====
==== Compiling config_manager.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/config_manager.o. ====
==== Auto-Generating Dependencies for stop.cc. ====
==== Compiling stop.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/stop.o. ====
==== Auto-Generating Dependencies for /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp. ====
==== Compiling /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/webobj/visualizer_sim/main.o. ====
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets.h:544:0,
                 from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:6,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:7:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-misc.h: In function const lws_dll2_owner* lws_dll2_owner(const lws_dll2*):
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-misc.h:271:40: warning: const lws_dll2_owner* lws_dll2_owner(const lws_dll2*) hides constructor for struct lws_dll2_owner [-Wshadow]
 lws_dll2_owner(const struct lws_dll2 *d) { return d->owner; }
                                        ^
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets.h:563:0,
                 from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:6,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:7:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-tokenize.h: At global scope:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-tokenize.h:126:37: warning: lws_tokenize_elem lws_tokenize(lws_tokenize*) hides constructor for struct lws_tokenize [-Wshadow]
 lws_tokenize(struct lws_tokenize *ts);
                                     ^
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:7:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In member function virtual void WebServerBase::Session::receiveMessage(const string&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:17:50: warning: unused parameter msg [-Wunused-parameter]
   virtual void receiveMessage(const std::string& msg) {}
                                                  ^~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In constructor WebServerWithState<T, STATE>::WebServerWithState(STATE, int):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:47:51: warning: declaration of state shadows a member of WebServerWithState<T, STATE> [-Wshadow]
  WebServerWithState(STATE state, int port = 8081) : WebServerBase(port), state(state) {}
                                                   ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:51:8: note: shadowed declaration is here
  STATE state;
        ^~~~~
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:55:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:7:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In member function bool picojson::value::evaluate_as_boolean() const:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:424:26: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
     return u_.number_ != 0;
                          ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In member function std::__cxx11::string picojson::value::to_str() const:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:489:93: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
     SNPRINTF(buf, sizeof(buf), fabs(u_.number_) < (1ULL << 53) && modf(u_.number_, &tmp) == 0 ? "%.f" : "%.17g", u_.number_);
                                                                                             ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In function bool picojson::operator==(const picojson::value&, const picojson::value&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:1123:55: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
   return y.is<type>() && x.get<type>() == y.get<type>()
                                                       ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:1125:3: note: in expansion of macro PICOJSON_CMP
   PICOJSON_CMP(double);
   ^~~~~~~~~~~~
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:7:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: At global scope:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:65:7: warning: virtual void JSONSession::receiveMessage(const string&) can be marked override [-Wsuggest-override]
  void receiveMessage(const std::string& msg) {
       ^~~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In member function virtual void JSONSession::receiveJSON(picojson::value&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:59:44: warning: unused parameter val [-Wunused-parameter]
  virtual void receiveJSON(picojson::value& val) {}
                                            ^~~
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:7:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In instantiation of class WebServerWithState<MyWebServerSession, MyWebServerSessionState>:
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:37:74:   required from here
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:49:11: warning: WebServerBase::Session* WebServerWithState<T, STATE>::createSession() [with T = MyWebServerSession; STATE = MyWebServerSessionState] can be marked override [-Wsuggest-override]
  Session* createSession() { return new T(state); }
           ^~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:26:15: warning: virtual void WebServerBase::createSession(void*) was hidden [-Woverloaded-virtual]
  virtual void createSession(void* info);
               ^~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:49:11: warning:   by WebServerBase::Session* WebServerWithState<T, STATE>::createSession() [with T = MyWebServerSession; STATE = MyWebServerSessionState] [-Woverloaded-virtual]
  Session* createSession() { return new T(state); }
           ^~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In instantiation of WebServerWithState<T, STATE>::WebServerWithState(STATE, int) [with T = MyWebServerSession; STATE = MyWebServerSessionState]:
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/main.cpp:37:85:   required from here
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:47:2: warning: declaration of state shadows a member of WebServerWithState<MyWebServerSession, MyWebServerSessionState> [-Wshadow]
  WebServerWithState(STATE state, int port = 8081) : WebServerBase(port), state(state) {}
  ^~~~~~~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:51:8: note: shadowed declaration is here
  STATE state;
        ^~~~~
==== Auto-Generating Dependencies for /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc. ====
==== Compiling /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/webobj/visualizer_sim/my_web_server_command.o. ====
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets.h:544:0,
                 from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:6,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-misc.h: In function const lws_dll2_owner* lws_dll2_owner(const lws_dll2*):
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-misc.h:271:40: warning: const lws_dll2_owner* lws_dll2_owner(const lws_dll2*) hides constructor for struct lws_dll2_owner [-Wshadow]
 lws_dll2_owner(const struct lws_dll2 *d) { return d->owner; }
                                        ^
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets.h:563:0,
                 from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:6,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-tokenize.h: At global scope:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-tokenize.h:126:37: warning: lws_tokenize_elem lws_tokenize(lws_tokenize*) hides constructor for struct lws_tokenize [-Wshadow]
 lws_tokenize(struct lws_tokenize *ts);
                                     ^
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In member function virtual void WebServerBase::Session::receiveMessage(const string&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:17:50: warning: unused parameter msg [-Wunused-parameter]
   virtual void receiveMessage(const std::string& msg) {}
                                                  ^~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In constructor WebServerWithState<T, STATE>::WebServerWithState(STATE, int):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:47:51: warning: declaration of state shadows a member of WebServerWithState<T, STATE> [-Wshadow]
  WebServerWithState(STATE state, int port = 8081) : WebServerBase(port), state(state) {}
                                                   ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:51:8: note: shadowed declaration is here
  STATE state;
        ^~~~~
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:55:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In member function bool picojson::value::evaluate_as_boolean() const:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:424:26: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
     return u_.number_ != 0;
                          ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In member function std::__cxx11::string picojson::value::to_str() const:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:489:93: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
     SNPRINTF(buf, sizeof(buf), fabs(u_.number_) < (1ULL << 53) && modf(u_.number_, &tmp) == 0 ? "%.f" : "%.17g", u_.number_);
                                                                                             ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In function bool picojson::operator==(const picojson::value&, const picojson::value&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:1123:55: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
   return y.is<type>() && x.get<type>() == y.get<type>()
                                                       ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:1125:3: note: in expansion of macro PICOJSON_CMP
   PICOJSON_CMP(double);
   ^~~~~~~~~~~~
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.h:12,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_command.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: At global scope:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:65:7: warning: virtual void JSONSession::receiveMessage(const string&) can be marked override [-Wsuggest-override]
  void receiveMessage(const std::string& msg) {
       ^~~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In member function virtual void JSONSession::receiveJSON(picojson::value&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:59:44: warning: unused parameter val [-Wunused-parameter]
  virtual void receiveJSON(picojson::value& val) {}
                                            ^~~
==== Auto-Generating Dependencies for /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/visualization_simulator.cc. ====
==== Compiling /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/visualization_simulator.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/webobj/visualizer_sim/visualization_simulator.o. ====
==== Auto-Generating Dependencies for /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc. ====
==== Compiling /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/webobj/visualizer_sim/my_web_server_session.o. ====
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets.h:544:0,
                 from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:6,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-misc.h: In function const lws_dll2_owner* lws_dll2_owner(const lws_dll2*):
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-misc.h:271:40: warning: const lws_dll2_owner* lws_dll2_owner(const lws_dll2*) hides constructor for struct lws_dll2_owner [-Wshadow]
 lws_dll2_owner(const struct lws_dll2 *d) { return d->owner; }
                                        ^
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets.h:563:0,
                 from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:6,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-tokenize.h: At global scope:
/classes/grades/Fall-2019/csci3081/project/external/include/websockets/libwebsockets/lws-tokenize.h:126:37: warning: lws_tokenize_elem lws_tokenize(lws_tokenize*) hides constructor for struct lws_tokenize [-Wshadow]
 lws_tokenize(struct lws_tokenize *ts);
                                     ^
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In member function virtual void WebServerBase::Session::receiveMessage(const string&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:17:50: warning: unused parameter msg [-Wunused-parameter]
   virtual void receiveMessage(const std::string& msg) {}
                                                  ^~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In constructor WebServerWithState<T, STATE>::WebServerWithState(STATE, int):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:47:51: warning: declaration of state shadows a member of WebServerWithState<T, STATE> [-Wshadow]
  WebServerWithState(STATE state, int port = 8081) : WebServerBase(port), state(state) {}
                                                   ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:51:8: note: shadowed declaration is here
  STATE state;
        ^~~~~
In file included from /classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:55:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In member function bool picojson::value::evaluate_as_boolean() const:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:424:26: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
     return u_.number_ != 0;
                          ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In member function std::__cxx11::string picojson::value::to_str() const:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:489:93: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
     SNPRINTF(buf, sizeof(buf), fabs(u_.number_) < (1ULL << 53) && modf(u_.number_, &tmp) == 0 ? "%.f" : "%.17g", u_.number_);
                                                                                             ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h: In function bool picojson::operator==(const picojson::value&, const picojson::value&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:1123:55: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
   return y.is<type>() && x.get<type>() == y.get<type>()
                                                       ^
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/picojson.h:1125:3: note: in expansion of macro PICOJSON_CMP
   PICOJSON_CMP(double);
   ^~~~~~~~~~~~
In file included from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.h:9:0,
                 from /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server_session.cc:6:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: At global scope:
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:65:7: warning: virtual void JSONSession::receiveMessage(const string&) can be marked override [-Wsuggest-override]
  void receiveMessage(const std::string& msg) {
       ^~~~~~~~~~~~~~
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h: In member function virtual void JSONSession::receiveJSON(picojson::value&):
/classes/grades/Fall-2019/csci3081/project/external/include/cppwebserver/WebServer.h:59:44: warning: unused parameter val [-Wunused-parameter]
  virtual void receiveJSON(picojson::value& val) {}
                                            ^~~
==== Auto-Generating Dependencies for /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server.cc. ====
==== Compiling /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/web_code/web/my_web_server.cc into /project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/webobj/visualizer_sim/my_web_server.o. ====
==== Linking vis_sim. ====
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/bus.o: In function `Bus::Move()':
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/src/bus.cc:49: undefined reference to `Passenger::Update()'
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/src/bus.cc:84: undefined reference to `Stop::LoadPassengers(Bus*)'
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/src/bus.cc:114: undefined reference to `Stop::LoadPassengers(Bus*)'
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/random_passenger_generator.o: In function `RandomPassengerGenerator::RandomPassengerGenerator(std::__cxx11::list<double, std::allocator<double> >, std::__cxx11::list<Stop*, std::allocator<Stop*> >)':
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/src/random_passenger_generator.cc:13: undefined reference to `vtable for RandomPassengerGenerator'
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/build/obj/transit_sim/stop.o: In function `Stop::Update()':
/project/grades/Spring-2020/csci3081/ungxx028/grading-environment/grading-scripts/grading/Lab_09_Feedback/repo-kunkl007/project/src/stop.cc:51: undefined reference to `Passenger::Update()'
collect2: error: ld returned 1 exit status
makefile:173: recipe for target 'vis_sim' failed
make: *** [vis_sim] Error 1
</pre>



+ Skip: Change into directory "..".

  This test was not run because of an earlier failing test.

+ Skip: Check that file "build/bin/vis_sim" exists.

  This test was not run because of an earlier failing test.

