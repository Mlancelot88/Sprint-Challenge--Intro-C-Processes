**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running: When a process is currently running or it is ready to run.
Waiting: The process is waiting to be called or it is awaiting a resource.
Stopped: The process has been stopped through an exit or killed, usually by signal.
Zombie: The process has been stopped but has not been removed from the process table. It still needs to pass on an exit status.

**2. What is a zombie process?**
A zombie process is one that has been stopped but not removed from the process table. It essentially still has data that needs to be passed on.

**3. How does a zombie process get created? How does one get destroyed?**
When the process parent reads all of the exit status of the child the child will fail to remove it from the process table, though it has finished its execution.
To destroy the zombie, the parent zombie must be notified of its presence. Once done, it can execute wait() to clean up all zombie children present.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages can catch bugs long before reaching production as they do not allow bad behavior in the code (ie improper variable use, data types, missing arguments, pointers, etc). The benefit is that it allows developers to be more confident in the code and the end performance as the code compiles to machine code.