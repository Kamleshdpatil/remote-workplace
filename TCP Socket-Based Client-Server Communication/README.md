# Socket Chat Application (Windows, Winsock)

This project implements a **simple multi-client chat system** using **Winsock** on Windows.  
It consists of:  

- **SocketServer.cpp** → Server that accepts multiple clients and allows message exchange.  
- **SocketClient.cpp** → Client program that connects to the server and sends/receives messages.  
- **Build.bat** → Batch script to compile both server & client using MinGW/GCC or cl.exe (depending on your setup).  

---

## ✅ Features
- Uses **TCP/IP (SOCK_STREAM)** sockets.
- Server supports **multiple clients** with `select()` for multiplexing.
- Server can send manual responses back to clients interactively.
- Client:
  - Connects to server
  - Receives welcome message (`"Got the connection done Successfully."`)
  - Sends messages and prints replies interactively

---

## ✅ Prerequisites

- **Windows OS**  
- **MinGW** (or Visual Studio `cl.exe`) installed  
- **Winsock2 library** available (default on Windows)  

---

## ✅ How it works

1. **Server:**
   - Initializes Winsock (`WSAStartup`)  
   - Creates a TCP socket & binds it to port `9909`  
   - Listens for new connections  
   - Uses `select()` to handle:
     - New incoming client connections  
     - Messages from existing clients  
   - After receiving a message, the server prompts the operator to type a response and sends it back.

2. **Client:**
   - Initializes Winsock  
   - Connects to `127.0.0.1:9909`  
   - Receives a welcome message `"Got the connection done Successfully."`  
   - Allows the user to type a message → sends it → waits for the server reply → prints it  

---

## ✅ Building the Programs

A **`Build.bat`** script is provided for easy compilation.  

### 1. Using MinGW g++  
If you have MinGW installed:  

```bat
g++ SocketServer.cpp -o Server.exe -lws2_32
g++ SocketClient.cpp -o Client.exe -lws2_32
```

This links against **`ws2_32.lib`** (Winsock2 library).  

### 2. Run Build Script  
Simply double-click or run in cmd:

```bat
Build.bat
```

This will generate:
- **Server.exe**  
- **Client.exe**  

---

## ✅ Running the Application

### 1. Start the server
```cmd
Server.exe
```
You should see:
```
---------!!!  Server Program Started Running  !!!---------
Waiting for client request...
```

### 2. Start a client
```cmd
Client.exe
```
You should see:
```
---------!!!  Client Program Started Running  !!!---------
Connected to Server...

Server response: Got the connection done Successfully.
Send your message to Server:
```

Now you can type a message from the client.  

### 3. Server responds
The server prints:
```
New message received from Client is: Hello
Send your message to Client:
```
The server operator types a reply (e.g. `Hi Client!`), which is sent back.  

The client then prints:
```
Server reply: Hi Client!
```

---

## ✅ Example Interaction

**Client terminal:**
```
Send your message to Server: Hello
Server reply: Hi Client!
*************************************************************
```

**Server terminal:**
```
New message received from Client is: Hello
Send your message to Client: Hi Client!
*************************************************************
Waiting for client request...
```

---

## ✅ Multiple Clients

- You can start **multiple `Client.exe` instances**  
- The server handles them in parallel using `select()`  
- Each connected client gets its own socket  

---

## ✅ Notes & Tips

- Make sure **port 9909** is free (not used by other apps).
- You can change the port in both `SocketServer.cpp` & `SocketClient.cpp` (macro `PORT`).
- If you want **automatic replies**, you can replace the `fgets()` in server with a predefined response.

---

## ✅ Files

- **SocketServer.cpp** – Main server source  
- **SocketClient.cpp** – Client source  
- **Build.bat** – Build script for Windows  

---

## ✅ Future Improvements

- Implement **auto-replies** (no need for manual typing on the server)
- Add **threading** for a more interactive chat (server operator + multiple clients simultaneously)
- Support **broadcast messages** to all clients  

---

Enjoy chatting between server & clients on Windows! 🎉


---

## 🙌 Author  
**Kamlesh Dugade**  

📧 **Email:** [kamleshdpatil777@gmail.com](mailto:kamleshdpatil777@gmail.com)  

💻 Developed with ❤️ using C++ & Winsock  
