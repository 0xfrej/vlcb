## TODO
- refactor
  - iface holds the device and list of sockets
  - each socket holds a pointer to enpoint (this should be the hw addr)
    - if no hw addr is set yet, can't communicate
  - each packet gets copied to each endpoint if endpoint can accept it (ideally figure out how to filter based on hw addr too)
  - need some way to setup hw addr, probably using a socket or something that will do the job.
    - it is not possible to do this in the net layer because unlike ethernet/ip there is no fixed hw addr, that can change at any point

- figure how to handle lower level comms (like can control)

- implement duplicate address detection and auto reset (it should also flush any queued socket packets)
- managed buffers on heap / both set size and dynamic
- setup tests using unity
- setup doxygen
- setup github pipeline for testing
- todo allow routing