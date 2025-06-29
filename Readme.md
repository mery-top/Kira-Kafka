# ⚙️ Kira-Kafka — A Minimal Kafka-Inspired System in C

![Kira-Kafka Architecture](logo.png)


Welcome to **Kira-Kafka**, lightweight, and educational **Kafka-like distributed log system** written in pure C. This project mimics the core architecture of Apache Kafka — covering **topics**, **partitions**, **message brokers**, **disk-backed logs**, **zero-copy reads**, **memory-mapped I/O**, **thread-to-core mapping**, and **log compression**.

> 🔬 Designed for learning, systems programming enthusiasts, and OS-level Kafka internals.

---

## 🌟 Features

| Kafka Feature                    | Kira-Kafka Implementation                                |
|----------------------------------|-----------------------------------------------------------|
| **Topic & Partitioning**         | `Topic` structure with round-robin partitioning          |
| **Disk-Based Log Storage**       | Append-only `.log` files for each partition              |
| **Zero-Copy Reads**              | `sendfile()` syscall for NIC-efficient file transfer     |
| **Memory-Mapped I/O**            | `mmap()` for reading logs as byte arrays                 |
| **Thread-Core Affinity**         | `pthread_setaffinity_np()` for log/consumer separation   |
| **Flush Daemon (Durability)**    | Background `fsync()` log flush thread                    |
| **Load Balancing**               | Per-thread round-robin dispatch to partitions            |
| **Open Source Friendly**         | Community-driven, well-documented, modular structure     |

---

## 🧱 Project Structure

```bash
## 📁 Project Structure

```bash
## 📁 Project Structure

```bash
KIRA-KAFKA/
├── appendLog/
│   ├── include/             # Headers for append-only log
│   ├── src/                 # C source files for disk logging
│   ├── temp/                # Temporary log data (buffered writes)
│   ├── kafka_appendLog      # Binary output
│   └── main.c               # Log writer entry point
│
├── mmap/
│   ├── include/             # Headers for memory-mapped I/O
│   ├── src/                 # mmap-based log readers
│   ├── kafka_mmap           # Compiled output binary
│   ├── main.c               # mmap reader demo
│   └── Makefile             # Build script for mmap module
│
├── partitioning/
│   ├── include/             # Headers for topic/partition logic
│   ├── src/                 # C source files for round-robin dispatch
│   ├── kafka_partitioning   # Compiled output binary
│   ├── main.c               # Partitioning logic demo
│   └── Makefile             # Build script for partitioning module
│
├── threadCore/
│   ├── include/             # Headers for thread-core mapping
│   ├── src/                 # Source files for CPU affinity logic
│   ├── kafka_threadCore     # Compiled binary
│   ├── main.c               # Thread-core mapping demo
│   └── Makefile             # Build script for threadCore module
│
├── zeroCopy/
│   ├── include/             # Headers for zero-copy I/O
│   ├── src/                 # sendfile() based implementation
│   ├── kafka_zeroCopy       # Output binary for zero-copy demo
│   ├── main.c               # Zero-copy file transfer example
│   └── Makefile             # Build script for zeroCopy module
│
├── Makefile                 # Optional root Makefile to build all modules
└── README.md                # Full project documentation



```
## 🚀 Getting Started

### 🔧 Build

```bash
cd (required directory)
make
make run
```

## 🛠️ How It Works (Kafka Internals Recreated)

This section explains how Kira-Kafka recreates key Kafka features at the OS and systems level.

---

### 1. 📦 Topics & Partitions

Each `Topic` contains **N partitions**, and incoming messages are dispatched using a **round-robin strategy**.

> ✅ Mimics Kafka’s producer partitioning logic

---

### 2. 🧾 Append-Only Logs

Messages are stored in an **append-only format** like Kafka's commit log.

```bash
data/orders-0/00000000000000000000.log
data/orders-0/00000000000000000000.index
data/orders-0/00000000000000000000.timeindex
```
---

### 3. 📤 Zero-Copy Reads
To optimize throughput, Kira-Kafka uses Linux’s sendfile() syscall to send data directly from disk to socket, bypassing user space.

```
sendfile(fd_socket, fd_file, &offset, len);
```
🧠 Eliminates user-kernel copy steps → faster log fetches.

---
### 4. 🗃 Memory-Mapped Reads
Instead of traditional read(), Kira-Kafka uses mmap() for efficient, on-demand log access.

```
void* mapped = mmap(NULL, length, PROT_READ, MAP_SHARED, fd, 0);
```
Lazily loads log data into memory, backed by the OS page cache.

---
### 5. 🔄 Log Flusher (Durability)
A dedicated background thread periodically flushes log data from user-space buffers to disk for durability:

```
fflush(f);
fsync(fileno(f));
```
Ensures write-behind logs are safely persisted like Kafka’s flush daemon.

---

### 6. 🧵 Thread-to-Core Mapping
To simulate Kafka's I/O concurrency model, threads are pinned to CPU cores using:

```
pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
```
Mimics Kafka’s use of Java NIO, background I/O, and consumer thread pools with OS-level CPU affinity.

---

## 📚 Discussions & Wiki

### 🤔 Have questions or ideas?
Start a discussion here:
👉 GitHub Discussions

### 📘 Internal Docs
Check the Wiki for:

Architecture diagrams
OS-level optimization explanations
How Kafka uses these techniques at scale


---

## 🤝 Contributing

We ❤️ contributors!

To contribute:

1. **Fork** the repository  
2. **Clone** it locally  
3. **Create a new branch** for your changes  
4. **Implement** your feature or bug fix  
5. **Submit a Pull Request (PR)** with a clear message and screenshot if applicable

```bash
git clone https://github.com/mery-top/kira-kafka.git
cd kira-kafka
git checkout -b feature/my-improvement
```

## 🪪 License

MIT License © Meerthika
