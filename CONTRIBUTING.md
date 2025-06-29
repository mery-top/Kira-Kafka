# ⚙️ Kira-Kafka — A Minimal Kafka-Inspired System in C

Welcome to **Kira-Kafka**, a blazing-fast, lightweight, and educational **Kafka-like distributed log system** written in pure C. This project mimics the core architecture of Apache Kafka — covering **topics**, **partitions**, **message brokers**, **disk-backed logs**, **zero-copy reads**, **memory-mapped I/O**, **thread-to-core mapping**, and **log compression**.

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
