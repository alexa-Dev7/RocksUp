FROM ubuntu:latest

# Install required dependencies
RUN apt-get update && apt-get install -y     g++ cmake make libssl-dev libcrypto++-dev build-essential git wget zlib1g-dev libuv1-dev

# Install latest CMake (older versions may cause build failures)
RUN wget https://github.com/Kitware/CMake/releases/download/v3.22.0/cmake-3.22.0-linux-x86_64.sh &&     chmod +x cmake-3.22.0-linux-x86_64.sh &&     ./cmake-3.22.0-linux-x86_64.sh --skip-license --prefix=/usr/local &&     rm cmake-3.22.0-linux-x86_64.sh

# Clone and build uWebSockets
RUN git clone --depth=1 --recurse-submodules https://github.com/uNetworking/uWebSockets.git &&     cd uWebSockets &&     mkdir build && cd build &&     cmake .. -DCMAKE_BUILD_TYPE=Release &&     make -j$(nproc) && make install &&     cd ../.. && rm -rf uWebSockets

# Set working directory
WORKDIR /app

# Copy all files
COPY . .

# Compile the chat application
RUN g++ -std=c++17 -o chat_server src/main.cpp src/storage.cpp src/encryption.cpp src/websocket_server.cpp src/ui.cpp     -luWS -lssl -lcrypto -lpthread -lz -luv

# Expose WebSocket server port
EXPOSE 9001

# Start the server
CMD ["./chat_server"]
