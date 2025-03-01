#include "storage.h"
#include "encryption.h"
#include "websocket_server.h"
#include "ui.h"

int main() {
    initializeStorage(); // Load user and message data
    generateRSAKeys();   // Generate RSA keys if missing
    startWebSocketServer(); // Start real-time chat server

    return 0;
}
