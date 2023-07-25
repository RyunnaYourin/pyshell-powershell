import os
import sys

class powershell:
	def __init__(self):
		self.process_name = None
		self.connection_name = None
		self.output_process = None
		self.netiface_adapter = None
		self.process_name = None
		self.promisc = None # SOON :3

	def windows_sys(self):
		if sys.platform.startswith("win32"):
			print("[+] Inspecting Process On The System")
			output_process = os.popen("Powershell Get-Process").read()
			print(output_process)
			print("[+] Identified Network Interface On The System")
			netiface_adapter = os.popen("Powershell Get-NetAdapter -Name 'Wi-Fi'").read()
			print(netiface_adapter)
		
	def powershell_command(self):
		process_name = input("Enter the name of program: ")
		process_list = os.popen(f"Powershell Get-Process {process_name}").read()
		print(process_list)
		
	def powershell_tcp(self):
		connection_name = input("Enter Connection Name [tcp/udp]: ")
		if connection_name == "tcp":
			net_tcp = os.popen("Powershell Get-NetTCPConnection").read()
			print(net_tcp)

		elif connection_name == "udp":
			net_udp = os.popen("Powershell Get-NetUDPEndpoint").read()
			print(net_udp)
def main():
    ps1 = powershell()
    ps1.powershell_tcp()
    ps1.powershell_command()
    ps1.windows_sys()

if __name__ == '__main__':
    main()