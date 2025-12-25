# Concurrency Primitives
This repo contains implementations of concurrency primitives for me to learn how they work.

The following are the primitives implemented:
1. Spinlock - uses std::atomic_flag
2. Basic Mutex - uses spinlock
3. Simple Barrier - uses std::atomic<int>
4. Semaphore - mutex
5. Condition Variable - mutex
6. Reader-writer lock - mutex + condition variable
7. Thread-safe Queue - mutex + condition variable
8. Thread pool - thread-safe queue + std::thread
