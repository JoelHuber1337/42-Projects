This is a Programm that sends a String to another Programm. 

The Client Programm uses a PID (Process Identification) to send UNIX Signals (SIGUSR1, SIGUSR2) to the Server Programm.
It does this by splitting Characters up into their bit value and sending those over to the Server, the Server decodes those bits back into full Characters and prints them.
It uses SIGACTION to handle Signals from the <Signal.h> library.
With a double handshake implimented, this Programm runs exceptionally fast.
The Syntax for the Client Programm is ./client Server_PID "Insert_String" and for the Server it's just ./server.

The Server must be started first, upon start it will print it's PID and await further instructions. When a string has been sent, it will print it and await another.
The Client must take the Server's PID, in case of a different one, it will not recieve a handshake from the Server and after 30 seconds it will time-out. Negative PID's are blocked.

//Future Updates.
-Remove the output files from the Github
-Impliment a string sent to the Server before the User String that outlines the Size of the String that will be sent, this will cut down memory allocation to One instead of One per Character
and will increase the Time to print messages greatly.
-Find a better solution to keep static variables in check, to not waste a Global Variable on them.
-Use a new Global Variable to impliment another handshake for added security.
