#include "websocket_server.h"
#include <uWS/uWS.h>
#include <iostream>

void startWebSocketServer() {
    uWS::Hub h;

    h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
        std::string msg(message, length);
        std::cout << "Received: " << msg << std::endl;
        ws->send("Echo: " + msg, opCode);
    });

    if (h.listen(9001)) {
        std::cout << "Server running on port 9001" << std::endl;
        h.run();
    } else {
        std::cerr << "Failed to start server!" << std::endl;
    }
}
