# UDP-Client-Server 🚀

> A simple UDP client-server project in C++ demonstrating connectionless communication, message exchange, and basic error handling.  
> Repository: https://github.com/SauvirWodehra/UDP-Client-Server

---

## 🧩 Problem Statement
Many networked applications require fast, low-latency message delivery where occasional packet loss or out-of-order delivery is acceptable (for example: live audio/video, simple query/response, telemetry).  
**Build a simple UDP-based client-server program in C++ that demonstrates:**
- Creating and binding UDP sockets.  
- Sending and receiving datagrams.  
- Basic error handling and simple request–response flow (server echoes or acknowledges client messages).  

**Objective:** Educational — to learn connectionless networking primitives and UDP behavior.

---

## 💡 Proposed Solution
Create two programs in C++:

**1. Server**  
- Bind to a UDP port and wait for incoming datagrams.  
- Print received messages and optionally respond (echo or acknowledgement).

**2. Client**  
- Send one or more messages to the server IP:port, optionally wait for a reply, print it, then exit.

**Key design points**
- Use BSD sockets (POSIX) or Winsock2 (Windows).  
- Keep code minimal and well-commented for learning.  
- Provide clear build/run instructions for Linux/macOS and Windows.

---

## 🛠️ Technology Used
- **Language:** C++ (C++11 / C++17 recommended)  
- **Networking API:** BSD sockets (Linux/macOS) / Winsock2 (Windows)  
- **Build Tools:** `g++` / `clang++` / MSVC / MinGW  
- **OS Tested On:** Linux, Windows (examples for both included)

---

## 🧠 Intuition
- **UDP (User Datagram Protocol)** is connectionless: there is *no handshake* to establish a session prior to sending data.  
- Think of UDP like **sending postcards** — you post the message and hope it arrives; there’s no guaranteed delivery or built-in acknowledgement.  
- UDP has lower overhead than TCP, which makes it ideal for low-latency scenarios where a few lost packets are acceptable (e.g., real-time audio/video, gaming updates, DNS queries).

---

## 📡 What is UDP? — Explanation with Real-Life Examples
**UDP** is a transport-layer protocol that transmits independent messages (datagrams) between hosts with minimal protocol overhead. It provides:
- Connectionless messaging (no session/state on the protocol level).  
- No guaranteed delivery, ordering, or built-in retransmission.  
- Low latency and low CPU/packet overhead.

**Real-life analogies & examples**
- **Postcard analogy:** You write and send a postcard (no return receipt). If it arrives, great; if not, you may never know.  
- **Radio broadcast:** A radio station broadcasts to all listeners — there’s no per-listener acknowledgement. UDP multicast/broadcast works similarly.  
- **Live video/voice calls:** Slight frame loss is preferable to retransmitting old frames that would arrive too late. Many real-time systems use UDP with application-layer fixes.  
- **Online multiplayer game state updates:** Frequent small position updates where lost packets are tolerable compared to added latency.

**Key UDP characteristics**
- ✅ Connectionless (no handshake)  
- ✅ Low overhead, low latency  
- ❌ No guaranteed reliability or ordering  
- ✅ Suitable for streaming, games, DNS, telemetry, and simple request/response tasks

---

## 🔧 How to Build & Run

> The exact compile line depends on your implementation. Replace `server.cpp`/`client.cpp` paths as needed.

### Linux / macOS (g++)
```bash
# Compile server
g++ -std=c++17 server.cpp -o server

# Compile client
g++ -std=c++17 client.cpp -o client

# Terminal 1: start server (listens on port 9000 by default)
./server

# Terminal 2: run client (connects to server IP and port)
./client 127.0.0.1 9000 "Hello from client"

# Compile (MinGW)
g++ -std=c++17 server.cpp -o server.exe -lws2_32
g++ -std=c++17 client.cpp -o client.exe -lws2_32

# Start server
.\server.exe

# Run client
.\client.exe 127.0.0.1 9000 "Hello from client"

