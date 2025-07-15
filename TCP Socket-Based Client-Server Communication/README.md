# 🖧 TCP Socket-Based Client-Server Communication (C++ Winsock)

This is a **TCP/IP-based client-server communication system** implemented using **C++ Winsock2 API** on Windows.  
The project demonstrates basic socket programming, message exchange, and I/O multiplexing (`select()`) for efficient event handling.

---

## 📌 Project Description

- The **server** listens on a dedicated port (`9909`), accepts incoming client connections, and processes messages interactively.  
- The **client** connects to the server, sends messages, and receives responses in real-time.  
- Implements **I/O multiplexing** (`select()`) to efficiently monitor multiple socket events (read, write, error).  
- Demonstrates **error handling**, **socket cleanup**, and **resource management** for stable network operations.

---

## ✅ Features

- **TCP Server**
  - Uses `socket()`, `bind()`, `listen()`, and `accept()` for incoming connections.
  - Supports `select()` for detecting read/write/error events.
  - Handles basic message responses.

- **TCP Client**
  - Establishes a connection with the server.
  - Sends and receives messages interactively.

- **Error Handling**
  - Proper socket shutdown and cleanup with `WSACleanup()`.

- **Extensible**
  - Can be extended for multi-client support and advanced protocols.

---

## 🛠 Technologies Used

- **C++**
- **Winsock2 API**
- **TCP/IP Protocol**
- **I/O Multiplexing with `select()`**
- **Windows Network Programming**

---

## 🚀 Build & Run Instructions

### 1️⃣ Prerequisites
- Windows OS  
- MinGW / Visual Studio (or any C++ compiler with Winsock support)

### 2️⃣ Build the Server

```bash
g++ SocketServer.cpp -o server.exe -lws2_32
```

Run the server:
```bash
server.exe
```

### 3️⃣ Build the Client

```bash
g++ SocketClient.cpp -o client.exe -lws2_32
```

Run the client:
```bash
client.exe
```

---

## 🧪 How It Works

1. **Start the Server**
   - It will bind to port `9909` and wait for incoming client connections.

2. **Start the Client**
   - It will connect to the server at `127.0.0.1:9909`.
   - You can type messages that will be sent to the server.

3. **Server-Client Communication**
   - The server responds to messages.
   - Connection closes gracefully on exit.

---

## 🔮 Future Enhancements

- ✅ Multi-client support using `select()` loop  
- ✅ Non-blocking sockets (`ioctlsocket`)  
- ✅ Logging system for request/response history  
- ✅ Cross-platform support with POSIX sockets  

---

## 📄 License
This project is for **learning and personal development**.  

---

## 🙌 Author
## Kamlesh Dugade 
📧 kamleshdpatil777@gmail.com  
