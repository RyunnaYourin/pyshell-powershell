import socket
import sys
import os

import colorama
from colorama import Fore
colorama.init()

CYAN = Fore.CYAN
RESET = Fore.RESET
RED = Fore.RED

""" Credit: HCKaito_iZumiXD (Youtube)

"""

class net_scanner():
	def __init__(self):
		self.host = None
		self.port = None
		self.start_port = None
		self.end_port = None

	def port_scanner(self, host, port, end_port):
		for i in range(port, end_port + 1):
			port = i
			try:
					s = socket.socket()
					s.connect((host, port))
					s.settimeout(1)
					print(CYAN+f"[+] Host Is Up {host}:{port} Port Is Open"+RESET)
			except:
					print(RED+f"[-] Host Is Up {host}:{port} Port Is Closed/Filtered"+RESET)

	def port_scanner_init(self):
		try:
			netscan = net_scanner()
			if len(sys.argv) != 4:
				print(f"Usage: {sys.argv[0]} <host: 127.0.0.1> <start_port: 21> <end_port: 80>")

			netscan.port_scanner(sys.argv[1], int(sys.argv[2]), int(sys.argv[3]))
		except KeyboardInterrupt:
			print(RED+f'[User-Interrupt]'+RESET)
		finally:
			sys.exit()

if __name__ == '__main__':
	netscan = net_scanner()
	netscan.port_scanner_init()
