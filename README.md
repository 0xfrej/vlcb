## TODO
- refactor
  - each socket holds a pointer to endpoint (this should be the hw addr) - done
    - if no hw addr is set yet, can't communicate
  - each packet gets copied to each endpoint if endpoint can accept it (ideally figure out how to filter based on hw addr too)
  - need some way to setup hw addr, probably using a socket or something that will do the job.
    - it is not possible to do this in the net layer because unlike ethernet/ip there is no fixed hw addr, that can change at any point

- figure how to handle lower level comms (like can control)

- optimise structures and it's layout without relying on packed structures
- setup some static analysis
- implement duplicate address detection and auto reset (it should also flush any queued socket packets)
- managed buffers on heap / both set size and dynamic
- setup tests using unity
- setup doxygen
- setup github pipeline for testing
- todo allow routing

# implementation
- module is a mediator
- ui will send out state change events to keep it agnostic of the mechanism
  - module will request change on the state machine
each service will receive packet
  - can can interrupt and discard the packet