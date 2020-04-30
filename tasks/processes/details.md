# Processes

- PID
- Resident Memory
- %Memory
- User
- %CPU  
- Process

## PID

- Get back the list of all the processes
- Then, get back the process ID for each

## Resident Memory

- How to determine how much memory is a process occupying in the RAM?
- How big is that process? 
- How to convert it into human readable form?
- How to keep up with them in realtime? How to keep notice of any changing differences?

## %Memory

- Should be easy enough - just compare with the total memory available.
- Can't say for sure. Let us just the best in the future

## User

- Basically the owner of the process, the person who executed it
 
## %CPU

- I have no idea
- Obviously there isn't a sharpe number which I can just use. 
- Let us say for example, a file is to be opened. It will definitely be opened, meaning that somehow, one way or another, it will be processed
- It might be that it is slowly processed, but it will be processed
- In that case, percentage starts to become vague - we don't have a discrete value to deal with
- Do I measure the throughput?
- Do I measure the number of threads it is running on itself ay any given moment?
- Do I measure the different sizes of each type of queue? That is to say, a longer queue means the CPU is harboring processes that take too much of the CPU and the IO bursts. 
- Maybe we can find a way to calculate how much of CPU is being utilized, in that case, how do we find out how much of each process takes up the CPU percentage?

## Process

- The file location of the command that was executed

## In general,

- Sort all of them taking the %Memory as the primary key