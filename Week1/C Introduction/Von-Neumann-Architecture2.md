### CPU and Cores

![cores.png](..%2F..%2Fimages%2Fcores.png)
- A CPU is responsible for controlling the cores
- A core, or CPU core, is the "brain" of a CPU (central processing unit). 
  - It is an independent processing unit.
  - It receives instructions and performs calculations or operations to satisfy those instructions.
- A CPU can have multiple cores.


---

### Von Neumann Architecture

![memoryUnit.png](..%2F..%2Fimages%2FmemoryUnit.png)
#### SRAM (Static Random Access Memory)

- It is volatile memory
  - Faster than DRAM 
  - Uses flip-flop circuits to store data
  - Used in cache memories


#### DRAM (Dynamic Random Access Memory)

- It is volatile memory
  - slower than SRAM 
  - Uses capacitors to store data 
  - Used in main memories

#### Disk

- Stores data in a non-volatile form, meaning it retains data even when power is lost
- Used for long-term storage of data and programs

---
#### Clock Speed

- It refers to the number of cycles per second that a processor can execute. Measured in gigahertz (GHz).

What are clock cycles?

- In a single clock cycle, a CPU can execute a basic operation, such as fetching an instruction, decoding it, or performing a simple arithmetic operation.

-  A higher clock speed means the processor can execute more instructions per second, leading to increased processing power.
---
#### System Bus

- Buses are a set of parallel wires which connect two or more components inside the CPU.
- System Bus is made up of the data bus, control bus, and address bus. 

---
#### Cache Memory

- Cache temporarily stores frequently used instructions so they can be accessed quicker.
- L1 cache is extremely fast but relatively small
  - usually embedded as the cpu core cache.
- L2 cache is often more capacious than L1.
- L3 cache is much larger and slower memory cell.

### Multicore Processor Architecture

- A multi-core processor contains two or more cores.

![multicore.png](..%2F..%2Fimages%2Fmulticore.png)


- Each core has its own L1 Cache
- In some processors, each core has its own L2 Cache
- All cores share one L3 Cache
- All cores share Main Memory  (DRAM)

---

### Cache Coherence

- Cache coherence refers to a consistency mechanism, which ensures that all processors access the same up-to-date copy of shared data stored in their local caches.

---
#### MSI Protocol

- The MSI protocol is a basic cache-coherence protocol.
- Each cache line can have one of three possible states:
  - M: cache block has been modified, and writes it to DRAM
  - S: other caches may be sharing this block
  - I: cache block is invalid
- Goal: Two cores must never see different values in their local caches for the same shared data.

--- 
Cache Lines
- The chunks of memory handled by the cache are called cache lines.

![cacheLine.png](..%2F..%2Fimages%2FcacheLine.png)