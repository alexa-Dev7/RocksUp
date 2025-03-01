# Messenger-Style Chat App (C++ - Render Deployment)

## Features
- ✅ Login/Register System
- ✅ Real-time Messaging (WebSockets)
- ✅ End-to-End Encryption (RSA + AES)
- ✅ JSON-based Storage (No DB Required)
- ✅ Dockerized for Easy Hosting on Render

## Setup Instructions
1. **Clone the Repo**  
   ```sh
   git clone https://github.com/your-repo/chat-app.git && cd chat-app
   ```

2. **Build & Run Locally**  
   ```sh
   docker build -t chat-app .
   docker run -p 9001:9001 chat-app
   ```

3. **Deploy on Render**  
   - Upload the repo & connect Render  
   - Use `Docker` build & auto-deploy

### **Contact for Support**
If you face any issues, please open an issue or reach out.
